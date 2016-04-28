#pragma once
#ifndef TABLE_H
#define TABLE_H

#include "Bill.h"
#include "Menu.h"

static int AllTablesID = 101;

class Table
{
	vector <Item> _tableItems;
	string _tableName;
	Bill *_tableBill;
	int _tableId;
	int _amountOfItem;
	bool flag = true;

public:

	Table(string);
	~Table();
	void pay();

	int getID() const;
	string getTableName() const;

	Bill* getTableBill_ByID(const int);
	Bill* getTableBill() const;

	int getTableAmountOfItems_ByID();

	void AddItemsToTable(Menu*);

	void setTableBill(double, vector <Item> items);

	bool TablePayTheBill(vector<Table> &temp);

	void printTableItems();

	void removeTable(vector<Table> &temp);

};

#endif