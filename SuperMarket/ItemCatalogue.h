#pragma once
# include<iostream>
#include<iomanip>
using namespace std;

class ItemCatalogue
{
private:
	string id;
	string name;
	int quantity;
	double price;

public:
	ItemCatalogue();
	ItemCatalogue(string name, int quantity, double price);
	void setName(string name);
	void setId(string id);
	void setQuantity(int quantity);
	void setPrice(double price);
	string getId();
	string getName();
	int getQuantity();
	double getPrice();
	string createId();
	void print();


};

