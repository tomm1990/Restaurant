#include "stdafx.h"
#include "Item.h"
#include "Beverage.h"

Item::Item()
{
}


//Item::~Item()
//{
//}

Item::Item(int newId, double newPrice, string newItemName, string newItemDescrpition)
{
	//this->_lineNum = lineNum;
	this->id = newId;
	this->price = newPrice;
	this->itemName = newItemName;
	this->itemDescription = newItemDescrpition;
}

void Item::operator = (const Item& temp) {
	this->id = temp.id;
	this->itemDescription = temp.itemDescription;
	this->itemName = temp.itemName;
	this->price = temp.price;

}

const string Item::getName() const {
	return (this->itemName);
}

const string Item::getDes() const {
	return (this->itemDescription);
}

int Item::getID() const {
	return (this->id);
}


