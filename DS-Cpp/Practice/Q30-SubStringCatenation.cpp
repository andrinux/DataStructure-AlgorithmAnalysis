#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	* The Brute Force: Very Slow. 800ms.
	* Code is tedious and long.
	*/
	vector<int> findSubstring_Old(string s, vector<string>& words) {
		vector<int> result;
		//corner cases
		if (s.size() == 0 || words.size() == 0)
			return result;
		int N = words[0].size();
		int limit = words.size() * N;
		if (s.size() < limit)
			return result;
		// construct the map
		unordered_map<string, int> Maps, curMap;
		int i = 0, j = 0;
		for (i = 0; i < words.size(); i++)
			Maps[words[i]]++;
		//Search one by one
		i = 0;
		while (i <= s.size() - limit){
			j = i;
			curMap = Maps;
			while ((j + N) <= s.size() && (j - i) < limit){
				string key = s.substr(j, N);
				if (curMap.count(key) == 0){
					i++;
					break;
				}
				else if (curMap[key] > 0){
					curMap[key]--;
					j = j + N;
					if (j - i == limit){
						result.push_back(i);
						i++;
						break;
					}
				}
				else{
					//if this item is used up. next loop should start from the same position?
					i++;
					break;
				}
			}
		}

		return result;
	}
	/* A cleaner Method use help function. 
	* A little bit quicker 724ms.
	*/
	//Check if the current sub string is concatenation or not
	bool checkSubString(int start, string &s, unordered_map<string, int>& Map, int wordCnt, int wordLen){
		unordered_map<string, int> curMap;
		int i = 0;
		for (i = 0; i < wordCnt; i++){
			//no need to check out-of-range. becuse it is checked in parent function.
			string key = s.substr(start + i*wordLen, wordLen);
			if (Map.count(key) == 0)
				return false;
			else{
				curMap[key]++;
				if (curMap[key] > Map[key]) //这里有抽屉原则的思想。
					return false;
			}
		}
		return true;
	}
	vector<int> findSubstring_Clean(string s, vector<string>& words){
		vector<int> res;
		int M = s.size(), N = words.size();
		//check the corner cases.
		if (M == 0 || N == 0) 
			return res;
		int wordCnt = words.size();
		int wordLen = words[0].size();
		if (M < wordLen*N)
			return res;
		//build the map.
		int i = 0, j = 0;
		unordered_map<string, int> Map;
		for (int i = 0; i < N; i++)
			Map[words[i]]++;
		//check them one by one
		while (i <= M - wordLen*N){
			if (checkSubString(i, s, Map, N, wordLen)){
				res.push_back(i);
				i++;
			}
			else
				i++;
		}
		return res;
	}



};


int main()
{
	vector<int> result;
	Solution so;
	string s("barfoothefoobarman");
	vector<string> words = {"bar","foo"};
	result = so.findSubstring(s, words);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " - ";


	return 1;
}
