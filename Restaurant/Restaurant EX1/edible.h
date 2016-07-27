
#pragma once
#ifndef EDIABLE_H
#define EDIABLE_H
#include <string>
#include "Item.h"


class edible : public Item
{
protected:
	enum drinkType { starter, first_course, second_course, dessert };
	int _lineNum;

public:
	edible();
	void setPrice(const int newprice) { this->price = newprice; };
	edible(int type, int newId, double newPrice, string newItemName, string newItemDescrpition);
	~edible();
};

#endif