/*
* Implement a myQueue class using two stacks.
*/

//Very naive solutions by tranferring data between two stacks.

#include <iostream>
#include <stack>

using namespace std;

class myQueue{
public:
	stack<int> stk1, stk2;
public:
	myQueue();
	void push_back(int data);
	void pop_front();
	int front();
	int back();
};

myQueue::myQueue(){
	//None
}
//stk1 keeps empty and stk2 hold all the elements
void myQueue::push_back(int data){
	//Transfer all the elements from stk2 to stk1
	//while (stk2.size() != 0){
	//	int val = stk2.top();
	//	stk1.push(val);
	//	stk2.pop();
	//}
	stk1.push(data);
	////Transfer to stk2
	//while (stk1.size() != 0){
	//	int val = stk1.top();
	//	stk2.push(val);
	//	stk1.pop();
	//}
}

void myQueue::pop_front(){
	if (stk1.size()==0 && stk2.size() == 0){
		cout << "No element. Cannot pop." << endl;
		return;
	}
	//=============
	while (stk2.size() != 0){
		int val = stk2.top();
		stk1.push(val);
		stk2.pop();
	}
	//Transfer to stk2
	while (stk1.size() != 0){
		int val = stk1.top();
		stk2.push(val);
		stk1.pop();
	}
	//=============
	stk2.pop();
}

int myQueue::front(){
	if (stk1.size() == 0 && stk2.size() == 0){
		cout << "No element. Cannot get front()." << endl;
		return 0;
	}
	return stk2.top();
}

int myQueue::back(){
	if (stk1.size() == 0 && stk2.size() == 0){
		cout << "No element. Cannot get Back()." << endl;
		return 0;
	}
	//Transfer all data from stk2 to stk1
	while (stk2.size() != 0){
		int val = stk2.top();
		stk1.push(val);
		stk2.pop();
	}
	int data = stk1.top();
	while (stk1.size() != 0){
		int val = stk1.top();
		stk2.push(val);
		stk1.pop();
	}
	return data;
}

int main()
{
	myQueue mq;
	for (int i = 0; i != 20; i++){
		mq.push_back(i);
		cout << "Push " << i << ", then front=" << mq.front() << ", back= " << mq.back() << endl;
	}

	for (int i = 0; i != 20; i++){
		mq.pop_front();
		cout << "Pop " << ", then front=" << mq.front() << ", back= " << mq.back() << endl;
	}

	return EXIT_SUCCESS;
}