#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>


using namespace std;

//Not elegant at all.
class Solution_1 {
public:
	void goUp(string& res){
		int N = res.size();
		int i = N - 1;
		if (i==0) return;
		while (res[i] != '/'){
			res.pop_back();
			i--;
		}
	}
	string simplifyPath(string s) {
		int N = s.size();
		if (N == 0 || s[0]!='/') return "";
		int cntABC = 0, cntDot = 0, i = 1, cntOther = 0;
		string res("/");
		int beginIdx = 1;
		while (i < N){
			beginIdx = i; cntABC = 0; cntDot = 0; cntOther = 0;
			while (i < N && s[i] != '/'){
				if (s[i] == '.') 
					cntDot++;
				else if (isalpha(s[i]))
					cntABC++;
				else
					cntOther++;
				i++;
			}
			//process
			if (cntOther > 0)
				return s.substr(0, i);//invalid.
			if (cntABC == 0){
				//if (cntDot == 0); //do nothing.
				//if (cntDot == 1); //do nothing,
				if (cntDot == 2)
					goUp(res);
				if (cntDot > 2){
					return s.substr(0, i);
				}
			}
			if (cntABC > 0){
				res = res + s.substr(beginIdx, i - beginIdx);
				if (cntDot > 0)
					return res;
			}	
			i++;
		}
		return res;
	}
};


//use stack to store it.
class Solution {
public:
	string simplifyPath(string s) {
		int N = s.size();
		if (N == 0 || s[0] != '/') return "";
		int cntABC = 0, cntDot = 0, i = 1, cntOther = 0;
		deque<string> store; 
		int beginIdx = 1;
		while (i < N){
			beginIdx = i; cntABC = 0; cntDot = 0; cntOther = 0;
			while (i < N && s[i] != '/'){
				if (s[i] == '.')
					cntDot++;
				else if (isalpha(s[i]))
					cntABC++;
				else
					cntOther++;
				i++;
			}
			//process
			if (cntDot == 2 && cntABC == 0 && cntOther == 0){
				if(store.size()>0) store.pop_back(); 
				i++;
			}
			else if (cntDot == 1 && cntABC == 0 && cntOther == 0){
				i++;
			}
			else{
				if(i>beginIdx)	
					store.push_back(s.substr(beginIdx, i - beginIdx));
				i++;
			}
		}
		//convert.
		string ret;
		while (store.size() > 0){
			string cur = store.front();
			if (cur.size() > 0)
				ret = ret + '/' + cur;
			store.pop_front();
		}
		return ret.empty() ? "/" : ret;

	}
};


int main()
{
	Solution so;
	string p;
	p = "/a/../b/../../c/"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/home/"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/.."; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/.. /.."; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "//home/...."; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "//home/"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/.../"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/abc/.../"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/abc../"; cout << p << " -> " << so.simplifyPath(p) << endl;
	p = "/.aa/....hidden"; cout << p << " -> " << so.simplifyPath(p) << endl;
	return 0;
}
