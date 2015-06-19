/*
* Implement a myQueue class using two stacks.
*/

#include <iostream>
#include <stack>

class myQueue{
public:
	myQueue();
	void push_back(int data);
	void pop_front();
	void front();
	void back();
};

int main()
{
	myQueue mq;
	for (int i = 0; i != 20; i++)
		mq.push_back(i);
	return EXIT_SUCCESS;
}