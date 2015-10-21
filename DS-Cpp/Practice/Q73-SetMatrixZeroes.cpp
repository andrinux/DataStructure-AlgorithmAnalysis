#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& mat) {
		int M = mat.size(); if (M == 0) return;
		int N = mat[0].size(); if (N == 0) return;
		vector<bool> Cs(N, false);
		vector<bool> Ls(M, false);
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (mat[i][j] == 0){
					Ls[i] = true;
					Cs[j] = true;
				}
			}
		}
		//paint
		for (int i = 0; i < M; i++){
			if (Ls[i])
				for (int j = 0; j < N; j++)
					mat[i][j] = 0;
		}
		for (int j = 0; j < N; j++){
			if (Cs[j])
				for (int i = 0; i < M; i++)
					mat[i][j] = 0;
		}
		return;
	}
};

int main()
{
	vector<vector<int>> mat;
	mat.push_back({ 0, 0, 0, 5 });
	mat.push_back({ 4, 3, 1, 4 });
	mat.push_back({ 0, 1, 1, 4 });
	mat.push_back({ 1, 2, 1, 3 });
	mat.push_back({ 0, 0, 1, 1 });
	Solution so;
	for (auto vec : mat){
		for (auto x : vec)
			cout << x << " ";
		cout << endl;
	}
	cout << "------" << endl;
	so.setZeroes(mat);

	for (auto vec : mat){
		for (auto x : vec)
			cout << x << " ";
		cout << endl;
	}
}