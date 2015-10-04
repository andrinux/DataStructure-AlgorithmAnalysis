#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

//Direct Way: use Two pointers to find a local max value. 
// trapped in Local Optimal.
// Worst Case will be O(n*k)
class Solution_1 {
public:
	int trap(vector<int>& H) {
		int M = H.size();
		if (M <= 1) return 0;
		int res = 0, finalRes = 0;
		int maxH = 0;
		do{
			res = 0;
			int p1 = 0, p2 = 0;
			//skip the foregoing 0's
			while (H[p1] == 0 && p1 < M)
				p1++;
			p2 = p1 + 1;
			while (p2 < M){
				while (p2 + 1 < M && !(H[p2 - 1] < H[p2] && H[p2] >= H[p2 + 1])){
					p2++;
				}
				int local = min(H[p1], H[p2]);
				for (int i = p1 + 1; i < p2; i++){
					if (local > H[i]){
						res += (local - H[i]);
						H[i] = local;
					}
				}
				p1 = p2;
				p2 = p2 + 1;
			}
			finalRes += res;
		} while (res != 0);
		

		return finalRes;
	}
};


//Very clean and simple method: 
//Ref: http://fisherlei.blogspot.com/2013/01/leetcode-trapping-rain-water.html
//Search twice. Complexity is O(2n), Space complexity is O(2n)

class Solution {
public:
	int trap(vector<int>& height) {
		int water = 0;
		int M = height.size();
		if (M <= 1) return water;
		vector<int> LeftHeight(M, 0);
		vector<int> RightHeight(M, 0);
		int maxH = 0;
		for (int i = 0; i < M; i++){
			LeftHeight[i] = max(maxH, height[i]);
			maxH = max(maxH, LeftHeight[i]);
		}
		maxH = 0;
		for (int i = M - 1; i >= 0; i--){
			RightHeight[i] = max(maxH, height[i]);
			maxH = max(maxH, RightHeight[i]);
		}
		//Calculate
		for (int i = 0; i < M; i++){
			water += (min(LeftHeight[i], RightHeight[i]) - height[i]);
		}
		return water;
	}
};

// A method to search only once: Only one direction, Fill the previous ones if needed.
// https://leetcode.com/discuss/11272/my-solution-inspired-by-2-sum
// RainTotal - AreaTotal

int main()
{
	vector<int> heights = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
	Solution so;
	cout << so.trap(heights) << endl;
	return 0;
}