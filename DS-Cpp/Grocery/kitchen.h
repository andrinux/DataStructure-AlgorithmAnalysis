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
	int foundIngreCnt(const std::string &name);
	bool checkRecipe(std::list<Recipe>::const_iterator itr, std::ostream &ostr);
	void updateIngredient(std::list<Recipe>::const_iterator itr);
private:
	std::list<Ingredient> ingredients;
};

#endif