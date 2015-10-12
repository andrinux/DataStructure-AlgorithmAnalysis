#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Basic Method: T-L-E
class Solution_1 {
public:
	void inline swap(string& data, int a, int b){
		char tmp = data[a];
		data[a] = data[b];
		data[b] = tmp;
	}
	void reverse(string& data, int start, int end){
		while (start < end){
			swap(data, start, end);
			start++; end--;
		}
	}
	//helper function to get the next permutation.
	void findNext(string& data){
		int N = data.size();
		int b = N - 1, a = b - 1;
		while (a >= 0 && data[a] >= data[b]){
			a--; b--;
		}
		if (a == -1){
			reverse(data, 0, N - 1);
			return;
		}
		// Find c
		int c = N - 1;
		while (data[c] <= data[a])
			c--;
		swap(data, a, c);
		//swap(data[a], data[c]);
		reverse(data, b, N - 1);
		//reverse(data.begin() + b, data.end());
	}

	string getPermutation(int n, int k) {
		string data;
		if (n == 0 || k == 0)
			return data;
		int i = 0;
		int bound = 1;
		for (i = 1; i <= n; i++){
			data.push_back(i + '0');
			bound = bound*i;
		}
		k = k%bound;
		for (i = 0; i < k-1; i++){
			findNext(data);
		}
			
		return data;
	}
};





int main()
{
	Solution so;
	for (int i = 1; i <= 120; i++)
		cout << so.getPermutation(5, i) << endl;
	return 0;
}
