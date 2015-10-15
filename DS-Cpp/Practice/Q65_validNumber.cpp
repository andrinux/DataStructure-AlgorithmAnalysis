#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//Very ugly, cannot handle many cases at a time.
//Too stupid method.
class Solution_ {
public:
	bool isNumber(string s) {
		int N = s.size();
		bool HaveE = false;
		bool HaveP = false;
		bool HaveNum = false;
		int i = 0;
		//blank
		while (i < N && s[i] == ' ')
			i++;
		if (i == N) return false;
		//symbol
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (i == N) return false;
		//several parts of numbers
		while (i < N){
			while (i < N && isdigit(s[i])){
				i++;
				HaveNum = true; 
				continue;
			}
			//get a pointer.
			if (s[i] == '.'){ //(1)-. (2)_. (3).(4)5.
				if (i == N - 1)
					if (!HaveNum) return false;
				else{
					if (s[i + 1] == ' '){
						i++;
						while (i < N){ if (s[i++] != ' ') return false; }
					}
				}
				if (HaveP) 
					return false;
				else{
					HaveP = true;
					i++;
					continue;
				}
				
			}
			if (s[i] == 'e'){//get a 'e':
				if (HaveE) return false;
				if (HaveNum == false||i == N-1) return false;
				if (i > 1 && !isdigit(s[i - 1])) return false;
				HaveE = true;
				HaveP = true;
				i++;
				continue;
			}
			if (i < N && s[i] != '.' && s[i] != 'e'){
				//skip the blank
				while (s[i-1]!='e' && i < N  && s[i] == ' '){
					i++;
				}
				return i==N;
			}
				
		}
		return true;
	}
};



int main()
{
	Solution so;
	string s;
	//s = "    1234    "; cout << s << tr
	s = " "; cout << setw(5)<< s << "	0-"<< so.isNumber(s) << endl;
	s = "-."; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "12.34"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "-1.43"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "-.5"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "1e20"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "e1"; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "e"; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "1."; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "3.  "; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "."; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = ". "; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "1 4"; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "1 "; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "1e"; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "1e "; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "1  .2 "; cout << setw(5) << s << " 0-" << so.isNumber(s) << endl;
	s = "00"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "0."; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	s = "+004.4E-5"; cout << setw(5) << s << " 1-" << so.isNumber(s) << endl;
	return 0;
}
