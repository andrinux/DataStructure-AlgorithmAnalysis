/*
* Describe how you could use a single array to implement three stacks.
*/

#include <iostream>
#include <iomanip>

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
	void top(int stackNo);
	void pop(int stackNo);
	bool isEmpty(int stackNo);
	void printStack(int stackNo);
};

//Default constructor
Stack3_v1::Stack3_v1(){
	totalsize = 900;
	content = new int[totalsize];
	stop[0] = -1;
	stop[1] = -1;
	stop[2] = -1;
}

Stack3_v1::~Stack3_v1(){
	delete[] content;
}

//Stack1: 000->299
//Stack2: 301->599
//Stack3: 601->899
void Stack3_v1::push(int No, int data){
	int max = 300 * (No + 1) - 1;
	if (stop[No] == max){
		std::cout << "Cannot Push: Stack" << No << "is FULL." << std::endl;
		return;
	}
	stop[No]++;
	content[No*300 + stop[No]] = data;
}

void Stack3_v1::pop(int No){
	if (stop[No] == -1){
		std::cout << "Cannot Pop: Stack" << No << "is Empty." << std::endl;
		return;
	}
	content[No*300 + stop[No]] = 0;
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
		std::cout << std::setw(3) << content[i + No * 300] << "->";
	}
	std::cout << std::endl;
}

//Version-2: The key Problem here is to avoid the case of "usage unbalance"
//When one stack is used up. how to reallocate the space to minimize the collide
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
	return EXIT_SUCCESS;
}

