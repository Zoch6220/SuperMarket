#include "Item.h"


Item::Item(string name, int quantity, double price, double cost, int sold, int bought) {
	id = "";
	this->name = name;
	this->quantity = quantity;
	this->price = price;
	this->cost = cost;
	this->sold = sold;
	this->bought = bought;
}

//getter

string Item:: getName() {
	return name;
}
int Item::getQuantity() {
	return quantity;
}
double Item::getPrice() {
	return price;
}
double Item::getCost() {
	return cost;
}
int Item::getSold() {
	return sold;
}
int Item::getBought() {
	return bought;
}
string Item::getId() {

	return id;
}

//setters

void Item::setName(string name) {
	this->name = name;
}
void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}
void Item::setPrice(double price) {
	this->price = price;
}
void Item::setCost(double cost) {
	this->cost = cost;
}
void Item::setSold(int sold) {
	this->sold = sold;
}
void Item::setBought(int bought) {
	this->bought = bought;
}
void Item::setId(string p_id) {
	this->id = p_id;
}

void Item::createId(){
	string idx="";
	//srand(time(NULL));
	idx = name[0];
	int randomNumber = rand() % 301;
	idx += to_string(randomNumber);
	this->id= idx;
}
void Item::print() {
	cout << "|" << left << setw(5) << id;
	cout	<< "|" << left << setw(20) << name
			<< "|" << right << setw(10) << quantity
			<< "|" << right<<setw(10) << fixed << setprecision(2)  << price
			<< "|" << right<<setw(14)<<fixed<< setprecision(2) << cost
			<< "|" << right<<setw(12) << sold
			<< "|" << right<<setw(12) << bought << endl;
}

