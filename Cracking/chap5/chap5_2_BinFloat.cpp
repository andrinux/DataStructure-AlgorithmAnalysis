/*
* Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation.
* If the number can not be represented accurately in binary, print ¡°ERROR¡±.
*/

//Consider to extend to Base-any.
#define MAX 100

#include <iostream>
#include <string>
#include <stdlib.h>
#define M 10

using namespace std;

//convert the base-10 string to binary string
string dec2bin_I(string in){
	string res;
	if (in.size() == 0){
		return res;
	}
	//atoi: in-->intger
	int num = atoi(in.c_str());
	//integer to base 2
	int i = 0;
	do{
		int tmp = num % 2;
		num = num / 2;
		res.push_back(tmp + '0');
	} while (num != 0);
	//reverse the string
	std::reverse(res.begin(), res.end());
	return res;
	
}

string dec2bin_F(string in){
	string res;
	if (in.size() == 0)
		return "";
	in = "0." + in;
	double num = atof(in.c_str());
	int i = 0;
	double tmp = 0;
	do{
		tmp = num * 2;
		res.push_back((int)tmp + '0');
		num = tmp - (int)tmp;
		i++;
	} while (num != 0 && i < M);

	if (i == M)
		return "err";
	else
		return res;
}


//Pay attention to extreme cases
void dec2bin(string& in, string& out){
	int i = 0;
	string s1, s2;
	while (i != in.size()){
		if (in[i] == '.')
			break;
		i++;
	}
	if (i == in.size()){
		s1 = in;
		s2 = "";
	}
	else{
		s1 = in.substr(0, i);
		s2 = in.substr(i + 1);
	}
	string str1 = dec2bin_I(s1);
	string str2 = dec2bin_F(s2);
	if (str2 == "err")
		std::cout << "ERROR" << std::endl;
	else
		std::cout << str1 + "." + str2 << std::endl;
	return;
}

int main()
{
	string in("0.0");
	string out;
	dec2bin(in, out);
	return 0;
}