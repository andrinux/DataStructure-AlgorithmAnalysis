#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;
		int i = 0, j = height.size() - 1;
		int left = 0, right = j;
		int small = (height[i] < height[j]) ? i : j;
		int maxArea = (j - i)*min(height[i], height[j]);
		//Move.
		while (i < j){
			if (height[i] < height[j])
				//i is lower than j
				i++;
			else
				j--;
			if (maxArea < (j - i)*min(height[i], height[j])){
				maxArea = (j - i)*min(height[i], height[j]);
				left = i; right = j;
			}
		}
		return maxArea;
	}
};


int main()
{
	Solution so;
	vector<int> height;
	height = { 1, 3, 2 }; cout << so.maxArea(height) << endl;
	return 1;
}