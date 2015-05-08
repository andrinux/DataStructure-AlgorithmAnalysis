// There are a number of additional functions used in main.cpp that
// you need to declare and implement.

//This file is used to implement some functions declared in traincar_prototytpe.h

#include "traincar_prototypes.h"

//Impelement the pushback function, "simple" is the linked list head.
//Note: No need to add "static" here 
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