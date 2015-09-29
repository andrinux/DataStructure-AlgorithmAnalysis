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
