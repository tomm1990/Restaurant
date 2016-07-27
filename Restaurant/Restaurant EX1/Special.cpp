#include "stdafx.h"
#include "Special.h"


Special::Special()
{
}


Special::~Special()
{
}

//Special::Special(Beverage _bev, edible _edi)
//{
//	_specBeverage = _bev;
//	_specEdible = _edi;
//}

Special::Special(Item * bev, Item * ed) {
	this->_specBeverage = bev;
	this->_specEdible = ed;
	this->price = (this->_specBeverage->getPrice() + this->_specEdible->getPrice());
	this->itemDescription = "Special description";
	this->itemName = (this->_specBeverage->getName() + " and " + this->_specEdible->getName());
	this->id = Specials++;
}

//Special::Special(int newId, string newItemName, string newItemDescrpition)
//:Item( newId, newItemName, newItemDescrpition){
//	this->setPrice (  ( this->_specBeverage->getPrice() + this->_specEdible->getPrice() )  );
//	price = (this->_specBeverage->getPrice() + this->_specEdible->getPrice());
//}


