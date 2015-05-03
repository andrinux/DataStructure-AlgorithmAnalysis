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
	void printIngredients(std::ostream &ostr) const;
	int foundIngreCnt(const std::string &name) const;
	bool checkRecipe(std::list<Recipe>::const_iterator itr, std::ostream &ostr) const;
	void updateIngredient(std::list<Recipe>::const_iterator itr, std::ostream &ostr);
	const std::list<Ingredient>&  getIngredients() const{ return this->ingredients; }
	int changeIngreCnt(const std::string& name, int cnt, std::ostream &ostr);
	void ToBuyList(std::list<Recipe>::const_iterator itr, std::ostream &ostr);
	void Re_sort();

private:
	std::list<Ingredient> ingredients;
};

bool comp_Kit_Ingre(Ingredient &ingre1, Ingredient &ingre2);
#endif