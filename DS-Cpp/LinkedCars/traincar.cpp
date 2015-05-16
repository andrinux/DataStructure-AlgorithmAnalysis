// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>

#include "traincar.h"
#include "traincar_prototypes.h"
#include <vector>
#include <algorithm>

#define _DEBUG 0
// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "traincar_prototypes.h" FILE.
//
//Impelement the pushback function, "simple" is the linked list head.
//Note: No need to add "static" here 
//Pay attention to the passing of reference, See StackOverflow
void PushBack(TrainCar*& head, TrainCar* newCar){
	if (head == NULL){
		//still a empty list
		head = newCar;
	}
	else{
		//need to loop to the end of list because there is no "tail" in the class
		TrainCar* itr = head;
		while (itr->next != NULL){
			itr = itr->next;
		}
		newCar->prev = itr;
		itr->next = newCar;
	}
	return;
}

//Destroy thr list from beginning
void DeleteAllCars(TrainCar* simple){
	TrainCar *tmp;
	while (simple != NULL){
		tmp = simple->next;
		delete simple;
		simple = tmp;
	}
	return;
}


//Optimization problem
std::vector<TrainCar*> ShipFreight(TrainCar*& all_engines, TrainCar*& all_freight, int min_speed, int max_cars_per_train){
	//all_engines in the engines-list avaiable  all_freights are all the freights cars  
	std::vector<TrainCar*> trains; //store the final result
	sortFreights(all_freight);
	//Use Greedy Algorithm to solve
	//Add each freight one by one, check its feasibility
	TrainCar* curTrain = NULL;
	std::vector<TrainCar*>::iterator itr = trains.begin();
	TrainCar * curFreight;
	TrainCar * unFitFreights=NULL;
	while (all_freight != NULL){
		curFreight = pop_front(all_freight);
		//int test = curFreight->getWeight();
		if (trains.empty()){
			//At begining, trains is empty, so need to add One Train into the vector
			addToTrain(curTrain, pop_front(all_engines));
			addToTrain(curTrain, curFreight);
			trains.push_back(curTrain);
			continue;
		}
		//Loop the whole train list to find a place to
		for (itr = trains.begin(); itr != trains.end(); itr++){
			curTrain = *itr;
			if (true==checkOK(curTrain, curFreight, min_speed, max_cars_per_train)){
				//Add current Freight into the current Train
				addToTrain(curTrain, curFreight);
				break;
			}
		}
		if (itr == trains.end()){
			//No existing Train can hold curFreight, so assign a new Train
			if (all_engines != NULL){
				TrainCar* newTrain = NULL;
				addToTrain(newTrain, pop_front(all_engines));
				addToTrain(newTrain, curFreight);
				trains.push_back(newTrain);
			}
			else{
				//add the freight to the unfit Freight chains, 
				//actually, this is the largest one, All the following will not be fitted, so OK to quit.
			#if _DEBUG
				for (itr = trains.begin(); itr != trains.end(); itr++){
					curTrain = *itr;
					if (false==checkOK(curTrain, curFreight, min_speed, max_cars_per_train)){
						//Add current Freight into the current Train
						std::cout << "Check Fail:" << curFreight->getWeight() << ", " << getTotalWeight(curTrain) << ", "<<
							getSpeed(curTrain, curFreight, min_speed) << " < " << min_speed<< std::endl;
					}
				}
			#endif
				addToTrain(unFitFreights, curFreight);
				/*
				//Need to store back curFreight to all Freight
				all_freight->prev = curFreight;
				curFreight->next = all_freight;
				all_freight = curFreight;
				break;*/

			}
		}
	}
	all_freight = unFitFreights;
	MergeTrains(trains, max_cars_per_train);
	return trains;
}
//There are some short tains, merger them to get a smaller train count
void MergeTrains(std::vector<TrainCar*>& trains, int max_cars_per_train){
	std::sort(trains.begin(), trains.end(), compTrain);
	std::vector<TrainCar*>::iterator itr1, itr2;
	itr1 = trains.begin();
	while (itr1 != trains.end()){
		itr2 = itr1 + 1;
		if (itr2 != trains.end() && (getCarNum(*itr1) + getCarNum(*itr2)) <= max_cars_per_train){
			linkCars(*itr1, *itr2);
			trains.erase(itr2);
		}
		else
			itr1++;
	}
	return;
}

void linkCars(TrainCar*& t1, TrainCar*& t2){
	TrainCar* ptr = t1;
	while (ptr->next != NULL)
		ptr = ptr->next;
	//ptr point to the last position
	ptr->next = t2;
	t2->prev = ptr;
}
bool compTrain(TrainCar* t1, TrainCar* t2){
	int len1 = getCarNum(t1);
	int len2 = getCarNum(t2);
	return (len1 > len2) ? true : false;
}
//Add a new car(Freight/Engine) to the train,
//because the newCar's next is set already, so we cannot use PushBack directly
void addToTrain(TrainCar*& head, TrainCar* newCar){
	newCar->next = NULL;//here is different
	if (head == NULL){
		//still a empty list
		head = newCar;
	}
	else{
		//need to loop to the end of list because there is no "tail" in the class
		TrainCar* itr = head;
		while (itr->next != NULL){
			itr = itr->next;
		}
		//Travel to the train end, itr is the end now
		newCar->prev = itr;
		itr->next = newCar;
	}

	return;
}

int getCount(TrainCar* head){
	int num = 0;
	TrainCar* itr = head;
	while (itr != NULL){
		num += 1;
		itr = itr->next;
	}
	return num;
}
bool checkOK(TrainCar* curTrain, TrainCar* curFreight, int min_speed, int max_cars_per_train){
	int curNum = getCarNum(curTrain);
	if (curNum == max_cars_per_train)
		return false;
	float Speed = getSpeed(curTrain, curFreight, min_speed);
	if (Speed < float(min_speed))
		return false;
	else
		return true;
}

//get the speed with a new car
float getSpeed(TrainCar* curTrain, TrainCar* curFreight, int min_speed){
	int curWeight = getTotalWeight(curTrain);
	int total = curWeight + curFreight->getWeight();
	float speed = 30 * 550 * 36 * 50 / (20  * 52.80 * total);
	return speed;
}

//Get the total Weight without a new Car
int getTotalWeight(TrainCar* curTrain){
	int num = 0;
	TrainCar* itr = curTrain;
	while (itr != NULL){
		num += itr->getWeight();
		itr = itr->next;
	}
	return num;
}
TrainCar* pop_front(TrainCar*& all_engines){
	TrainCar *tmp;
	tmp = all_engines;
	all_engines = all_engines->next;
	if (all_engines != NULL)
		all_engines->prev = NULL;
	return tmp;
}

int getCarNum(TrainCar* head){
	TrainCar * itr = head;
	int num = 0;
	while (itr != NULL){
		num++;
		itr = itr->next;
	}
	return num;
}
int engineLeft(TrainCar * all_engines){
	TrainCar * itr = all_engines;
	int num = 0;
	while (itr != NULL){
		num++;
		itr = itr->next;
	}
	return num;
}

int freightLeft(TrainCar * all_freight){
	TrainCar * itr = all_freight;
	int num = 0;
	while (itr != NULL){
		num++;
		itr = itr->next;
	}
	return num;
}
//Sort freights
void sortFreights_v(TrainCar*& all_freight){
	//Just Use  sorting first
	int count = 100;
	TrainCar* tmp = all_freight;
	//bool not_last_pair = 0;
	while (count != 0) {
		count = 0;
		while (tmp->next != NULL) {
			if (tmp->getWeight() < tmp->next->getWeight()) {
				swap(tmp);
				count++;
			}
			else
				tmp = tmp->next;
		}
		while (tmp->prev != NULL) {
			tmp = tmp->prev;
		}
	}
	all_freight = tmp;
	return;
}


//Try to use while to do sorting for Linked List
void sortFreights(TrainCar*& all_freight){
	//Just Use  sorting first
	//debug info
#if _DEBUG
	TrainCar *itr = all_freight;
	while (itr != NULL){
	std::cout << itr->getWeight() << ", ";
	itr = itr->next;
	}
	std::cout << std::endl;
#endif
	//Start 
	int swapped = 1;
	while (swapped){
		swapped = 0;
		TrainCar *i = all_freight;
		while (i->next != NULL){
			if (i->getWeight() < i->next->getWeight()){
				swap(i);
				swapped = 1;
			}
			else
				i = i->next;
		}
		while (i->prev != NULL)
			i = i->prev;
		all_freight = i;
	}
	//end
#if _DEBUG
	itr = all_freight;
	while (itr != NULL){
	std::cout << itr->getWeight() << ", ";
	itr = itr->next;
	}
	std::cout << std::endl;
#endif
	//After sorting, need to find out the new head
	return;
}

//Swap Node a and the node following a
//Maybe too many steps, but very easy to understand
void swap(TrainCar*& a){
	TrainCar *N1;
	TrainCar *N2;
	TrainCar *b = a->next;
	//Special case: a is head and b is tail
	N1 = a->prev; N2 = b->next;
	if (N1 == NULL){
		//a is the head of list
		b->next = a;
		a->next = N2;
		N2->prev = a;
		a->prev = b;
		b->prev = N1;
	}
	else if (N2 == NULL){
		N1->next = b;
		b->next = a;
		a->prev = b;
		b->prev = N1;
		a->next = NULL;
	}
	else{
		//Normal case
		N1->next = b;//onlu difference
		b->next = a;
		a->next = N2;
		N2->prev = a;
		a->prev = b;
		b->prev = N1;
	}
	return;
}

void TotalWeightAndCountCars(TrainCar* train, int &total_weight, int &num_engines,
	int &num_freight_cars, int &num_passenger_cars, int &num_dining_cars, int &num_sleeping_cars){
	TrainCar *itr = train;
	while (itr != NULL){
		total_weight += itr->getWeight();
		if (itr->isDiningCar())
			num_dining_cars++;
		if (itr->isEngine())
			num_engines++;
		if (itr->isFreightCar())
			num_freight_cars++;
		if (itr->isPassengerCar())
			num_passenger_cars++;
		if (itr->isSleepingCar())
			num_sleeping_cars++;
		itr = itr->next;
	}
	return;
}

float CalculateSpeed(TrainCar* train){
	TrainCar *itr = train;
	int num_engines = 0, total = 0;
	while (itr != NULL){
		total += itr->getWeight();
		if (itr->isEngine())
			num_engines++;
		itr = itr->next;
	}
	float speed = num_engines * 30 * 550 * 36 / (20 * 0.02 * 52.80 * total);
	return speed;
}

//Core function to seperate
void Separate(TrainCar*& train1, TrainCar*& train2, TrainCar*& train3){
	int total = getTotalWeight(train1) - 2 * 150; //Total weights other than engine
	int total_1 = 0;
	int loc1 = -1, loc2 = -1;
	int loc = 0, cutPos = 0;
	train2 = train1;
	TrainCar *itr = train1;
	//Search for twice, one for turning point location
	//Another for enginer location
	while (total_1 < total / 2){
		if (!itr->isEngine()){
			total_1 += itr->getWeight();
		}
		loc++;
		itr = itr->next;
	}
	//cutPos is the location of 50% weights(without engine)
	cutPos = loc - 1; //[Need]: further discussion here.
	//Search another time, reset itr and loc
	itr = train1; loc = 0;
	while (itr != NULL){
		if (itr->isEngine()){
			if (loc1 == -1)
				loc1 = loc;
			else
				loc2 = loc;
		}
		itr = itr->next;
		loc++;
	}
	//Move the location of engine according to the relation between 
	//curPos, loc1, loc2
	if (loc1 < cutPos && cutPos < loc2){
		//seems good, nothing need to be moved, just cut into two trains at cutPos
		//Move the itr to the location just before cutPos
		itr = train1;
		int tmp = 0;
		while (tmp != cutPos){
			itr = itr->next;
			tmp++;
		}
		itr->prev->next = NULL;
		itr->prev = NULL;
		train3 = itr;
	}
	if (loc1 < loc2 && loc2 < cutPos){
		//need to move loc2 to right after cutPos
		TrainCar* itr1, *itr2;
		itr = train1; itr1 = train1; itr2 = train1;
		int tmp = 0;
		while (itr != NULL){
			if (tmp == loc2){
				itr1 = itr;
			}
			if (tmp == cutPos){
				itr2 = itr;
			}
			tmp++;
			itr = itr->next;
		}
		moveBackEngine(itr1, itr2);
		//Divide into two trains at cutPos
		itr = itr2;
		itr->prev->next = NULL;
		itr->prev = NULL;
		train3 = itr;
	}
	//Note the order maybe different from las case
	if (cutPos < loc1 && loc1 < loc2){
		//Need to move loc1 to right before cutPos
		TrainCar* itr1, *itr2;
		itr = train1; itr1 = train1; itr2 = train1;
		int tmp = 0;
		while (itr != NULL){
			if (tmp == cutPos)
				itr1 = itr;
			if (tmp == loc1)
				itr2 = itr;
			itr = itr->next;
			tmp++;
		}
		moveFrontEngine(itr1, itr2);
		itr = itr1;
		itr->prev->next = NULL;
		itr->prev = NULL;
		train3 = itr;
	}
	train1 = NULL;
	return;
}

//Move the node@itr1 to the location after @itr2
//Move is divided into two steps, erase and insert
void moveBackEngine(TrainCar*& itr1, TrainCar*& itr2){
	//Erase and then Insert
	TrainCar * N1 = itr1->prev;
	TrainCar * N2 = itr1->next;
	N1->next = N2;
	N2->prev = N1;
	//insert
	TrainCar* N3 = itr2->next;
	itr2->next = itr1;
	N3->prev = itr1;
	itr1->prev = itr2;
	itr1->next = N3;
	return;
}
//Case3. Move itr2 front before itr1
void moveFrontEngine(TrainCar*& itr1, TrainCar*& itr2){
	TrainCar * N1 = itr1->prev;
	TrainCar * N3 = itr2->prev;
	TrainCar * N4 = itr2->next;
	//erase
	N3->next = N4;
	N4->prev = N3;
	//Insert
	N1->next = itr2;
	itr2->next = itr1;
	itr1->prev = itr2;
	itr2->prev = N1;
	return;
}

//get the count of engine
int engineCnt(TrainCar* t){
	int num = 0;
	while (t != NULL){
		if (t->isEngine())
			num++;
		t = t->next;
	}
	return num;
}


float  AverageDistanceToDiningCar(TrainCar *head){
	float distance_front = 0;
	float distance_back = 0;
	float distance = 0;
	float num_passenger_cars = 0;
	//float num_dining_cars = 0;
	TrainCar* tmp = head;
	TrainCar* passenger_car;
	//if the first train car is passanger car
	if (tmp->isPassengerCar()) {
		tmp = head->next;
		while (tmp != NULL) {
			if (tmp->isEngine()) {
				distance_back = 0;
				return -1;
				break;
			}
			else if (!(tmp->isDiningCar())) {
				distance_back++;
				tmp = tmp->next;
			}
			else if (tmp->isDiningCar()) {
				distance_back++;
				distance += distance_back;
				break;
			}
		}
		tmp = head->next;
	}
	while (tmp != NULL) {
		if (tmp->isPassengerCar()) {
			passenger_car = tmp;
			num_passenger_cars++;
			//look forward for dining car
			tmp = passenger_car->prev;
			while (tmp != NULL) {
				if (tmp->isEngine()) {
					distance_front = 0;
					break;
				}
				else if (!(tmp->isDiningCar())) {
					distance_front++;
					tmp = tmp->prev;
				}
				else if (tmp->isDiningCar()) {
					distance_front++;
					break;
				}
			}
			//look afterward for dining car
			tmp = passenger_car->next;
			while (tmp != NULL) {
				if (tmp->isEngine()) {
					distance_back = 0;
					break;
				}
				else if (!(tmp->isDiningCar())) {
					distance_back++;
					tmp = tmp->next;
				}
				else if (tmp->isDiningCar()) {
					distance_back++;
					break;
				}
			}
			if (distance_back == 0 && distance_front == 0) return -1;
			else if (distance_front == 0 && distance_back != 0) distance += distance_back;
			else if (distance_front != 0 && distance_back == 0) distance += distance_front;
			else if (distance_back*distance_front != 0 && distance_back < distance_front) {
				distance += distance_back;
			}
			else if (distance_back*distance_front != 0 && distance_back >= distance_front){
				distance += distance_front;
			}
			else {
				std::cout << "bug in the traincar.cpp AverageDistanceToDiningCar\n";
			}
			distance_back = 0;
			distance_front = 0;
			tmp = passenger_car->next;
		}
		else tmp = tmp->next;
	}
	return float(distance / num_passenger_cars);
}
int  ClosestEngineToSleeperCar(TrainCar* head){
	TrainCar* tmp = head;
	TrainCar* engincar;
	int distance_front = 0;
	int distance_back = 0;
	int distance = 0;
	while (tmp != NULL) {
		if (tmp->isEngine()) {
			engincar = tmp;
			//look forward to find sleepercar
			if (tmp->prev != NULL) {
				tmp = engincar->prev;
			}
			//if the first train car is the engine
			else if (tmp->prev == NULL) {
				if (tmp->isEngine()) {
					tmp = engincar->next;
					while (tmp != NULL) {
						if (!(tmp->isSleepingCar())) {
							distance_back++;
							tmp = tmp->next;
						}
						else if (tmp->isSleepingCar()) {
							distance_back++;
							distance = distance_back;
							break;
						}
					}
				}
				tmp = head->next;
				continue;
			}
			while (tmp != NULL) {
				if (!(tmp->isSleepingCar())) {
					distance_front++;
					tmp = tmp->prev;
				}
				else if (tmp->isSleepingCar()) {
					distance_front++;
					break;
				}
			}
			//look backward to find sleepercar
			tmp = engincar->next;
			while (tmp != NULL) {
				if (!(tmp->isSleepingCar())) {
					distance_back++;
					tmp = tmp->next;
				}
				else if (tmp->isSleepingCar()) {
					distance_back++;
					break;
				}
			}
			if (distance_front < distance_back && distance > distance_front) {
				distance = distance_front;
			}
			else if (distance_front > distance_back && distance > distance_back) {
				distance = distance_back;
			}
			distance_front = 0;
			distance_back = 0;
		}
		else tmp = tmp->next;
	}
	return distance;
}