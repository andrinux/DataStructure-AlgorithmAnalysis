//Author" XZ
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <string>

#include "TextQuery.h"

std::ifstream& open_file(std::ifstream &in, const std::string &file);
void printResult(std::set<TextQuery::line_no> locations, std::string &str, TextQuery &Text);

int main(int argc, char* argv[])
{
	std::ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1])){
		std::cerr << "Error when open input file" << std::endl;
		return EXIT_FAILURE;
	}
	TextQuery Text;
	Text.read_file(infile);
	
	/* //debug code segment
	std::istringstream line("hello world");
	std::string str1, str2;
	line >> str1 >> str2;
	std::cout << str1 << ",,,," << str2 << std::endl;*/
	while (true){
		std::cout << "Enter a word to look up, 'q' to quit: " << std::endl;
		std::string str;
		std::cin >> str;
		if (!std::cin || str == "q")
			break;
		std::set<TextQuery::line_no> locations = Text.run_query(str);
		printResult(locations, str, Text);
	}
	return EXIT_SUCCESS;
}

void printResult(std::set<TextQuery::line_no> locations, std::string &str, TextQuery &Text){
	if (locations.size() == 0)
		std::cout << "No resuls found." << std::endl;
	else{
		std::set<TextQuery::line_no>::const_iterator itr;
		for (itr = locations.begin(); itr != locations.end(); itr++)
			std::cout << "\t (line " << (*itr + 1) << " ): " 
						<< Text.text_line(*itr) << std::endl;
	}
}

std::ifstream& open_file(std::ifstream &in, const std::string &file){
	in.close();  // close in case it was already open
	in.clear();  // clear any existing errors

	// if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given

	return in; // condition state is good if open succeeded
}
