#pragma once
#ifndef BEVERAGE_H
#define BEVERAGE_H
#include "Item.h"


class Beverage : public Item
{
protected:
	enum drinkType { alcoholic = 0, soda = 1, water = 2, hot = 3 };
	drinkType type;


public:
	Beverage();
	Beverage(int type, int newId, double newPrice, string newItemName, string newItemDescrpition);
	void setPrice(const int newprice) { this->price = newprice; };
	drinkType getType() { return type; };
	int getId() { return id; };
	string getDescription() { return itemDescription; };
	~Beverage();
};

#endif