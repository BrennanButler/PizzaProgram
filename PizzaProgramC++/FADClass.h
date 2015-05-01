#pragma once

#include "DrinkClass.h"
#include "PizzaClass.h"
#include "ToppingClass.h"

enum Itype
{
	PIZZA,
	DRINK,
	TOPPING
};


class FADClass
{
public:
	FADClass();
	~FADClass();

	bool Initialize();
	void ShowMenu(Itype type);
	double getPrice(Itype type, int ID);
	int numElements(Itype type);
	std::string getElement(Itype type, int ID);

private:
	DrinkClass *cDrink;
	PizzaClass *cPizza;
	ToppingClass *cTopping;

};
