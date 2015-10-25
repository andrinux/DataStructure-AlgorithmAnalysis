#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
* (1) Sort, (2) Calculate the count, (3) Hash Value by Prime Number.
*/
class Solution_1 {
public:
	bool isAnagram(string s, string t) {
		int M = s.size(), N = t.size();
		if (M != N) 
			return false;
		int count[256] = { 0 };
		//check s
		for (int i = 0; i < M; i++)
			count[s[i]]++;
		for (int i = 0; i < N; i++){
			if (count[t[i]] > 0)
				count[t[i]]--;
			else
				return false;
		}
		return true;
	}
};

//use prime number based hash value.
//Cannot pass large dataset check.
class Solution {
public:
	bool isAnagram(string s, string t) {
		int M = s.size(), N = t.size();
		if (M != N)
			return false;

		int prime[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
			31, 37, 43, 47, 53, 59, 61, 67, 71, 73,
			79, 83, 89, 97, 101, 103 };
		double hash_1 = 1, hash_2 = 1;
		for (int i = 0; i < M; i++){
			hash_1 = hash_1*prime[s[i] - 'a'];
			hash_2 = hash_2*prime[t[i] - 'a'];
		}
		if (hash_1 == hash_2)
			return true;
		else
			return false;
	}
};


int main()
{
	string s = "abcdefghijk", t = "cx";
	Solution so;
	cout << so.isAnagram(s, t) << endl;
	return 0;
}