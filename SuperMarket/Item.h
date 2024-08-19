#pragma once
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class Item
{

private:
	string id;
	string name;
	int quantity;
	double price;
	double cost;
	int sold;
	int bought;
public:
	//constructor for the object item

	Item(string name, int quantity, double price, double cost, int sold, int bought);

	//setters and getters for the object item
	void setName(string name);
	void setQuantity(int quantity);
	void setPrice(double price);
	void setCost(double cost);
	void setSold(int sold);
	void setBought(int bought);
	void setId(string p_id);
	string getId();
	string getName();
	int getQuantity();
	double getPrice();
	double getCost();
	int getSold();
	int getBought();
	//print function for the object item
	void print();
	void createId();

};

