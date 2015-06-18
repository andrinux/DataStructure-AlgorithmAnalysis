/*
* Describe how you could use a single array to implement three stacks.
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>

#define M 300 //M is the total size of the full three stacks


//Version-1: Using an array, three stacktop pointers. 
//The array is divided evenly into three parts.
class Stack3_v1{
public:
	int totalsize;	//total size of three stacks
	int * content;	//Content Memory Array
	int stop[3];		//cursors of three stacks 
	//Avoid Use same name for variable and member function
public:
	Stack3_v1();
	~Stack3_v1();
	void push(int stackNo, int data);
	int top(int stackNo);
	void pop(int stackNo);
	bool isEmpty(int stackNo);
	void printStack(int stackNo);
};

//Default constructor
Stack3_v1::Stack3_v1(){
	totalsize = M;
	content = new int[totalsize];
	stop[0] = -1;
	stop[1] = -1;
	stop[2] = -1;
}

Stack3_v1::~Stack3_v1(){
	delete[] content;
}

//Push data into stack
void Stack3_v1::push(int No, int data){
	int max = M/3 - 1;
	if (stop[No] == max){
		std::cout << "Cannot Push: Stack " << No << " is FULL." << std::endl;
		return;
	}
	stop[No]++;
	content[No*(M/3) + stop[No]] = data;
}

void Stack3_v1::pop(int No){
	if (stop[No] == -1){
		std::cout << "Cannot Pop: Stack " << No << " is Empty." << std::endl;
		return;
	}
	content[No*(M/3) + stop[No]] = 0;
	stop[No]--;
}

bool Stack3_v1::isEmpty(int No){
	if (stop[No] == -1)
		return true;
	else
		return false;
}

void Stack3_v1::printStack(int No){
	std::cout <<"Stack"<<No<< ": Size is " 
		<< stop[No] + 1 << std::endl;
	if (stop[No] == -1)
		return;
	for (int i = 0; i != stop[No] + 1 ; i++){
		std::cout << std::setw(3) << content[i + No * (M / 3)] << "->";
	}
	std::cout << std::endl;
}

//Get the stack top value of one stack
int Stack3_v1::top(int No){
	return content[M / 3 * No + stop[No]];
}


/*
* This is the second Version of 3 Stack within an array
//Version-2: The key Problem here is to avoid the case of "usage unbalance"
//In this version, the three stacks are mixed, so we need a struct node to
//store one data, and a 'cur' to indicate where can get the empty space.
//Then the core array is an array of "node".


//Two ways to deal with 'cur': (1) increase all the time; (2) Can be decrease, the push would not be O(1)
*/



class node{
public:
	int value;
	int preIdx;
	//bool usable;
public:
	//Initializer expressions
	node() : value(INT_MIN), preIdx(-1) {}
	node(int val, int pre) : value(val), preIdx(pre) {}
};


class Stack3_v2{
public:
	int stop[3];
	node *content;
	int cur;	// denote the current location with space available. This matters.
	int totalsize;

public:
	Stack3_v2();
	~Stack3_v2();
	void push(int stackNo, int data);
	int top(int stackNo);
	void pop(int stackNo);
	bool isEmpty(int stackNo);
	void printStack(int stackNo);
};

Stack3_v2::Stack3_v2(){
	totalsize = M;
	content = new node[totalsize];
	cur = 0;
	stop[0] = stop[1] = stop[2] = -1;
}

Stack3_v2::~Stack3_v2(){
	delete[] content;
}

void Stack3_v2::push(int No, int data){
	if (cur == M){
		std::cout << "Stacks are full. Cannot Push." << std::endl;
		return;
	}
	//cur is the available position, would be retraced back in pop.
	content[cur].value = data;
	content[cur].preIdx = stop[No];
	stop[No] = cur;
	//Need search to next available location
	while (cur<=M && content[cur].value != INT_MIN)
		cur++;
}

int Stack3_v2::top(int No){
	return content[stop[No]].value;
}

//Pop must be O(1)
void Stack3_v2::pop(int No){
	if (stop[No] == -1){
		std::cout << "Stack" << No << " is empty. Cannot Pop." << std::endl;
		return;
	}
	int tmp = content[stop[No]].preIdx;
	content[stop[No]].value = INT_MIN;
	content[stop[No]].preIdx = -1;
	cur = (cur < stop[No]) ? cur : stop[No];//Keep cur at a small value
	stop[No] = tmp;
}

bool Stack3_v2::isEmpty(int stackNo){
	if (stop[stackNo] == -1)
		return true;
	else
		return false;
}

//Can only print in reverse order.
//A small trick here, use an aray to store and then print out
void Stack3_v2::printStack(int stackNo){
	if (stop[stackNo] == -1){
		std::cout << "Stack " << stackNo << " is EMPTY. Print Stop." << std::endl;
		return;
	}
	std::vector<int> data;
	int loc = stop[stackNo];
	while (loc != -1){
		data.push_back(content[loc].value);
		loc = content[loc].preIdx;
	}
	for (int i = data.size()-1; i >=0; i--){
		std::cout << data[i] << "->";
	}
	std::cout << std::endl;
}

//===================testbench===========================
int main() 
{
	Stack3_v2 myStack;
	for (int i = 0; i != 10; i++){
		myStack.push(0, 3*i); 
		myStack.push(1, 3*i+1); 
		myStack.push(2, 3*i+2);
	}

	myStack.printStack(1);
	for (int i = 0; i != 11; i++){
		myStack.pop(0);
		myStack.pop(1);
		myStack.pop(2);
	}
	myStack.printStack(1);

	return EXIT_SUCCESS;
}

