#include <iostream>
#include <string>
#include <list>

#include "recipe.h"

Recipe::Recipe(){

}

Recipe::Recipe(std::string& name){
	this->RecipeName = name;
}

void Recipe::addIngredient(std::string& name, int units){
	Ingredient Ingre(name, units); 
	this->ingredients.push_back(Ingre);//Need to keep order or not?
	return;
}

