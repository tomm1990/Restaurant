#include "stdafx.h"
#include "Table.h"


Table::Table(string tableName)
{
	this->_tableName = tableName;
	this->_tableBill = new Bill();
	this->_tableId = AllTablesID++;
	this->_amountOfItem = _tableBill->get_numOfItemsWithTheBill();
}


Table::~Table()
{
}

void Table::pay()
{
	_tableBill->setbill(0);
}

int Table::getID()const {
	return this->_tableId;
}


string Table::getTableName() const {
	return this->_tableName;
}

Bill* Table::getTableBill_ByID(const int id) {
	return this->_tableBill;
}

int Table::getTableAmountOfItems_ByID() {
	return this->_tableBill->get_numOfItemsWithTheBill();
}

void Table::AddItemsToTable(Menu* menu) {
	double tempPrice = 0.0;
	menu->PrintTheMenu(*menu);
	cout << "\nPlease choose your item ID : " << endl;
	cout << "(To stop , press -> 0 )" << endl;
	int choice, j = 0;
	cin >> choice;

	while (choice != 0) {
		for (int i = 0; i < menu->getNumOfItems(); i++) {
			if (choice == menu->getItemID(choice)) {
				/*		cout << "menu->getItemID(choice)  " << menu->getItemID(choice) << endl;
				cout << "choice  " << choice << endl;*/
				Item* temp = menu->getItemID_ToItem(menu->getItemID(choice));
				this->_tableItems.push_back(*temp);
				//tempPrice += menu->getItemID_ToItem(menu->getItemID(choice))->getPrice();				
				tempPrice = getTableBill()->getbill();
				tempPrice += temp->getPrice();
				this->setTableBill(tempPrice, this->_tableItems);
				//cout << "the item is : " << _tableItems[i].getName() << endl;
				break;
			}
			else {
				cout << "the iten is not in the menu.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\nPlease choose your item ID : " << endl;
				cout << "(To stop , press -> 0 )" << endl;
				cin >> choice;

			}
		}

		//cout << "Your have Added : " << this->_tableItems[j++].getName() << endl;
		cout << menu->getItemID_ToItem(menu->getItemID(choice))->getName() << " : checked";
		cout << "\nTotal Numbers of items so far  : " << this->_tableItems.size() << endl;

		cout << "\nPlease provide another item id , ( press 0 to stop )" << endl << endl;
		cin >> choice;
	}
	///this->setTableBill(tempPrice, this->_tableItems);

	cout << endl << "You can continue now... \n";
}


void Table::setTableBill(double totalPrice, vector <Item> items) {
	this->_tableBill->setbill(totalPrice);
	this->_tableBill->setTabsItems(items);
}


Bill* Table::getTableBill() const {
	return this->_tableBill;
}

bool Table::TablePayTheBill(vector<Table> &temp) {
	cout << " \n------------------------\n ";
	printTableItems();
	if (this->getTableBill()->getbill() == 0) {
		cout << "\nyour bill is empty\n";
		cout << "Do you want to close it?\n";
		cout << "1 <- Yes   ,    0 <- No\n";
		int pay;
		cin >> pay;
		if (pay == 1) {
			this->getTableBill()->setbill(0);
			cout << "You have successfully paid your bill\n";
			this->removeTable(temp);
			return true;
		}
		else if (pay == 2) {
			cout << "Still hungry...?\nLets order more...\n";
			return false;
		}
		else {

			cout << "We assume that you wanna keep on ordering...you may continue\n";
			return false;
		}
	}
	else {
		cout << "\nDo you want to pay the bill now ?\n";
		cout << "1 <- Yes   ,    0 <- No\n";
		int pay;
		cin >> pay;
		if (pay == 1) {
			this->getTableBill()->setbill(0);
			cout << "You have successfully paid your bill\n";
			this->removeTable(temp);
			return true;
		}
		else if (pay == 2) {
			cout << "Still hungry...?\nLets order more...\n";
			return false;
		}
		else {
			cout << "We assume that you wanna keep on ordering...you may continue\n";
			return false;
		}

	}


}

void Table::printTableItems() {
	cout << "Item ID" << "\t" << "Item Name" << "\t\t" << "Item Description" << "\t\t" << "Item Price" << endl;
	for (int i = 0; i < this->_tableItems.size(); i++) {
		cout << this->_tableItems[i].getID() << "\t" << this->_tableItems[i].getName() << "\t\t" << this->_tableItems[i].getDes() << "\t\t" << this->_tableItems[i].getPrice() << endl;
	}
	cout << "------------\n Total Price : " << this->getTableBill()->getbill();
}

void Table::removeTable(vector<Table> &temp) {
	temp.erase(temp.begin() + (this->getID() - 101));
	//temp.resize( temp.size() - 1);
	temp.shrink_to_fit();

}
