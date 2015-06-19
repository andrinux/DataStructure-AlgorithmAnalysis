/*
* Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely 
* start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. 
* SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. 
* SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same 
* values as it would if there were just a single stack).

* FOLLOW Up:
* Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

//using STL stack or customized stack? STL is fine, the key in this problem is how to use.

#include <iostream>
#include <vector>
#include <stack>

#define MAX 10
#define DBG 0

class mStack{
private:
	std::vector<std::stack<int>* > vStk;
	int cur; //cur Stack number
public:
	mStack();
	~mStack();
	void push(int val);
	void pop();
	int top();
	void popAt(int n);
	void print();
};

mStack::mStack(){
	cur = 0;
	std::stack<int>* newStack = new std::stack < int > ;
	vStk.push_back(newStack);
}

mStack::~mStack(){
	for (int i = 0; i != vStk.size(); i++){
		delete vStk[i];
	}
}

void mStack::push(int val){
	if (vStk[cur]->size() == MAX){
		std::stack<int>* newStack = new std::stack < int >;
		vStk.push_back(newStack);
		cur++;
	}
	vStk[cur]->push(val);
}

void mStack::pop(){
	if (cur == 0 && vStk[cur]->size() == 0){
		std::cout << "All the Stacks are empty. Cannot Pop." << std::endl;
		return;
	}
	vStk[cur]->pop();
	if (vStk[cur]->size() == 0){
		delete vStk[cur];//In case of memory leak.
		vStk.pop_back();
		cur--;
	}
	return;

}

void mStack::popAt(int n){
	if (cur == 0 && vStk[cur]->size() == 0){
		std::cout << "All the Stacks are empty. Cannot Pop." << std::endl;
		return;
	}
	if (cur < n){
		std::cout << "This Stack is empty. Cannot Pop." << std::endl;
		return;
	}
	vStk[n]->pop();
	if (vStk[n]->size() == 0){
		delete vStk[n];//In case of memory leak.
		//Remove the nth element in vStk
		std::vector<std::stack<int>* >::const_iterator itr = vStk.begin();
		int i;
		for (i = 0; i != n; i++){
			itr++;
		}
#if DBG
		std::cout << "i == " << i << ", n == " << n << std::endl;
#endif
		vStk.erase(itr);
		cur--;
	}
	return;

}

int mStack::top(){
	if (cur == 0 && vStk[cur]->size() == 0){
		std::cout << "All the Stacks are empty. No Value" << std::endl;
		return 0;
	}
	return vStk[cur]->top();
}



//Print with Destroying.
void mStack::print(){
	for (int i = 0; i != vStk.size(); i++){
		std::cout << "sub-stack " << i << ":";
		std::vector<int> data;
		//for (int j = 0; j != vStk[i]->size(); j++){
		//	std::cout << vStk[i]->top() << "->";
		//	vStk[i]->pop();
		//}
		std::cout <<"Top is " << vStk[i]->top() << ", size is "<<vStk[i]->size();
		std::cout << std::endl;
	}
	std::cout << "===================" << std::endl;
}

//==================TESTBENCH===================
int main()
{
	mStack mStk;
	for (int i = 0; i != 65; i++)
		mStk.push(i);
	mStk.print();
	for (int i = 0; i != 11; i++)
		mStk.pop();
	mStk.print();
	for (int i = 0; i != 10; i++)
		mStk.popAt(i);
	mStk.print();
	for (int i = 0; i != 9; i++)
		mStk.popAt(2);
	mStk.print();
	return EXIT_SUCCESS;
}