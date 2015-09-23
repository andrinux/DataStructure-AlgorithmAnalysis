#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
	bool operator()(const int&a, const int&b){
		return a < b;
	}
};

void swap(vector<int> &heap, int cur, int par){
	int tmp = heap[par];
	heap[par] = heap[cur];
	heap[cur] = tmp;
}

//Add one entry.Percolate up.
void my_push_heap(vector<int> &heap, int& entry){
	heap.push_back(entry);
	if (heap.size() == 1)
		return;
	int cur = heap.size()-1;
	int par = (cur % 2 == 0) ? (cur / 2 - 1) : (cur / 2);
	while (cur > 0 && heap[cur] > heap[par]){
		swap(heap, cur, par);
		cur = par;
		par = (cur % 2 == 0) ? (cur / 2 - 1) : (cur / 2);
	}

}

void my_pop_heap(vector<int> &heap){
	if (heap.size() == 0)
		return;
	int tmp = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	int cur = 0;
	int left = 2 * cur + 1, right = 2 * cur + 1;
	int swapIdx = 0;
	while (left < heap.size()){
		if (right < heap.size() && heap[right] < heap[left])
			swapIdx = left;
		else
			swapIdx = right;
		if (heap[cur] < heap[swapIdx])
			//swap
			swap(heap, cur, swapIdx);
		else
			break;
		cur = swapIdx;
		left = 2 * cur + 1, right = 2 * cur + 1;
	}
}

void my_make_heap(vector<int> &heap, vector<int> v){
	for (int i = 0; i < v.size(); i++)
		my_push_heap(heap, v[i]);
	for (int i = 0; i < heap.size(); i++)
		cout << heap[i] << " ";
}

int main(){
	vector<int> v = { 1, 4, 7, 9, 10, -1, 2, 8, 25 };
	vector<int> heap;
	my_make_heap(heap, v);
	priority_queue<int> Q;
	for (int i = 0; i < v.size(); i++)
		Q.push(v[i]);

	cout << "---------------------" << endl;
	for (int i = 0; i < 9; i++){
		my_pop_heap(heap);
		Q.pop();
		cout << "pause" << endl;
	}
	return 1;
}