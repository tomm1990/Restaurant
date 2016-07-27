#include "stdafx.h"
#include "Beverage.h"


Beverage::Beverage()
{

}



Beverage::~Beverage()
{
}

Beverage::Beverage(int type, int newId, double newPrice, string newItemName, string newItemDescrpition) : Item(newId, newPrice, newItemName, newItemDescrpition)
{
	switch (type)
	{
	case 0:
		type = alcoholic;
		break;
	case 1:
		type = soda;
		break;
	case 2:
		type = water;
		break;
	case 3:
		type = hot;
		break;
	}
}

