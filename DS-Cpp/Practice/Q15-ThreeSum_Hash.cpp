// the first version, work but complex code, Too long.
// And the time complexity is O(N^2)
// But the insert operation will have at least O(logN)
// So the final result will T-L-E.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

//Even if you use Set to insert, it is also TLE
//If use HashSet. It will not compile, because STL hashset don't support vector.
using namespace std;


int main()
{
	vector<int> v;
	struct cmp{
		bool operator()(int &a, int& b){
			return a < b;
		}
	};
	v = { -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 19, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, };

	make_heap(v.begin(), v.end(), cmp());
	cout << v.front();
	cout << v.back();
	pop_heap(v.begin(), v.begin() + 1, cmp());
	cout << v.front();
	return 1;
}