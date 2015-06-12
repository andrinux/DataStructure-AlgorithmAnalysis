//Write a method to replace all spaces in a string with ¡®%20¡¯.

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100

string replaceSpace(string s){
	if (s.size() == 0)
		return s;
	char str[MAX] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i != s.size(); i++){
		if (s[i] != ' ')
			str[j++] = s[i];
		else{
			str[j++] = '%';
			str[j++] = '2';
			str[j++] = '0';
		}
	}
	str[j] = '\0';
	string res(str);
	return res;
}


int main()
{
	string s0;
	string s1 = "HelloWorld";
	string s2 = "World Hello ";
	string s4 = "    abc   ";
	cout << s0 << "---"<< replaceSpace(s0) << endl;
	cout << s1 << "---" << replaceSpace(s1) << endl;
	cout << s2 << "---" << replaceSpace(s2) << endl;
	cout << s4 << "---" << replaceSpace(s4) << endl;
	return 1;
}

