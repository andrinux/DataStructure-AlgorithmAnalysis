/*
* Describe how you could use a single array to implement three stacks.
*/

#include <iostream>
#include <iomanip>

#define M 30
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

//Version-2: The key Problem here is to avoid the case of "usage unbalance"
//In this version, the three stacks are mixed, so we need a struct node to
//store one data, and a 'cur' to indicate where can get the empty space.
//Then the core array is an array of "node".
class node{
public:
	int value;
	int preIdx;
public:
	//Initializer expressions
	node() : value(0), preIdx(-1) {}
	node(int val, int pre) : value(val), preIdx(pre) {}
};

class Stack3_v2{

};

int main() 
{
	Stack3_v1 myStack;
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

