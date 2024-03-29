// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include"Header.h"


class Customer {
private:
	int id, phone, billAmmount;
	string name;
	string address;

public:
	void setDetails(int id, string name, string address, int billAmmount, int phone) {
		this->id = id;
		this->name = name;
		this->address = address;
		this->billAmmount = billAmmount;
		this->phone = phone;
	}

	int getID() {
		return id;
	}

	string getName() {
		return name;
	}

	string getAddress() {
		return address;
	}

	int getbillammount() {
		return billAmmount;
	}

	int getphone() {
		return phone;
	}

	void setID() {
		this->id = getInteger("Enter id: ");
	}
	void setName() {
		this->name = getString("Enter name: ");
	}
	void setAddress() {
		this->address = getString("Enter address: ");
	}
	void setphone() {
		this->phone = getInteger("Enter phoneNum: ");
	}
	void setbillAmmount() {
		this->phone = getInteger("Enter Ammount: ");
	}
};
Customer* allCustomer;
int num;
void Initialize() {
	num = getInteger("Enter the No Of Employees");
	allCustomer = new Customer[num];
}

string getMenu() {
	string menu = "~~~~~~~~~~~~~~~~EMPLOYEE MONITORING SYSTEM~~~~~~~\n";
	menu += "TO ADD NEW CUSTOMER-------->PRESS 1\n";
	menu += "TO SEARCH CUSTOMER--------->PRESS 2\n";
	menu += "TO DELETE CUSTOMER--------->PRESS 3\n";
	menu += "TO DISPLAY ALL CUSTOMER------------->PRESS 4\n";
	menu += "PS: ANY OTHER KEY IS CONSIDERED AS EXIT................";
	return menu;

}



void addNewCustomer(Customer cus) {
	for (int i = 0; i < num; i++) {
		if (allCustomer[i].getName() == "") {
			allCustomer[i].setDetails(cus.getID(), cus.getName(), cus.getAddress(), cus.getphone() , cus.getbillammount());
			return;
		}
	}
}

void deleteCustomer(int id) {
	for (int i = 0; i < num; i++) {
		if (allCustomer[i].getID() == id) {
			allCustomer[i].setDetails(0,"","",0,0);
			return;
		}
	}
}

void displayallCustomer() {

	for (int i = 0; i < num; i++) {
		if (allCustomer[i].getName() != "")
		{
			string msg =  allCustomer[i].getName() + allCustomer[i].getAddress() + allCustomer[i].getAddress() ;
			cout << msg << endl;
		}
	}

}void creatingCustomer() {
	Customer Cus;
	int id = getInteger("Enter the ID");
	string name = getString("Enter the Name");
	string address = getString("Enter the Address");
	int phone = getInteger("Enter the phoneNumber");
	int billAmmount = getInteger("Enter the billAmmount");
	Cus.setDetails(id, name, address, billAmmount, phone);
	addNewCustomer(Cus);

}

void deletingCustomer() {
	int empId = getInteger("Enter the ID of the Employee to delete");
	deleteCustomer(empId);

}

bool processMenu(int choice) {
	switch (choice) {
	case 1:
		creatingCustomer();
		return true;
		case 2:
		deletingCustomer();
		return true;
	case 3:
		displayallCustomer();
		return true;
	default:
		return false;
	}
}
int main() {
	string menu = getMenu();
	Initialize();
	bool processing = true;
	do {
		int choice = getInteger(menu);
		processing = processMenu(choice);
	} while (processing);

}

