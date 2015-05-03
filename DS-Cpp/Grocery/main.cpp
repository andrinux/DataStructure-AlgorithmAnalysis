//
// PROVIDED CODE FOR HOMEWORK 4: GROCERY LISTS
// 
// You may use none, a little, or all of this, as you choose, but we
// strongly urge you to examine it carefully.  You may modify this
// code as you wish to complete the assignment.
//

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

#include "recipe.h"
#include "kitchen.h"


// Helper functions
void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen);
void printRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes);
void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen);
void recipeSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, const Kitchen &kitchen);
void do_printRecipe(std::ostream &ostr, std::list<Recipe>::const_iterator itrRecipe);
bool recipeExisting(std::list<Recipe> &recipes, Recipe& r);
void menuSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, const Kitchen &kitchen);
// The main loop parses opens the files for I/O & parses the input
int main(int argc, char* argv[]) {

  // Check the number of arguments.
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
    return 1;
  }
  // Open and test the input file.
  std::ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "Could not open " << argv[1] << " to read\n";
    return 1;
  }
  // Open and test the output file.
  std::ofstream ostr(argv[2]);
  if (!ostr) {
    std::cerr << "Could not open " << argv[2] << " to write\n";
    return 1;
  }

  // the kitchen & recipe list
  Kitchen kitchen;
  std::list<Recipe> recipes;

  // some variables to help with parsing
  char c;
  while (istr >> c) {
    if (c == 'r') {
      // READ A NEW RECIPE
      readRecipe(istr,ostr,recipes);

    } else if (c == 'a') {
      // ADD INGREDIENTS TO THE KITCHEN
      addIngredients(istr,ostr,kitchen);
      
    } else if (c == 'p') {
      // PRINT A PARTICULAR RECIPE
      printRecipe(istr,ostr,recipes);

    } else if (c == 'm') {
      // MAKE SOME FOOD
      makeRecipe(istr,ostr,recipes,kitchen);

    } else if (c == 'k') {
      // PRINT THE CONTENTS OF THE KITCHEN
      kitchen.printIngredients(ostr);

    } else if (c == 's') {
      // SUGGEST ALL RECIPES THAT CAN BE MADE INDIVIDUALLY FROM THE
      //   CURRENT CONTENTS OF THE KITCHEN
      recipeSuggestions(ostr,recipes,kitchen);

    } else if (c == 'd') {
      // EXTRA CREDIT: SUGGEST THE COLLECTION OF RECIPES THAT CAN BE
      // MADE TOGETHER THAT USE THE MAXIMUM NUMBER OF UNITS OF
      // INGREDIENTS
		menuSuggestions(ostr, recipes, kitchen);
    } else {
      std::cerr << "unknown character: " << c << std::endl;
      exit(0);
    }
  }  
}


void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
  int units;
  std::string name, name2;  
  istr >> name;
  // build the new recipe
  Recipe r(name);
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name2;
    r.addIngredient(name2,units);
  }
  // add it to the list
  if (recipeExisting(recipes, r))
	  ostr << "Recipe for " << name << "already exists" << std::endl;
  else{
	  recipes.push_back(r);
	  ostr << "Recipe for " << name << " added" << std::endl;
  }
}

bool recipeExisting(std::list<Recipe> &recipes, Recipe& r){
	std::list<Recipe>::const_iterator itr;
	for (itr = recipes.begin(); itr != recipes.end(); itr++){
		if (r.getName() == itr->getName())
			return true;
	}
	return false;
}

void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
  int units;
  std::string name;
  int cntOld = kitchen.getIngredients().size();
  int count = 0;
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name;
    // add the ingredients to the kitchen
    kitchen.addIngredient(name,units);
    count++;
  }
  int cntNew = kitchen.getIngredients().size();
  if (cntNew-cntOld > 1) 
	  ostr << count << " ingredients added to kitchen" << std::endl;
  else
	  ostr << count << " ingredient added to kitchen" << std::endl;
}

//Print the list for a recipe
void printRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes) {
  std::string name;
  istr >> name;
  //Check if the recipe existing first
  //assert(name != "cheeseburger");
  std::list<Recipe>::const_iterator itrRecipe; //Must be const_iterator??? WHY?
  for (itrRecipe = recipes.begin(); itrRecipe != recipes.end(); itrRecipe++){
	  if (itrRecipe->getName() == name){
		  //Found and Print
		  ostr << "To make " << name << ", mix together:" << std::endl;
		  do_printRecipe(ostr, itrRecipe);
		  return;
	  }
  }
  if (itrRecipe == recipes.end()){
	  ostr << "No recipe for " << name << std::endl;
  }
  
}

//Do the print for a FOUND Recipe using iterator
void do_printRecipe(std::ostream &ostr, std::list<Recipe>::const_iterator itrRecipe){
	std::list<Ingredient>::const_iterator itrIngre;
	(*itrRecipe).printCurRecipe(ostr);
}

void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen) {
	//Get the name from Input istr
	std::string name;
	istr >> name;
	//Make "name"
	//Check if "name" exists in recipes
	std::list<Recipe>::const_iterator itrRecipe;
	for (itrRecipe = recipes.begin(); itrRecipe != recipes.end(); itrRecipe++){
		if (itrRecipe->getName() == name){
			//Found this recipe
			break;
		}
	}
	if (itrRecipe == recipes.end()){
		ostr << "Don't know how to make " << name << std::endl;
		return;
	}
	//If come to here, then indicates the recipe found
	//Check if Kitchen contains enough materials one by one
	//kitchen.printIngredients(std::cout);
	bool Enough=kitchen.checkRecipe(itrRecipe, ostr);
	if (Enough){
		ostr << "Made " << name << std::endl;
		kitchen.updateIngredient(itrRecipe, ostr);
	}
	else{
		ostr << "Cannot make " << name << ", need to buy:" << std::endl;
		kitchen.ToBuyList(itrRecipe, ostr);
	}
  
}


void recipeSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, 
	const Kitchen &kitchen) {
	std::list<Recipe>::const_iterator itrRecpList;
	std::list<std::string> OKtoMake;
	//Check these one by one, if meet, store em in a list
	for (itrRecpList = recipes.begin(); itrRecpList != recipes.end(); itrRecpList++){
		if (kitchen.checkRecipe(itrRecpList, ostr)){
			OKtoMake.push_back(itrRecpList->getName());
		}
	}
	OKtoMake.sort();
	if (OKtoMake.size()==0)
		ostr << "No recipes can be prepared" << std::endl;
	else if (OKtoMake.size()==1)
			ostr << "Recipe that can be prepared:" << std::endl;
		else
			ostr << "Recipes that can be prepared:" << std::endl;
	std::list<std::string>::const_iterator itr = OKtoMake.begin();
	for (; itr != OKtoMake.end(); itr++){
		ostr << "  " << *itr << std::endl;
	}

	return;
}

//Extra Credit
void menuSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, 	const Kitchen &kitchen) {
	//Seems like an Knap Sack Problem
	//kitchen.printIngredients(std::cout);
	
	//return;
}
