// There are a number of additional functions used in main.cpp that
// you need to declare and implement.

//This file is used to implement some functions declared in traincar_prototytpe.h

#include "traincar_prototypes.h"
#include <vector>
#include <iostream>

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
std::vector<TrainCar*>  ShipFreight(TrainCar* all_engines, TrainCar* all_freight, int min_speed, int max_cars_per_train){
	//all_engines in the engines-list avaiable  all_freights are all the freights cars  
	std::vector<TrainCar*> trains; //store the final result
	sortFreights(all_freight);
	return trains;
}

//Sort freights
void sortFreights(TrainCar*& all_freight){
	//Just Use  sorting first
	//debug info
	TrainCar *itr = all_freight;
	while (itr != NULL){
		std::cout << itr->getWeight()<<", ";
		itr = itr->next;
	}
	std::cout << std::endl;
	//Start 
	TrainCar *i, *j;
	for (i = all_freight; i != NULL; i = i->next){
		for (j = all_freight; j != NULL; j = j->next){
			if (j->getWeight() < j->getWeight()){
				swap(j);
			}
		}
		while (j->prev != NULL)
			j = j->prev;
		all_freight = j;
	}

	//swap(all_freight);
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