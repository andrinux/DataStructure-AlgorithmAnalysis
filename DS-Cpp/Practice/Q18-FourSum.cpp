#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <set>


using namespace std;

class Solution {
public:
	//(1) This is the AC'ed O(N^3) Method.
	vector<vector<int>> fourSum_1(vector<int>& nums, int target) {
		int M = nums.size();
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		vector<int> one_res;
		if (M < 4)
			return res;
		int a = 0, b = 0, c = 0, d = 0;
		for (a = 0; a < M-3; a++){
			if (a > 0 && nums[a] == nums[a - 1])
				continue;
			for (b = a + 1; b < M; b++){
				/*if (b>1 && nums[b] == nums[b - 1])
					continue;*/
				c = b + 1; d = M - 1;
				while (c < d){
					if (nums[a] + nums[b] + nums[c] + nums[d] == target){
						res.push_back({ nums[a], nums[b], nums[c], nums[d]});
						//Dedup:
						while (c + 1 < M && nums[c] == nums[c + 1])
							c++;
						while (d > 1 && nums[d] == nums[d - 1])
							d--;
						c++;
						d--;
					}
					else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
							c++;
						else
							d--;
				}//loop end for a c-d combination.
				//Skip the duplicated b.
				while ( b>0 && b+1<M && nums[b] == nums[b + 1])
					b++;
			}
		}
		return res;
	}

	//(2) A O(N^2) Method using HashMap: store the sum-locations in pair.
	//It is always very tricky to deal with the duplicated cases.
	vector<vector<int> > fourSum_2(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		int M = nums.size();
		vector<vector<int> > res;
		if (M < 4) return res;
		unordered_map<int, vector<pair<int, int>> > Maps;
		unordered_map<int, vector<pair<int, int>> >::const_iterator itr;
		int a = 0, b = 0, c = 0, d = 0;
		//Construct the Hashmap first, key is the sum and value is the location pairs
		//the second of this Map is a  VECTOR. So the complexity of this step is O(N^2)
		// Dedup matters here.
		for (a = 0; a < M; a++)
			for (b = a + 1; b < M; b++){
				Maps[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
				//Skip the duplicated. No need of this part because key is unique in MAP.
				//while (a+1 < M && nums[a] == nums[a + 1])
				//	a++;
				//while (b+1 < M && nums[b] == nums[b + 1])
				//	b++;
			}
		//cout << Maps.size() << endl;
				
		//Then Let us search c&d: Note the deduplication.
		//AT worst, it is O(N^3).

		for (c = 0; c < M; c++)
			for (d = c + 1; d < M; d++){
				while (d <= c)
					d++;
				int key = target - nums[c] - nums[d];
				itr = Maps.find(key);
				if (itr == Maps.end())
					continue;
				const vector<pair<int, int>> vec = itr->second;
				for (int i = 0; i < vec.size(); i++){
					if (c <= vec[i].second )//Smaller than the second.
						continue;
					else{
						res.push_back({ nums[vec[i].first], nums[vec[i].second], nums[c], nums[d] });
						//while (c + 1 < M && nums[c] == nums[c + 1])
						//	c++;
						//while (d + 1 < M && nums[d] == nums[d + 1])
						//	d++;
					} 
				}				
			}
		//Manually Dedup
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}

	//(3) use multimap to store.
	vector<vector<int> > fourSum_3(vector<int> &nums, int target){
		sort(nums.begin(), nums.end());
		int M = nums.size();
		vector<vector<int> > res;
		if (M < 4) return res;

		unordered_multimap<int, pair<int, int>> Maps;
		int a = 0, b = 0, c = 0, d = 0;
		for (a = 0; a < M; a++)
			for (b = a+1; b < M; b++){
				Maps.insert(make_pair(nums[a]+nums[b], make_pair(a, b)));
				//Skip the duplicated. No need of this part because key is unique in MAP.
				while (a+1 < M && nums[a] == nums[a + 1])
					a++;
				while (b+1 < M && nums[b] == nums[b + 1])
					b++;
			}
		unordered_multimap<int, pair<int, int>>::const_iterator itr;
		for (itr = Maps.begin(); itr != Maps.end(); itr++){
			int key = target - itr->first;
			auto range = Maps.equal_range(key);
			for (auto iter = range.first; iter != range.second; iter++){
				a = itr->second.first;
				b = itr->second.second;
				c = iter->second.first;
				d = iter->second.second;
				if (a < c && a < d && b < c && b < d){
					vector<int> one_res = {nums[a], nums[b], nums[c], nums[d]};
					//sort(one_res.begin(), one_res.end());
					res.push_back(one_res);
				}
			}
		}
		//Manually Dedup
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}



};



int main()
{
	vector<int> nums;
	vector<vector<int> > res;
	Solution so;
	nums = { -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1,
		4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9 };
	//nums = { -1, -1, -1, -1, 0, 1, 2, 3, 2, 2, 2, -1, -4 };
	nums = { 0, 0, 0, 0 };
	nums = { 2, 0, 3, 0, 1, 2, 4 };
	res = so.fourSum_3(nums, 7);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "In total: "<< res.size() << endl;
	return 1;
}
