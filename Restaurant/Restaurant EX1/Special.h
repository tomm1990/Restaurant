#pragma once
#ifndef SPECIAL_H
#define SPECIAL_H
#include "Beverage.h"
#include "Item.h"
#include "edible.h"

static int Specials = 30;

class Special : public Item
{
	Item *_specBeverage;
	Item *_specEdible;
public:
	Special();
	//Special( Beverage , edible );
	Special(Item * bev, Item * ed);
	~Special();
	void setNameOfItem(const string a) {
		this->itemName = a;
	}

	void setDescriptionOFItem(const string a) {
		this->itemDescription = a;
	}


	//Special(int newId , string newItemName, string newItemDescrpition) ;
	void setPrice(const int newprice) {
		this->setPrice((this->_specBeverage->getPrice() + this->_specEdible->getPrice()));
	};
};

#endif