#include "stdafx.h"
#include "edible.h"


edible::edible()
{
}


edible::~edible()
{
}

edible::edible(int type, int newId, double newPrice, string newItemName, string newItemDescrpition)
	:Item(newId, newPrice, newItemName, newItemDescrpition)
{
	switch (type)
	{
	case 0: type = starter;
	case 1: type = first_course;
	case 2: type = second_course;
	case 3: type = dessert;
	}
}