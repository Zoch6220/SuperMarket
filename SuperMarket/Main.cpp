#include "Main.h"



int main() {
	srand(time(NULL));
	catalogue=setData();
	do
	{
		menu();
		choix = UtilityMethod::lireEntier();

		switch (choix)
		{
		case 1:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			warehouse.buyCatalogue(catalogue);
			break;
		case 2:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			warehouse.sellInventory();
			break;
		case 3:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			warehouse.print();
			system("pause");
			break;
		case 4:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			warehouse.displayStatistics();
			system("pause");
			break;
		case 5:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			warehouse.payEmployees();
			cout << "The employée have been pay" << endl;
			cout << "The total amount of money paid is: $" <<fixed<<setprecision(2)<< warehouse.getSalary() << endl;
			system("pause");
			break;
		case 6:
			system("CLS");
			UtilityMethod::getSystemDate();
			UtilityMethod::getSystemTime();
			cout << endl;
			cout << "Enter the name of the file: ";
			cin >> name;
			UtilityMethod::writeFileInventory(name, inv);
			
			break;
		case 7:
			cout << "Au revoir!";
			continuer = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (continuer);
	for(int i=0;i<6;i++)
		delete catalogueFournisseur[i];
	return 0;
}

Catalogue setData()
{
	//initialise les donnes automatiquement a partir d'un document txt formater
	//j'ai fait cela pour automatisé le prossesu et aussi apprendre la lecture et l'ecriture de fichier en c++ 
	for (int i = 0; i < 6; i++) {
		catalogueFournisseur[i] = new ItemCatalogue();
	}
	UtilityMethod::readFileCatalogue("catalogue.txt", catalogueFournisseur);
	Catalogue catalogue("Porier Farm", "Vegetable", catalogueFournisseur);
	UtilityMethod::readFileInventory("Inventory.txt", inv);
	for (auto& i : inv) {
		i.createId();
		
	}
	inventory.setInventory(inv);
	return catalogue;

}
void menu() {
	system("CLS");
	UtilityMethod::getSystemDate();
	UtilityMethod::getSystemTime();
	cout << " ----------------------------" << endl;
	cout << "| Welcome to the SuperMarket |" << endl;
	cout << " ----------------------------" << endl;
	cout << "1. Buy an item from Catalogue" << endl;
	cout << "2. Sell an item" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Display statistique" << endl;
	cout << "5. Pay Employee" << endl;
	cout << "6. Save an copy of the inventory" << endl;
	cout << "7. Exit" << endl;

}