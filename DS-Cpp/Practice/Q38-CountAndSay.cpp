#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Method-1: Brute Force, do it one by one.
class Solution {
public:
	//0, 1 -> 1
	string countAndSay(int n) {
		string str="1";
		string res;
		for (int i = 1; i < n; i++){
			int idx = 0;
			char cur = NULL ;
			while (idx < str.size()){
				int count = 0;
				cur = str[idx];
				//count
				while (cur == str[idx]){
					idx++;
					count++;
				}
				//say
				char cnt = '0' + count;
				res = res + cnt + cur;
			}
			//next i
			str = res;
			res.clear();

		}
		return str;
			
	}
};


int main()
{
	Solution so;
	cout << so.countAndSay(8) << endl;
	return 0;
}
