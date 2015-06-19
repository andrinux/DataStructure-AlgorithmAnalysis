/*
* Implement a myQueue class using two stacks.
*/


//* A better solution to save up moving operations
//* (especially when consecutive push())
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
	void move(stack<int> &src, stack<int> &dst);
};

myQueue::myQueue(){
	//None, no dynamically allocated memory space.
}

//Move stack src to dst
void myQueue::move(stack<int> &src, stack<int> &dst){
	if (src.size() == 0){
		cout << "Cannot Move: Stack is empty." << endl;
		return;
	}
	while (src.size() != 0){
		int val = src.top();
		dst.push(val);
		src.pop();
	}
}


void myQueue::push_back(int data){
	stk1.push(data);
}

//Pop out data, from stk2, if stk2 is empty, move from stk1 first.
void myQueue::pop_front(){
	if (stk1.size() == 0 && stk2.size() == 0){
		cout << "Empty. Cannot PopFront" << endl;
		return;
	}
	if (stk2.size() != 0){
		stk2.pop();
		return;
	}
	if (stk2.size() == 0 && stk1.size() != 0){
		move(stk1, stk2);
		stk2.pop();
		return;
	}
}

//the top of 2nd stack on the right side
int myQueue::front(){
	if (stk1.size() == 0 && stk2.size() == 0){
		cout << "Empty. Cannot PopFront" << endl;
		return 0;
	}
	if (stk2.size() != 0){
		return stk2.top();
	}
	if (stk2.size() == 0){
		move(stk1, stk2);
		return stk2.top();
	}
}

int myQueue::back(){
	if (stk1.size() == 0 && stk2.size() == 0){
		cout << "Empty. Cannot PopFront" << endl;
		return 0;
	}
	if (stk1.size() != 0){
		return stk1.top();
	}
	if (stk1.size() == 0 && stk2.size() != 0){
		move(stk2, stk1);
		return stk1.top();
	}
}

int main()
{
	//myQueue mq;
	//for (int i = 0; i != 20; i++){
	//	mq.push_back(i);
	//	cout << "Push " << i << ", then front=" << mq.front() << ", back= " << mq.back() << endl;
	//}

	//for (int i = 0; i != 20; i++){
	//	mq.pop_front();
	//	cout << "Pop " << ", then front=" << mq.front() << ", back= " << mq.back() << endl;
	//}

	myQueue newQ;
	for (int i = 0; i != 15; i++){
		newQ.push_back(2 * i);
		newQ.push_back(2 * i + 1);
		newQ.pop_front();
		cout << "Front=" << newQ.front() << ", back= " << newQ.back() << endl;
	}
	
	return EXIT_SUCCESS;
}