
#include <iostream>
#include <string>
#include <list>

#include "kitchen.h"
#include "recipe.h"

Kitchen::Kitchen(){

}

void Kitchen::addIngredient(std::string &name, int units){

}
void Kitchen::printIngredients(std::ofstream &ostr){

}

int Kitchen::foundIngreCnt(const std::string &name){
	std::list<Ingredient>::const_iterator itr;
	for (itr = ingredients.begin(); itr != ingredients.end(); itr++){
		if (itr->getName() == name)
			return itr->getUnits();
	}
	//if (itr == ingredients.end())
		return 0;//didn't find it
}

bool Kitchen::checkRecipe(std::list<Recipe>::const_iterator itr, std::ostream &ostr){
	return true;
}

void Kitchen::updateIngredient(std::list<Recipe>::const_iterator itr){
	return;
}
