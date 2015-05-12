//Declaration of TextQuery Class
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include <iostream>
#include <fstream>
#include <sstream> //for stringstream
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

class TextQuery{
public:
	//We use size_type here to be generalized
	typedef std::vector<std::string>::size_type line_no;
	/*iterfaces:
	* read files: read the files and build the data structure of each line
	* run_query find the given word and returns sets of lines which is appears
	* text_line returns a line from the input file
	*/
	void read_file(std::ifstream &is) { store_file(is); build_map(); }
	std::set<line_no> run_query(const std::string& str) const;
	const std::string& text_line(line_no line) const;
private:
	//utility functions to read file
	void store_file(std::ifstream& is);
	//associate each word with a set of line numbers
	void build_map();
	//remember the whole input file
	std::vector<std::string> lines_of_text;
	//map word to set of the line on which it occurs
	std::map<std::string, std::set<line_no> > word_map;
	std::string cleanUp(std::string& str);
};
#endif