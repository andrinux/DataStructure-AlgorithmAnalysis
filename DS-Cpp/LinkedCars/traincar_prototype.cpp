// There are a number of additional functions used in main.cpp that
// you need to declare and implement.

//This file is used to implement some functions declared in traincar_prototytpe.h

#include "traincar_prototypes.h"
#include <vector>
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
	std::vector<TrainCar*> trains;
	return trains;
}

void TotalWeightAndCountCars(TrainCar* train, int total_weight, int num_engines,
	int num_freight_cars, int num_passenger_cars, int num_dining_cars, int num_sleeping_cars){
	return;
}

float CalculateSpeed(TrainCar* train){
	return 0.0;
}