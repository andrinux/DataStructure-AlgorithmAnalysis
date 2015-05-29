/*
* Implement an algorithm to determine if a string has all unique characters. 
  What if you can not use additional data structures?
*/


#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

//Search need to be efficient, ASCII value
bool checkAllUnique_1(std::string str){
	int count[256] = {0};
	for (int i = 0; i != str.size(); i++){
		int cur = str[i];
		if (count[cur] == 0)
			count[cur] = 1;
		else
			return false;
	}
	return true;
}

bool checkAllUnique_2(std::string str){
	uint32_t count[8] = { 0 };
	for (int i = 0; i != str.size(); i++){
		int cur = str[i];
		int Byte = cur / 32; 
		int Bit = 7 - cur % 32;
		uint32_t mask = 0x01 << Bit;
		if ((count[Byte] & mask) == 0)
			count[Byte] |= count[Byte] | mask;
		else
			return false;
	}

	return true;
}

int main()
{
	std::vector<std::string> str;
	str.push_back("Thequickbrownfoxjumpsoverthelazydog");
	str.push_back("Hapy Life");
	str.push_back("Good Day");
	str.push_back("xyzabc");
	str.push_back("A B C");
	for (auto cur : str)
		std::cout << checkAllUnique_1(cur) << "-"<<checkAllUnique_2(cur) << " : " << cur << std::endl;
	return 1;
}