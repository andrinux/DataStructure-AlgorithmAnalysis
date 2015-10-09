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

class Solution {
public:
	static bool compare( const Interval& A, const Interval& B) {
		if (A.start != B.start)
			return A.start < B.start;
		else
			return A.end < B.end;
	}

	vector<Interval> merge(vector<Interval>& it) {
		vector<Interval> res;
		int N = it.size(); if (N == 0) return res;
		if (N == 1) return it;
		sort(it.begin(), it.end(),compare);
		//scan one by one.
		int cur = 0;
		for (int i = 1; i < N; i++){
			if (it[cur].start == it[i].start){
				it[cur].end = max(it[cur].end, it[i].end);
				continue;
			}
			if (it[cur].start < it[i].start && it[i].start <= it[cur].end){
				it[cur].end = max(it[cur].end, it[i].end);
				continue;
			}
			if (it[cur].end < it[i].start){
				cur++;
				it[cur].start = it[i].start;
				it[cur].end = it[i].end;
				continue;
			}
		}
		it.resize(cur + 1);
		return it;
	}
};


int main()
{
	vector<Interval> intervals;
	intervals = { { 1, 3 }, { 8, 10 }, { 8, 12 }, { 15, 20 }, { 17, 19 }, { 2, 6 }, { 70, 80 }, { 72, 74 }, {80, 81} };
	
	Solution so;
	vector<Interval> res = so.merge(intervals);
	for (auto seg : res){
		cout << "[" << seg.start << "," << seg.end << "] ";
	}

	return 0;

}
