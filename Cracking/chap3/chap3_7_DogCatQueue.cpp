/*
* An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out" basis. 
* People must adopt either the "oldest" ((based on arrival time) of all animals at the shelter, or 
* they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). 
* They cannot select which specific animal they would like.
*/

#include <iostream>
#include <list>

using namespace std;


class AnimalQueue{
private:
	list<int> Dog;
	list<int> Cat;
public:
	static int idx;
	AnimalQueue();
	void enqueue(int type, int index);
	void dequeueAny();
	void dequeueDog();
	void dequeueCat();
};

int AnimalQueue::idx = 0; //initialize 

AnimalQueue::AnimalQueue(){
	//None.
}
//Type: 0-Dog 1-Cat.
void AnimalQueue::enqueue(int type, int ArriveTime){
	if (type == 0)
		Dog.push_back(ArriveTime);
	else
		Cat.push_back(ArriveTime);
}

/*This FUnction can be much cleanner by calling DequeueCat() and DequeueDog.*/
void AnimalQueue::dequeueAny(){
	if (Dog.empty() && Cat.empty()){
		cout << "Empty. Cannot DeQueue." << endl;
		return;
	}
	int type;
	if (!Dog.empty() && Cat.empty())
		type = 0;
	if (!Cat.empty() && Dog.empty())
		type = 1;
	if (!Dog.empty() && !Cat.empty()){
		if (Dog.front() < Cat.front())
			type = 0;
		else
			type = 1;
	}
	if (type == 0){
		cout << "Dequeue Dog:" << Dog.front() << endl;
		Dog.pop_front();
	}
	else{
		cout << "Dequeue Cat:" << Cat.front() << endl;
		Cat.pop_front();
	}

}

void AnimalQueue::dequeueDog(){
	if (Dog.empty()){
		cout << "Empty. Cannot DeQueue Dog." << endl;
		return;
	}
	cout << "Dequeue Dog:" << Dog.front() << endl;
	Dog.pop_front();
}

void AnimalQueue::dequeueCat(){
	if (Cat.empty()){
		cout << "Empty. Cannot DeQueue Cat." << endl;
		return;
	}
	cout << "Dequeue Cat:" << Cat.front() << endl;
	Cat.pop_front();
}

int main()
{
	AnimalQueue AQ;
	AQ.enqueue(1, AQ.idx++); AQ.enqueue(1, AQ.idx++); AQ.enqueue(0, AQ.idx++); AQ.enqueue(1, AQ.idx++);
	AQ.enqueue(0, AQ.idx++); AQ.enqueue(0, AQ.idx++); AQ.enqueue(1, AQ.idx++); AQ.enqueue(0, AQ.idx++);

	AQ.dequeueAny();
	AQ.dequeueDog();
	AQ.dequeueDog();

	return EXIT_SUCCESS;
}