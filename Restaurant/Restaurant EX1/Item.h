#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {

protected: int id;
		   double price;
		   string  itemName;
		   string itemDescription;
public:
	const  double getPrice() { return this->price; };
	//void virtual setPrice(const int newprice) { this->price = newprice; };
	void virtual setPrice(const int newprice) {  };
	Item(int, double, string, string);
	Item();
	~Item() {
		//if (this) delete this;
	};
	void operator=(const Item& temp);
	const string getName() const;



	const string getDes() const;
	int getID() const;

	void virtual setDescriptionOFItem(const string a) {};
	void virtual setNameOfItem(const string a) {};
};

#endif
