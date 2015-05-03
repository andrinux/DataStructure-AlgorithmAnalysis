#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "recipe.h"

Recipe::Recipe(){

}

Recipe::Recipe(std::string& name){
	this->RecipeName = name;
}

void Recipe::addIngredient(std::string& name, int units){
	Ingredient Ingre(name, units); 
	this->ingredients.push_back(Ingre);//Need to keep order or not?
	//Add each Ingredient, trigger one SORTING...
	//Seems not that efficient...
	this->SortInOrder(); 
	return;
}
//Sort for List. Cannot Use STL???
void Recipe::SortInOrder(){
	//std::sort(ingredients.begin(), ingredients.end(), IngreComp);
	ingredients.sort(IngreComp);
}

void Recipe::printCurRecipe(std::ostream &ostr) const {
	std::list<Ingredient>::const_iterator itr;
	for (itr = ingredients.begin(); itr != ingredients.end(); itr++){
		if (itr->getUnits() == 1)
			ostr <<"  "<< itr->getUnits() << " unit of " 
			<< itr->getName() <<std::endl;
		else
			ostr << "  " << itr->getUnits() << " units of " 
			<< itr->getName() << "s" << std::endl;
	}
}

bool IngreComp(Ingredient &ingre1, Ingredient &ingre2) {
	return ((ingre1.getName() < ingre2.getName()) ? true : false);
}


