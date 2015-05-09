// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//

//Helper function to add one new car to the list
#include "traincar.h"
#include <vector>

void PushBack(TrainCar*& simple, TrainCar* newCar);

//Destroy thr list from beginning to avoid memory leak
void DeleteAllCars(TrainCar* simple);
//Optimization problem
std::vector<TrainCar*>  ShipFreight(TrainCar* all_engines, TrainCar* all_freight, int min_speed, int max_cars_per_train);
//Sort the freight list from heavy to light
void sortFreights(TrainCar*& all_freight);
//Swap to adjacent Node, Note that std::sort doesn't work well here
void swap(TrainCar*& a);
int engineLeft(TrainCar * all_engines);
int freightLeft(TrainCar * all_freight);
void TotalWeightAndCountCars(TrainCar* train, int total_weight, int num_engines, int num_freight_cars, int num_passenger_cars, int num_dining_cars, int num_sleeping_cars);

float CalculateSpeed(TrainCar* train);

