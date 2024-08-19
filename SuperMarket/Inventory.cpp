#include "Inventory.h"


//j'ai utiliser un vector afin de pouvoir avoir un inventaire dynamic et de ne pas avoir a deternimer ca longueur
vector<Item> Inventory::inventory;

Inventory::Inventory()
{

}
Inventory::Inventory(vector<Item>& p_inv)
{
	for (auto& i : p_inv)
		inventory.push_back(i);
}
void Inventory::setInventory(vector<Item>& p_inv)
{
	inventory.clear();
	for (auto& i : p_inv)
		inventory.push_back(i);
}
vector<Item>& Inventory::getInventory()
{
	return inventory;
}

void Inventory::removeItem(int index)
{
	inventory.erase(inventory.begin() + index);
}
void Inventory::addItem(Item p_item)
{
	do {
		p_item.createId();
	} while (this->searchById(p_item.getId())!=-1);
	inventory.push_back(p_item);
}
//permet la recherche par nom
int Inventory::searchByName(string p_name)
{
	int idx = 0;
	for (auto i : inventory) {
		if (i.getName() == p_name)
			return idx;
		idx++;
	}
	return -1;
}
int Inventory::searchByPosition(int p_position)
{
	if (p_position > 0 && p_position < inventory.size())
		return p_position - 1;
	return -1;
}
//permet la recherche par ID, j'ai préféré utiliser cette methode la au lieu de la methode par index comme deuxieme methode
//recherche car cela fesait plus de sens dans le contexte de l'application
int Inventory::searchById(string p_id) {
	int idx = 0;
	for (auto i : inventory) {
		if (i.getId() == p_id)
			return idx;
		idx++;
	}

	return -1;
}
void Inventory::print()
{
	cout << "/----------------------------------------/"<<endl;
		cout << "            Inventory              " << endl;
		cout << "/----------------------------------------/" << endl;
	if (inventory.size() == 0)
		cout << "Inventory is empty" << endl;
	else{
		cout << "|" << left << setw(5) << "id";
		cout<<"|" << left << setw(20) << "Name"
			<< "|" << right << setw(10) << "Quantity"
			<< "|" << right << setw(10) << "Price"
			<< "|" <<right<< setw(14) << "Cost"
			<< "|" << right << setw(12) << "Sold"
			<< "|" << right << setw(12) << "Bought" << endl;
		for (auto i : inventory)
			i.print();
	}
}
void Inventory::setIdforOne(string p_name) {
	int index= this->searchByName(p_name);
	string p_id;
	do{
		
		inventory[index].createId();

	
	} while (searchById(p_id) != -1);
	inventory[index].setId(p_id);
}
void Inventory::clearIventory()
{
	inventory.clear();
}
