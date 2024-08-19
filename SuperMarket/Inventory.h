#pragma once
#include <vector>
#include "Item.h"
#include "Catalogue.h"
using namespace std;
class Inventory : virtual Recherche
{
private:
	static vector<Item> inventory;
public:
	Inventory();
	Inventory(vector<Item>& p_inv);
	static void setInventory(vector<Item>& p_inv);
	static vector<Item>& getInventory();
	 void addItem(Item p_item);
	static void removeItem(int index);
	void print();
	int searchByName(string p_name);
	int searchByPosition(int p_position);
	int Recherche::searchById(string p_name)override;
	static void clearIventory();
	 void setIdforOne(string p_name);
};
