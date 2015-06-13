//Write code to compress a string
//First version has bug

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string strCompress(string& str){
	string res;
	char curChar=str[0];
	int curLen = 1;
	for (int i = 1; i != str.size(); i++){ //From 1
		if (curChar != str[i]){
			//Save up
			res += curChar;
			res += ('0' + curLen); //important here
			curChar = str[i];
			curLen = 1;
		}
		else{
			curLen++;
		}
	}
	//Need to keep the last one
	res += curChar;
	res += ('0' + curLen); //important here
	if (res.size() > str.size())
		return str;
	else
		return res;
}

int main()
{
	string s1 = "aabcccccaaabbb";
	string s2 = "aaaabbbbccddddsss";
	cout << s1 << "-" << strCompress(s1) << endl;
	cout << s2 << "-" << strCompress(s2) << endl;
}