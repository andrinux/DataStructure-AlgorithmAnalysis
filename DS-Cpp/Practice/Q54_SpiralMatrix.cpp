#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_1 {
public:
	//Recursively Calling.
	void doSpiral(vector<vector<int>>& matrix, int round, vector<int>& res){
		int M = matrix.size();
		int N = matrix[0].size();
		//corner case
		if (M - 2 * round <= 0 || N - 2*round <= 0)
			return;
		//one line
		if (M - 2 * round == 1){
			for (int i = round; i < N - round; i++)
				res.push_back(matrix[round][i]);
			return;
		}

		//one column
		if (N - 2 * round == 1){
			for (int i = round; i < M - round; i++)
				res.push_back(matrix[i][round]);
			return;
		}

		//general case:
		// four edges:
		for (int i = round; i < N - round; i++)
			res.push_back(matrix[round][i]);
		for (int i = round + 1; i < M - round; i++)
			res.push_back(matrix[i][N - round - 1]);
		for (int i = N - round - 2; i >= round; i--)
			res.push_back(matrix[M - round - 1][i]);
		for (int i = M - round - 2; i > round; i--)
			res.push_back(matrix[i][round]);
		//next round
		doSpiral(matrix, round + 1, res);

	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int M = matrix.size();
		//corner case: blank.
		if (M == 0) return vector<int>();
		int N = matrix[0].size();
		vector<int> res;
		doSpiral(matrix, 0, res);
		return res;
	}
};




int main()
{
	vector<vector<int> > matrix;
	matrix.push_back({ 1, 2,3,4});
	matrix.push_back({ 5,6,7,8  });
	matrix.push_back({ 9, 10, 11, 12 });
	matrix.push_back({ 13, 14, 15, 16 });
	matrix.push_back({ 17, 18, 19, 20 });
	matrix.push_back({ 21, 22, 23, 24 });
	Solution so;
	vector<int> res;
	res = so.spiralOrder(matrix);
	for (auto d : res)
		cout << d << " ";
	cout << endl;
	return 0;
}
