#include "stdafx.h"
#include "Bill.h"
#include "Table.h"

Bill::Bill()
{
}

Bill::Bill(int totalBill, vector <Item> items)
{
	_orderNum = StaticOrdersNums++;
	_totalBill = totalBill;
	_tabItems = items;
}

int Bill::get_numOfItemsWithTheBill() const {
	return this->_tabItems.size();
}

Bill::Bill(const Bill& t) {
	this->_totalBill = t._totalBill;
	this->_orderNum = t._orderNum;
	this->_tabItems = t._tabItems;
}

Bill::~Bill()
{
}

double Bill::calculateTotal()
{
	for (int i = 0; i < 90; i++)
	{
		_totalBill += _tabItems[i].getPrice();
	}
	return _totalBill;
}

void Bill::setTabsItems(const vector <Item> items) {
	this->_tabItems = items;
}
