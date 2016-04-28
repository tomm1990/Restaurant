#pragma once
#ifndef MENU_H
#define MENU_H
#include <vector>

#include "Item.h"
class Menu
{
	vector <Item> _items;
	int _numOfItems;
	//int maxItem; 
	//Item _items[10];

public:
	Menu(vector<Item>);
	~Menu();

	int getNumOfItems() const;
	void setNumOfItem(const int temp);
	void PrintFoodlMenu(Menu);
	void operator<<(const Menu& temp);
	void Menu::PrintTheMenu(Menu) const;
	void PrintInitialMenu(Menu) const;
	Item& getItemInfoByIndex(int);
	int getItemID(int) const;
	Item* Menu::getItemID_ToItem(int item_id);
	//friend ostream& operator<<(ostream& os, const Menu& a);

};


#endif