#pragma once
#include<iostream>
#include "Item.h"
#include "Recherche.h"
#include "Catalogue.h"
#include "ItemCatalogue.h"
#include "Inventory.h"
#include "Warehouse.h"
#include <stdlib.h>


	vector<Item> inv;
	ItemCatalogue* catalogueFournisseur[6];
	Inventory inventory;
	Warehouse warehouse(inventory);
	bool continuer = true;
	int choix;
	string name;
	Catalogue catalogue;

	static Catalogue setData();
	static void menu();


