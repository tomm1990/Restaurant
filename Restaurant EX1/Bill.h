#pragma once
#ifndef BILL_H
#define BILL_H

#include <vector>
#include "Item.h"

static int StaticOrdersNums = 501;

class Bill
{
	int _orderNum;
	double _totalBill;
	int _numOfItemsWithTheBill;
	vector <Item> _tabItems;

public:
	Bill(int totalBill, vector <Item> items);
	Bill(const Bill& t);
	Bill();
	void setbill(int x) { _totalBill = x; }
	double getbill() { return _totalBill; };
	double	calculateTotal();
	int get_numOfItemsWithTheBill() const;
	void setBill(const Bill&);
	void setTabsItems(const vector <Item> items);

	~Bill();
};

#endif