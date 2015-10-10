#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

//Many tricky cases to handle. Must find a cleaner way to clarify.
class Solution_1 {
public:
	vector<Interval> insert(vector<Interval>& Itvs, Interval newIt) {
		int N = Itvs.size();
		vector<Interval> res;
		if (N == 0){
			res.push_back(newIt);
			return res;
		}
		//Already sorted.shoule be done in O(N)
		int i = 0, j = 0;
		while (i < N && newIt.start > Itvs[i].end){
			res.push_back(Itvs[i]);
			i++;
		}
		if (i == N){
			res.push_back(newIt);
			return res;
		}
		if (newIt.end < Itvs[i].start){
			res.push_back(newIt);
			for (; i < N; i++)
				res.push_back(Itvs[i]);
			return res;
		}
		Itvs[i].start = min(Itvs[i].start, newIt.start);
		//for end.
		j = i;
		while (j<N && newIt.end < Itvs[j].start){
			j++;
		}
		Itvs[i].end = max(Itvs[j].end, newIt.end);
		res.push_back(Itvs[i]);
		for (j=j+1; j < N; j++){
			//if ()
			res.push_back(Itvs[j]);
		}
		return res;
	}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& Its, Interval newIt) {
		int N = Its.size();
		if (N == 0) return vector<Interval>({ newIt });
		vector<Interval> res;
		int i = 0;
		bool isInserted = false;
		// Struggling........



		//TO be filled.


		return res;
	}
};

int main()
{
	vector<Interval> intervals;
	intervals = { { 1, 4 }, { 7, 17 } };
	Interval newItv = Interval(4, 7);
	Solution so;
	vector<Interval> res = so.insert(intervals, newItv);
	for (auto seg : res){
		cout << "[" << seg.start << "," << seg.end << "] ";
	}
	return 0;
}
