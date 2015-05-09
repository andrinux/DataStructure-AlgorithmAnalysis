// There are a number of additional functions used in main.cpp that
// you need to declare and implement.

//This file is used to implement some functions declared in traincar_prototytpe.h

#include "traincar_prototypes.h"
#include <vector>
#include <iostream>
#include <algorithm>

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
std::vector<TrainCar*> ShipFreight(TrainCar* all_engines, TrainCar* all_freight, int min_speed, int max_cars_per_train){
	//all_engines in the engines-list avaiable  all_freights are all the freights cars  
	std::vector<TrainCar*> trains; //store the final result
	sortFreights(all_freight);
	//Use Greedy Algorithm to solve
	while (engineLeft(all_engines) != 0 && freightLeft(all_freight) != 0){
		TrainCar* curTrain;

	}
	return trains;
}

int engineLeft(TrainCar * all_engines){
	TrainCar * itr = all_engines;
	int num = 0;
	while (itr->next != NULL){
		num++;
		itr = itr->next;
	}
	return num;
}

int freightLeft(TrainCar * all_freight){
	TrainCar * itr = all_freight;
	int num = 0;
	while (itr->next != NULL){
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
	TrainCar *itr = all_freight;
	while (itr != NULL){
		std::cout << itr->getWeight() << ", ";
		itr = itr->next;
	}
	std::cout << std::endl;
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
	itr = all_freight;
	while (itr != NULL){
		std::cout << itr->getWeight() << ", ";
		itr = itr->next;
	}
	std::cout << std::endl;
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
	else if(N2==NULL){
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

void TotalWeightAndCountCars(TrainCar* train, int total_weight, int num_engines,
	int num_freight_cars, int num_passenger_cars, int num_dining_cars, int num_sleeping_cars){
	return;
}

float CalculateSpeed(TrainCar* train){
	return 0.0;
}