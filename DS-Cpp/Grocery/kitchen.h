#ifndef _KITCHEN_H_
#define _KITCHEN_H_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "recipe.h"

class Kitchen{
public:
	Kitchen();
	void addIngredient(std::string &name, int units);
	void printIngredients(std::ofstream &ostr);

private:
	std::list<Ingredient> ingredients;
};
#endif