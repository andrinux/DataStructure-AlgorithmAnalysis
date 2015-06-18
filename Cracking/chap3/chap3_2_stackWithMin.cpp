/*
* How would you design a stack which, in addition to push and pop, 
* also has a function min which returns the minimum element? 
* Push, pop and min should all operate in O(1) time.
*/

//==========The Tricky Point is POP.==============

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

#define MIN INT_MIN

class myStack{
private:
	int capacity;
	int *content;
	std::vector<int> minIdx; //Store the all the minIdx in history
	int stop;
public:
	myStack();
	myStack(int cap);
	~myStack();
	void push(int val);
	void pop();
	int top();
	int getMin();
	void printStack();
};

myStack::myStack(){
	capacity = 50;
	content = new int[capacity];
	memset(content, MIN, capacity*sizeof(int));
	minIdx.push_back(0);
	stop = -1;
}

myStack::myStack(int cap){
	capacity = cap;
	content = new int[capacity];
	memset(content, MIN, capacity);
	minIdx.push_back(0);
	stop = -1;
}

myStack::~myStack(){
	delete[] content;
}

void myStack::push(int val){
	if (stop == capacity - 1){
		std::cout << "Cannot Push. Full" << std::endl;
		return;
	}
	stop++;
	content[stop] = val;
	if (content[minIdx.back()] > val){
		minIdx.push_back(stop);
	}
}

void myStack::pop(){
	if (stop == -1){
		std::cout << "Cannot Pop. Empty." << std::endl;
		return;
	}
	content[stop] = 0;
	if (minIdx.back() == stop){
		minIdx.pop_back();
	}
	stop--;
}

int myStack::top(){
	return content[stop];
}
int myStack::getMin(){
	return content[minIdx.back()];
}

void myStack::printStack(){
	if (stop == -1){
		std::cout << "EMpty Stack. Print Stop" << std::endl;
		return;
	}
	int i = 0;
	while (content[i] != MIN && i<capacity){
		std::cout << content[i++] << "->";
	}
	std::cout << std::endl;
}
/*
* =============TestBench==============
*/

int main()
{
	myStack my;
	for (int i = 0; i != 30; i++)
		my.push((30-i) * 2);
	my.printStack();
	for (int i = 0; i != 10; i++){
		my.pop();
		std::cout << "Top is: " << std::setw(2) << my.top();
		std::cout << " ; Min Now is: " << std::setw(2) << my.getMin() << std::endl;
	}
	return EXIT_SUCCESS;
}