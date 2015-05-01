#include "FADClass.h"
#include "FileClass.h"


FADClass::FADClass()
{
}

FADClass::~FADClass()
{
	if (cDrink)
	{
		delete cDrink;
		cDrink = nullptr;
	}

	if (cPizza)
	{
		delete cPizza;
		cPizza = nullptr;
	}

	if (cTopping)
	{
		delete cTopping;
		cTopping = nullptr;
	}
}


bool FADClass::Initialize()
{
	cDrink = new DrinkClass();

	if (!cDrink)
		return false;

	if (!cDrink->Initialize())
		return false;

	cPizza = new PizzaClass();

	if (!cPizza)
		return false;

	if (!cPizza->Initialize())
		return false;

	cTopping = new ToppingClass();

	if (!cTopping)
		return false;

	if (!cTopping->Initialize())
		return false;
	return true;
}

void FADClass::ShowMenu(Itype type)
{
	switch (type)
	{
		case DRINK:
			return cDrink->printAll();
		case PIZZA:
			return cPizza->printAll();
		case TOPPING:
			return cTopping->printAll();
		default: return;
	}
}

double FADClass::getPrice(Itype type, int ID)
{
	switch (type)
	{
		case DRINK:
			return cDrink->getPrice(ID);
		case PIZZA:
			return cPizza->getPrice(ID);
		case TOPPING:
			return cTopping->getPrice(ID);
		default: return -1;
	}
}

int FADClass::numElements(Itype type)
{
	switch (type)
	{
		case DRINK:
			return cDrink->numDrinks();
		case PIZZA:
			return cPizza->numPizzas();
		case TOPPING:
			return cTopping->numToppings();
		default: return -1;
	}
}

std::string FADClass::getElement(Itype type, int ID)
{
	switch (type)
	{
		case DRINK:
			return cDrink->getDrinkInfo(ID);
		case PIZZA:
			return cPizza->getPizzaInfo(ID);
		case TOPPING:
			return cTopping->getToppingInfo(ID);
		default: return "error";
	}
	return "error";
}