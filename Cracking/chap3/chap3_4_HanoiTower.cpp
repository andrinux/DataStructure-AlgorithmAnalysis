/*
* use stack to solve Hanoi Problem.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class HanoiTower{
private:
	int plateCnt;
	vector<stack<int> > H;
	
	int rod;
public:
	int step;
	HanoiTower();
	void solve();
	void print();
	void move(vector<stack<int> >& H, int idxF, int idxT, 
				int from, int to, int via);
	void do_solve(vector<stack<int> >& H, int n);
};

HanoiTower::HanoiTower(){
	plateCnt = 5;
	step = 0;
	stack<int> rod1, rod2, rod3;
	for (int i = plateCnt; i > 0; i--){
		rod1.push(i);
	}
	H.push_back(rod1);
	H.push_back(rod2);
	H.push_back(rod3);
}

void HanoiTower::move(vector<stack<int> >& H, int start, int end,
						int from, int to, int via){
	//Move plates by recursion.
	if (end==start){
		int data = H[from].top();
		H[from].pop();
		H[to].push(data);
		step++;
		return;
	}
	move(H, start, end - 1, from, via, to);
	move(H, end, end, from, to, via);
	move(H, start, end - 1, via, to, from);
}
//@para: n is the cnt of plates
void HanoiTower::do_solve(vector<stack<int> >& H, int n){
	if (n == 0)
		return;
	move(H, 0, n - 1, 0, 2, 1);
}

void HanoiTower::solve(){
	do_solve(H, this->plateCnt);
}

void HanoiTower::print(){
	for (int i = 0; i != 3; i++){
		cout << "Stack "<<i<< " : size is " << H[i].size() << endl;
	}
}

int main()
{
	HanoiTower HT;
	HT.print();
	HT.solve();
	HT.print();
	cout << "Total step is: " << HT.step << endl;
	return EXIT_SUCCESS;
}