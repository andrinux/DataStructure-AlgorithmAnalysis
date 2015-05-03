
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "kitchen.h"
#include "recipe.h"

Kitchen::Kitchen(){
	//Do we need to write sth inside? I think the list can be initialze automatically
	//Left blank
}

//Add the ingredients to the Kitchen. WTF.
//NEED to check if the ingredient is existing
void Kitchen::addIngredient(std::string &name, int units){
	Ingredient ingre(name, units);
	std::list<Ingredient>::iterator itr = ingredients.begin();
	for (; itr != ingredients.end(); itr++){
		if (name == itr->getName()){
			itr->addUnits(units);
			//ingredients.sort(comp_Kit_Ingre);
			Re_sort();
			return;
		}	
	}
	ingredients.push_back(ingre);
	//ingredients.sort(comp_Kit_Ingre);
	Re_sort();
	return;
}

//CHeck if there is some ingredients are used up and re-sort
void Kitchen::Re_sort(){
	std::list<Ingredient>::iterator itr = ingredients.begin();
	for (; itr != ingredients.end(); ){
		if (itr->getUnits() == 0)
			itr = ingredients.erase(itr); //Very Important Here. List Delete is strange
		else
			itr++;
		}
	ingredients.sort(comp_Kit_Ingre);
}

void Kitchen::printIngredients(std::ostream &ostr) const{
	ostr << "In the kitchen:" << std::endl;
	std::list<Ingredient>::const_iterator itr = ingredients.begin();
	for (; itr != ingredients.end(); itr++){
		if (itr->getUnits() > 1)
			ostr << "  " << itr->getUnits() << " units of " << itr->getName() << std::endl;
		else
			ostr << "  " << itr->getUnits() << " unit of " << itr->getName() << std::endl;
	}
}

int Kitchen::foundIngreCnt(const std::string &name) const{
	std::list<Ingredient>::const_iterator itr;
	for (itr = ingredients.begin(); itr != ingredients.end(); itr++){
		if (itr->getName() == name)
			return itr->getUnits();
	}
	//if (itr == ingredients.end())
		return 0;//didn't find it
}

int Kitchen::changeIngreCnt(const std::string& name, int cnt, std::ostream &ostr){
	std::list<Ingredient>::iterator itr;
	for (itr = ingredients.begin(); itr != ingredients.end(); itr++){
		if (itr->getName() == name){
			if (itr->getUnits() < cnt){
				ostr << "Error: Seems " << name << " is not enough." << std::endl;
			}
			itr->addUnits(-1 * cnt);
			return itr->getUnits();//Return the cnt left
		}
	}
	ostr << "Error: Didn't Find " << name << std::endl;
	return -1;
}

//Check if the kitchen contains enough ingredients for Recipe itr
bool Kitchen::checkRecipe(std::list<Recipe>::const_iterator Recipe, std::ostream &ostr) const{
	std::list<Ingredient>::const_iterator ingreInRecipe;
	for (ingreInRecipe = Recipe->getIngredient().begin(); 
		ingreInRecipe != Recipe->getIngredient().end(); ingreInRecipe++){
		if (ingreInRecipe->getUnits() > foundIngreCnt(ingreInRecipe->getName()))
			return false;
	}
	return true;
}


//Already know the iKitchen is enough to make a recipe, update the Kitchen
void Kitchen::updateIngredient(std::list<Recipe>::const_iterator itr, std::ostream &ostr){
	std::list<Ingredient>::const_iterator itr_Recipe_Ingre;
	itr_Recipe_Ingre = itr->getIngredient().begin();
	//FInd the ingredient in the Kitchen and update its units
	for (; itr_Recipe_Ingre != itr->getIngredient().end(); itr_Recipe_Ingre++){
		changeIngreCnt(itr_Recipe_Ingre->getName(), itr_Recipe_Ingre->getUnits(), ostr);
	}
	//ingredients.sort(comp_Kit_Ingre);//After removing some ingredient, NEED to Resort
	Re_sort();
	return;
}

//Already know that there exists something insufficient, So need to list the ToBuy list
void Kitchen::ToBuyList(std::list<Recipe>::const_iterator Recipe, std::ostream &ostr){
	std::list<Ingredient>::const_iterator ingreInRecipe;
	for (ingreInRecipe = Recipe->getIngredient().begin();
		ingreInRecipe != Recipe->getIngredient().end(); ingreInRecipe++){
		int cntNeed = ingreInRecipe->getUnits();
		int cntHave = foundIngreCnt(ingreInRecipe->getName());
		if (cntNeed - cntHave > 0){
			if (cntNeed - cntHave > 1)
				ostr <<"  "<< (cntNeed - cntHave) << " units of " << ingreInRecipe->getName() << std::endl;
			else
				ostr <<"  " << (cntNeed - cntHave) << " unit of " << ingreInRecipe->getName() << std::endl;
		}		
	}
}

//Sort helper function for the ingredients in Kitchen
bool comp_Kit_Ingre(Ingredient &ingre1, Ingredient &ingre2)
{
	//sort by quantity first, and then the alpbeta of name
	if (ingre1.getUnits() == ingre2.getUnits())
		return (ingre1.getName() > ingre2.getName()) ? false : true;
	else
		return (ingre1.getUnits() > ingre2.getUnits()) ? false : true;
}