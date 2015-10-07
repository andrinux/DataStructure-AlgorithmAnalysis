#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Method -1: Sort based: From scratch. 
// T L E ! ! ! 
class Solution_1 {
public:
	int searchKey(vector<string>& retKey, string &key){
		int N = retKey.size();
		if (N == 0)
			return -1;
		for (int i = 0; i < N; i++){
			if (key == retKey[i])
				return i;
		}
		return -1;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int N = strs.size();
		if (N == 0) return vector<vector<string>>();
		//general cases.
		vector<vector<string>> ret;
		vector<string> retKey;
		vector<string>  keys=strs;
		vector<string> cur;
		//generate keys
		for (int i = 0; i < N; i++)
			sort(keys[i].begin(), keys[i].end());


		for (int i = 0; i < N; i++){
			string& curStr = strs[i];
			string& key = keys[i];
			int pos = searchKey(retKey, key);
			if (pos == -1){
				retKey.push_back(key);
				cur.push_back(curStr);
				ret.push_back(cur);
				cur.clear();
			}
			else{//found this key at pos
				//strs[i] should be pushed into the N by order. complexity here is O(N)
				vector<string>& curVec = ret[pos];
				vector<string> newVec(curVec.size() + 1);
				int j = 0, k = 0;
				for (j = 0; j < curVec.size(); j++){
					if (ret[pos][j] < curStr)
						newVec[k++]=curVec[j];
					else
						break;
				}
				newVec[k++]=curStr;
				for (; j < curVec.size(); j++)
					newVec[k++]=curVec[j];
				//
				ret[pos] = newVec;
			}
		}

		return ret;
	}
};


//Use hashtable.
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int N = strs.size();
		if (N == 0) return vector<vector<string>>();
		//general cases:
		unordered_map<string, vector<string> > Maps;
		for (int i = 0; i < strs.size(); i++){
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			Maps[cur].push_back(strs[i]);
		}
		//
		vector<vector<string>> res;
		for (auto itr = Maps.begin(); itr != Maps.end(); itr++){
			sort(itr->second.begin(), itr->second.end());
			res.push_back(itr->second);
		}
		return res;
	}
};


int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution so;
	vector<vector<string>> res = so.groupAnagrams(strs);
	for (auto vec : res){
		for (auto str : vec)
			cout << str << " ";
		cout << endl;
	}
	return 0;
}