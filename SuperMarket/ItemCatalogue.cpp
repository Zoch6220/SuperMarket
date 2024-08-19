#include "ItemCatalogue.h"


ItemCatalogue::ItemCatalogue() {
	this->id = "";
	name = "";
	quantity = 0;
	price = 0;
}
ItemCatalogue::ItemCatalogue(string name, int quantity, double price) {
	this->id = "";
	this->name = name;
	this->quantity = quantity;
	this->price = price;
}
string ItemCatalogue::getId() {

	return id;
}
string ItemCatalogue::getName() {
	return name;
}

int ItemCatalogue::getQuantity() {
	return quantity;
}

double ItemCatalogue::getPrice() {
	return price;
}

void ItemCatalogue::setName(string name) {
	this->name = name;
}
void ItemCatalogue::setId(string id) {
	this->id = id;
}
void ItemCatalogue::setQuantity(int quantity) {
	this->quantity = quantity;
}

void ItemCatalogue::setPrice(double price) {
	this->price = price;
}

void ItemCatalogue:: print() {
	cout << "|" << left << setw(5) << id;
	cout<< "|" << left << setw(20) << name
		<< "|" << right << setw(10) << quantity
		<< "|" << right << setw(10) << std::fixed << setprecision(2) << price << endl;
}
