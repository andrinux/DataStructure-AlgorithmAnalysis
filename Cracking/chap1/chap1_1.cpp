/*
* Implement an algorithm to determine if a string has all unique characters. 
  What if you can not use additional data structures?
*/


#include <iostream>
#include <string>
#include <vector>

//Search need to be efficient, ASCII value
bool checkAllUnique(std::string str){
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

int main()
{
	std::vector<std::string> str;
	std::vector<int> m(256);
	str.push_back("Thequickbrownfoxjumpsoverthelazydog");
	str.push_back("Hapy Life");
	str.push_back("Good Day");
	str.push_back("xyzabc");
	str.push_back("A B C");
	for (auto cur : str)
		std::cout << checkAllUnique(cur) << " : " << cur << std::endl;
	return 1;
}