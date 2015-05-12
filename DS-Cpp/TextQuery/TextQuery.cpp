//This is the implementation of TextQuery CLass
//Including its member functions

#include "TextQuery.h"

//Store the file lines to a vector
void TextQuery::store_file(std::ifstream& is){
	std::string curLine;
	while (std::getline(is, curLine)){
		lines_of_text.push_back(curLine);
	}
	return;
}

//build the map between the word and its line_no set
void TextQuery::build_map(){
	line_no lineNo = 0;
	for (lineNo = 0; lineNo != lines_of_text.size(); lineNo++){
		//Current content of line
		std::istringstream curLine(lines_of_text[lineNo]);
		//break each line into several words
		std::string curWord;
		while (curLine >> curWord){
			word_map[curWord].insert(lineNo);
		}
	}
}