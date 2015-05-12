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
			word_map[cleanUp(curWord)].insert(lineNo);
		}
	}
}

//run-query for given string and return the set of line numbers
//Nte the case that the word does not exist
std::set<TextQuery::line_no> TextQuery::run_query(const std::string& str) const{
	std::map<std::string, std::set<line_no> >::const_iterator itr;
	itr = word_map.find(str);
	if (itr != word_map.end())
		return itr->second;
	else
		return std::set<TextQuery::line_no>();//Note here contains a parenthese
}

//Why here cannot set return type as reference
//because it is not a good practice, or add 
//std::string TextQuery::text_line(line_no line) const{
const std::string& TextQuery::text_line(line_no line) const{
	if (line >= lines_of_text.size())
		throw std::out_of_range("Exceed number of range");
	else{
		return lines_of_text[line];
	}
}

std::string TextQuery::cleanUp(std::string& word){
	std::string ret;
	for (std::string::const_iterator it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}