#include "Catalogue.h"

Catalogue::Catalogue() {
	
	this->name = "";
	this->categoriesItem = "";
	for (int i = 0; i < 6; i++)
		this->catalogueFournisseur[i] = new ItemCatalogue();
}
Catalogue::Catalogue(string p_name, string p_categoriesItem, ItemCatalogue* p_catalogueFournisseur[6])
{
	this->name = p_name;
	this->categoriesItem = p_categoriesItem;
	for(int i=0;i<6;i++)
		this->catalogueFournisseur[i] = p_catalogueFournisseur[i];
}

string Catalogue::getName() {
	return name;
}
string Catalogue::getCategoriesItem() {
	return categoriesItem;
}

ItemCatalogue** Catalogue::getCatalogueFournisseur()
{
	return catalogueFournisseur;
}



void Catalogue::setName(string p_name) {
	this->name = p_name;
}
void Catalogue::setCategoriesItem(string p_categoriesItem) {
	this->categoriesItem = p_categoriesItem;
}
int Catalogue::searchByName(string p_name) {
	for (int i = 0; i < 6; i++)
		if (Catalogue::catalogueFournisseur[i]->getName() == p_name)
			return i;
	return -1;
}
int Catalogue::searchById(string p_id) {
	int idx = 0;
	for (auto i : catalogueFournisseur) {
		if (i->getId() == p_id)
			return idx;
		idx++;
	}

	return -1;
}
int Catalogue::searchByPosition(int p_position) {
	if (p_position > 0 && p_position < 7)
		return p_position - 1;
	return -1;
};

void Catalogue::print() {
	cout << "Catalogue" << endl;
	cout << "Name: " << left<<setw(20)<<name << right<<setw(20)<<"Categories: " << categoriesItem  << endl;
	cout << "\n";
	cout << "|" << left << setw(5) << "Id";
	cout << "|" << left << setw(20) << "Name"
		<< "|" << right << setw(10) << "Quantity"
		<< "|" << right << setw(10) << "Price" << endl;
	
	for (auto i : catalogueFournisseur) {
		
		i->print();
		
	}
	cout << endl;
}
