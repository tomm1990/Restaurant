// Restaurant project v1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Beverage.h"
#include "Table.h"
#include <iostream>
#include "Item.h"
#include "Menu.h"
#include "edible.h"
#include "Special.h"
#include "Bill.h"

//void PrintInitialMenu( Menu menu);
void AddTable(vector<Table> &table);
Table* printActiveTables(vector<Table> &temp);

using namespace std;

int main()
{
	vector <Table> tables;
	bool flag = true;
	int choice;
	Item* coke = new Beverage(1, 10, 20, "Coca Cola", "great for your teeth");
	Item* fizzybublach = new Beverage(1, 11, 15, "fizzybublach", "is gud for your health");	//move items to a list or something in a new page????
	Item* pasta = new edible(1, 21, 50, "Napolitana", "Pasta with tomato sauce");
	Item* sandwich = new edible(1, 22, 40, "Tuna and Fish", "Tuna cheese Sandwich");

	Item* Bussines = new Special(coke, pasta);
	//Bussines->setPrice(333333);
	vector <Item> dish;
	dish.push_back(*coke);
	dish.push_back(*fizzybublach);
	dish.push_back(*pasta);
	dish.push_back(*sandwich);
	dish.push_back(*Bussines);
	Menu menu(dish);


	int i = 0;
	while (flag == true) {
		system("cls");
		menu.PrintInitialMenu(menu);
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			AddTable(tables);
			cout << "\nDo you want to add items to " << tables[i].getTableName() << "'s table?" << endl;
			cout << " If yes press 1 \n If no press 0  \n -> ";
			int choice;
			cin >> choice;
			if (choice == 1) {
				tables[i].AddItemsToTable(&menu);
				i++;
			}
			else if (choice == 0) {
				i++;
				break;
			}
			else {
				i++;
				cout << "Undefined option, Moving to main menu" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> choice;
				cout << " If yes press 1 \n If no press 0  \n -> ";
				break;
			}
			break;
		}
		case 2:
		{
			if (tables.size() == 0)
			{
				cout << "you need to add tables !\n";
				cout << "\npress ENTER to continue\n";
				system("pause>nul");
				break;
			}
			cout << "Please choose a table to add items to : " << endl;
			Table *t = printActiveTables(tables);
			t->AddItemsToTable(&menu);
			i++;
			break;
		}

		case 3:
		{
			menu.PrintTheMenu(menu);
			cout << "\npress ENTER to continue\n";
			system("pause>nul");
			break;
		}
		case 4:
		{
			if (tables.size() == 0)
			{
				cout << "you need to add tables !\n";
				cout << "\npress ENTER to continue\n";
				system("pause>nul");
				continue;
			}
			cout << "Please choose a table to check out :\n " << endl;
			Table *t = printActiveTables(tables);
			t->TablePayTheBill(tables);
			i--;
			break;
		}
		case 5:
		{
			flag = false;
			break;
		}
		default:
		{
			cout << "Please try again \n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		}

	}
	return 0;
}





void AddTable(vector<Table> &table) {
	cout << "\nYou choosed to add a new table\nPlease provide a name : ";
	string tablename;
	cin >> tablename;
	Table n(tablename);
	table.push_back(n);
}

Table* printActiveTables(vector<Table> &temp) {
	for (int i = 0; i < temp.size(); i++) {
		cout << "ID: " << temp[i].getID() << "--> " << temp[i].getTableName() << endl;
	}
	cout << "\nID number ";
	if (temp.size() > 1)
		cout << "(" << temp[0].getID() << "-" << temp[temp.size() - 1].getID() << "):";
	if (temp.size() == 1) {
		cout << "(" << temp[0].getID() << "?):";
	}

	int c;
	bool flag = true;
	cin >> c;

	while (c< temp[0].getID() || c>temp[temp.size() - 1].getID()) {
		cout << "\nThe table ID is not recognized. \nplease try again : ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> c;
	}
	while (flag) {

		for (int i = 0; i < temp.size(); i++)
		{
			if (c == temp[i].getID()) {
				flag = false;
				return &temp[c - 101];
			}
		}

	}
}


