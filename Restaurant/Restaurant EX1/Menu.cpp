#include "stdafx.h"
#include "Menu.h"
#include "Item.h"
#include "Bill.h"

Menu::Menu(vector<Item> vec)
{
	for (int i = 0; i < vec.size(); i++) {
		_items.push_back(vec[i]);
	}
	this->_numOfItems = vec.size();
	//cout << " num of item is  : " << this->_numOfItems << endl;
}


Menu::~Menu()
{
}

int Menu::getNumOfItems() const {
	return this->_numOfItems;
}

void Menu::setNumOfItem(const int temp) {
	this->_numOfItems = temp;
}

//friend ostream& Menu::operator<<(const ostream& os, const Menu& a){
//
//}

void Menu::PrintFoodlMenu(Menu menu) {
	cout << "Please choose from the following menu : " << endl;
	for (int i = 0; i < menu.getNumOfItems(); i++)
	{
		cout << "[" << i << "]" << endl;

	}


}

void Menu::PrintInitialMenu(Menu menu) const {

	cout << "\n\nPlease choose from the following actions : \n" << endl;
	cout << "[" << "1" << "]" << "add a table" << endl;
	cout << "[" << "2" << "]" << "add an item to an existing table" << endl;
	cout << "[" << "3" << "]" << "print the menu" << endl;
	cout << "[" << "4" << "]" << "show the current bill" << endl;
	cout << "[" << "5" << "]" << "exit" << endl << endl;
	cout << "-->";
}

void Menu::PrintTheMenu(Menu  menu) const {
	system("cls");
	cout << "\n Main Menu \n ---------------\n";
	cout << "Item ID" << "\t" << "Item Name" << "\t\t\t" << "Item Description" << "\t\t" << "Item Price" << endl;
	for (int i = 0; i < menu.getNumOfItems(); i++) {
		cout << menu.getItemInfoByIndex(i).getID() << "\t" << menu.getItemInfoByIndex(i).getName() << "\t\t" << menu.getItemInfoByIndex(i).getDes() << "\t\t" << menu.getItemInfoByIndex(i).getPrice() << endl;
	}
}

Item& Menu::getItemInfoByIndex(int i) {
	return this->_items[i];
}

int Menu::getItemID(int id) const {
	//cout << " the number of items is : - > " << getNumOfItems() << endl; 
	for (int i = 0; i < getNumOfItems(); i++) {
		//cout << " id of items" << this->_items[i].getID() << endl; 
		//cout << " name of items" << this->_items[i].getName() << endl;
		if (id == this->_items[i].getID()) return this->_items[i].getID();
	}
	return 0;
}

Item* Menu::getItemID_ToItem(int item_id) {
	for (int i = 0; i < getNumOfItems(); i++) {
		if (item_id == this->_items[i].getID()) return &_items[i];
	}
}


