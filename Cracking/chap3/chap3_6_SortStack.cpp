/*
* Write a program to sort a stack in ascending order. You should not make any assumptions 
* about how the stack is implemented. The following are the only functions that should be 
* used to write this program: push | pop | peek | isEmpty.
*/
#include <iostream>
#include <stack>

using namespace std;

class stkSort{
public:
	stack<int> data;
	stack<int> help;
public:
	stkSort();
	void sort();
	void selectMax();
};

stkSort::stkSort(){
	data.push(14); data.push(3); data.push(1); data.push(26); data.push(7); data.push(19);
	data.push(0); data.push(24); data.push(19); data.push(11); data.push(65); data.push(7);
}
//Use only one extra stack.

void stkSort::selectMax(){
	int cnt = 0;
	int curMax = 0;
	while (!data.empty()){
		cnt++;
		int val = data.top();
		help.push(val);
		data.pop();
		curMax = (curMax < val) ? val : curMax;
	}
	//Transfer back from help to data.
	//Here is '>', not '>='
	int times = 0;
	while (cnt > 0){
		int value = help.top();
		if (value < curMax){
			data.push(value);
			help.pop();
		}
		else{
			times++;
			help.pop();
		}
		cnt--;
	}
	//Maybe multiple
	for (int i = 0; i != times; i++)
		help.push(curMax);
}
void stkSort::sort()
{
	while (!data.empty()){
		selectMax();
	}
	while (!help.empty()){
		data.push(help.top());
		help.pop();
	}
	cout << "Pause." << endl;
}
//use a priority Queue


int main()
{
	stkSort mStk;
	mStk.sort();
	while (!mStk.data.empty()){
		cout << mStk.data.top() << "->";
		mStk.data.pop();
	}
	cout << endl;
	return EXIT_SUCCESS;
}
