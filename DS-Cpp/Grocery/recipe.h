#ifndef _RECIPE_H
#define _RECIPE_H

#include <iostream>
#include <string>
#include <list>

class Ingredient{
public:
	//friend Recipe;
	Ingredient() : name(""), units(0) {};
	Ingredient(std::string& name) :name(name), units(0) {}
	Ingredient(std::string& name, int number) :name(name), units(number) {}
	int getUnits() const { return units; }
	void setUnits(int number) { units = number; }
	void addUnits(int number){ units += number; }
	const std::string& getName() const { return name; } //Here &? another const

private:
	std::string name;
	int units;
};


//Implementation of Recipe Class
class Recipe{
public:
	Recipe();
	Recipe(std::string& name);
	void addIngredient(std::string& name, int units);
	const std::string& getName() const { return RecipeName; }
	void SortInOrder();
	void printCurRecipe(std::ostream &ostr) const;//Must contain const.
	const std::list<Ingredient>& getIngredient() const { return ingredients; }
private:
	std::string RecipeName;
	std::list<Ingredient> ingredients;
};

bool IngreComp(Ingredient &ingre1, Ingredient &ingre2);

#endif