#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Method-1: Karatscuba Algorithm.
class Solution_1 {
public:
	//String adding should be reversely, from M to 0. 
	string add(string s1, string s2){
		int M1 = s1.size(), M2 = s2.size();
		string res(max(M1, M2)+1, '0');
		int carry = 0;
		int p1 = M1-1, p2 = M2-1;
		int p = res.size()-1;
		//M1 M2 would be different length
		while (p1 >=0 || p2 >= 0){
			int d1 = (p1 < 0) ? 0 : (s1[p1] - '0');
			int d2 = (p2 < 0) ? 0 : (s2[p2] - '0');
			int d = d1 + d2 + carry;
			if (d >= 10){
				res[p--] = (d - 10) + '0';
				carry = 1;
			}
			else{
				res[p--] = d + '0';
				carry = 0;
			}
			p1--;
			p2--;
		}
		res[p] = carry + '0'; // add the carry bit.
		//Finish the adding, adjust its length and return
		for (p = 0; res[p] == '0'; p++)
			;
		if (p == res.size())
			return "0";
		else
			return res.substr(p);
	}

	string multiply(string s1, string s2) {
		//Corner cases:
		int M = s1.size(), N = s2.size();
		if (M == 0 || N == 0) return "0";
		string res;
		//base case: when the lenth are all 1
		if (M == 1 && N == 1){
			int result = (s1[0] - '0')*(s2[0] - '0');
			return to_string(result);
		}
		//general case
		string a = s1.substr(0, M / 2);
		string b = s1.substr(M / 2);
		string c = s2.substr(0, N / 2);
		string d = s2.substr(N / 2);

		string ac = multiply(a, c); int offset1 = b.size() + d.size();
		string bd = multiply(b, d); int offset2 = 0;
		string ad = multiply(a, d); int offset3 = b.size();
		string bc = multiply(b, c); int offset4 = d.size();
		// could be opyimized here.
		//The offset lenth needs to be carefully calculated.
		res = add((ac + string(offset1, '0')), (bd + string(offset2, '0')));
		res = add(res, (ad + string(offset3, '0')));
		res = add(res, (bc + string(offset4, '0')));
		return res;
	}
};

//Method-2: Direct Way. Brute Force.
class Solution {
public:
	string multiply(string s1, string s2) {
		//corner cases
		if (s1.size() == 0 || s2.size() == 0)
			return "0";
		//genral cases:
		int M1 = s1.size(), M2 = s2.size();
		vector<int> buf(M1 + M2, 0);
		int p1 = M1 - 1, p2 = M2 - 1;
		int p = buf.size() - 1;
		
		int start = 0;
		for (p2 = M2 - 1; p2 >= 0; p2--, start++){
			int d2 = s2[p2] - '0';
			int carry = 0; //clear the related variables each loop.
			p = buf.size() - 1 - start;
			for (p1 = M1- 1; p1 >= 0; p1--){
				int d1 = s1[p1] - '0';
				int d = d1 * d2 + carry + buf[p];
				if (d >= 10){
					carry = d / 10;
					buf[p--] = d % 10;
				}
				else{
					carry = 0;
					buf[p--] = d;
				}
			}
			buf[p] = carry;//save the last one.
		}
		//convert to string, skip all the zeros.
		string res;
		for (p = 0; p < buf.size(); p++)
			res.push_back(buf[p] + '0');
		//skip the foregoing 0's
		for (p = 0; p<buf.size() && buf[p] == 0; p++)
			;
		if (p == buf.size())
			return "0";
		else
			return res.substr(p);
	}
};



int main()
{
	string s1 = "1234";
	string s2 = "9999";
	Solution so;
	cout << so.multiply(s1, s2) << endl;
	return 0;
}
