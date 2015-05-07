// There are a number of additional functions used in main.cpp that
// you need to declare and implement.

//This file is used to implement some functions declared in traincar_prototytpe.h

#include "traincar_prototypes.h"

//Impelement the pushback function, "simple" is the linked list head.
//Note: No need to add "static" here 
void PushBack(TrainCar* simple, TrainCar* newCar){
	if (simple == NULL){
		//still a empty list
		simple = newCar;
	}
	else{
		//need to loop to the end of list because there is no "tail" in the class
		TrainCar* itr = simple;
		while (itr->next != NULL){
			itr = itr->next;
		}
		newCar->prev = itr;
		itr->next = newCar;
	}
	return;
}

void DeleteAllCars(TrainCar* simple){
	
	return;
}