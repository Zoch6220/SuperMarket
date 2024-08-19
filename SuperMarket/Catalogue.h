#pragma once
#include"ItemCatalogue.h"
#include "Recherche.h"
class Catalogue : public Recherche
{
private:
	string name;
	string categoriesItem;
	//ici j'ai utilliser un array car nous savions que la grandeur maximale, mais j'aurais pu utiliser un vector et ajouter une variable compteur
	// mais je voulais expérimenter avec les array et aussi m'habituer  avec les pointeurs 
	ItemCatalogue* catalogueFournisseur[6];

public:
	Catalogue();
	Catalogue(string p_name, string p_categoriesItem, ItemCatalogue* p_catalogueFournisseur[6]);
	void setName(string p_name);
	void setCategoriesItem(string p_categoriesItem);
	int Recherche::searchByName(string p_name) override;
	int Recherche::searchByPosition(int p_position) override;
	int Recherche::searchById(string p_name) override;
	string getName();
	
	string getCategoriesItem();
	ItemCatalogue** getCatalogueFournisseur();



	void Recherche::print();
};

