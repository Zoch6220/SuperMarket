#include "Warehouse.h"


Warehouse::Warehouse(Inventory& p_inv) {
	inventory = p_inv;
	last_payTime = time(NULL);
	totalSale= 0;
	totalCost = 0;
	totalSpending = 0;
	profit = 0;
	salary = 0;
	totalPay = 0;
	totalItemSold = 0;
	totalItemBuy;

}
double Warehouse::getSalary() {
	return salary;
}
int Warehouse::calculateTotalItemSold() {
	int sum = 0;
	for (auto i : inventory.getInventory()) {
		sum += i.getSold();
	}
	return sum;
}
int Warehouse::calculateTotalItemBought() {
	int sum = 0;
	for (auto  i: inventory.getInventory())
		sum += i.getBought();
	return sum;
}
double Warehouse::calculateTotalCost() {
	double totalCost = 0;
	for (auto i : inventory.getInventory()) {
		totalCost += i.getCost() * i.getBought();
	}

	return totalCost;
}
double Warehouse::calculateTotalSale() {
	double totalSale = 0;
	for (auto i : inventory.getInventory()) {
		totalSale += i.getPrice() * i.getSold();
	}
	return totalSale;
}
vector<Item> Warehouse::getInventory() {
	return inventory.getInventory();
}
void Warehouse::buyCatalogue(Catalogue p_catalogue) {
	bool continuer=true;
	do {
		system("cls");
		p_catalogue.print();
		cout << "Enter the name or Id of the product you want to buy: ";
		string name = "";
		string id = "";
		cin >> name;
		int index = p_catalogue.searchByName(name);
		if(index==-1)
			index=p_catalogue.searchById(name);
		//ici on donne le nom de l'article afin de créé un doublon si l'utilisateur entre un Id
		if(index!=-1)
			name=p_catalogue.getCatalogueFournisseur()[index]->getName();
		if (index != -1)
		{
			ItemCatalogue** itemCataPtr = p_catalogue.getCatalogueFournisseur();
			ItemCatalogue* itemCata = itemCataPtr[index];
			int quantity = 0;
			do {
				cout << "Enter the quantity of the product you want to buy: ";
				quantity = UtilityMethod::lireEntier();
				if(quantity > itemCata->getQuantity())
					cout << "The quantity you want to buy is more than the quantity available" << endl;
			} while (quantity>itemCata->getQuantity());
			
			int indexInv = inventory.searchByName(name);
			if (indexInv != -1) {
				
				inventory.getInventory()[indexInv].setQuantity(inventory.getInventory()[indexInv].getQuantity() + quantity);
				inventory.getInventory()[indexInv].setBought(inventory.getInventory()[indexInv].getBought() + quantity);
				cout << "You have successfully bought the product" << endl;
			}
			else {
				double price = 0;
				cout << "What is the sell price of the new product: ";
				price=UtilityMethod::lireDouble();

				
				Item item(itemCata->getName(), quantity, price, itemCata->getPrice(), 0, quantity);
				inventory.addItem(item);
				
				cout << "You have successfully bought the product and was add to the inventory" << endl;
			}
			//ajuste les donnés des statistique et du catalogue
			itemCata->setQuantity(itemCata->getQuantity() - quantity);
			totalItemBuy += quantity;
		}
		else {
			cout << "The product you want to buy is not in the catalogue" << endl;
		}
		string choix = "";
		do {
			cout << "Do you want to buy another product? (yes/no): ";
			
			cin >> choix;
			UtilityMethod::toLowerString(choix);
			if (choix == "yes") {
				continuer = true;
				
			}
			else if (choix == "no") {
				continuer = false;
				
			}
			else {
				cout << "Invalid input" << endl;
			}
		} while (choix!="yes"&&choix!="no");
	

	} while (continuer);
	
}
void Warehouse::sellInventory() {
	bool continuer = true;
	do
	{
		inventory.print();
		cout << "Enter the name or the Id of the product you want to sell: ";
		string name = "";
		cin >> name;
		/*le string name dois passer par 2 verification pour savoir si l'utilisateur a rentrer un Id ou le nom de l'item*/
		int index = inventory.searchByName(name); 
		if(index==-1)
			index = inventory.searchById(name);
		if (index != -1) {
			int quantity = 0;
			bool sell;
			do
			{
				
				cout << "Enter the quantity of the product you want to sell: ";
				quantity = UtilityMethod::lireEntier();

				if (inventory.getInventory()[index].getQuantity() >= quantity) {
					inventory.getInventory()[index].setQuantity(inventory.getInventory()[index].getQuantity() - quantity);
					inventory.getInventory()[index].setSold(inventory.getInventory()[index].getSold() + quantity);
					totalItemSold += quantity;
					cout << "You have successfully sold the product" << endl;
					sell = true;
				}
				else {
					cout << "You don't have enough quantity to sell" << endl;
					sell = false;
				}
			} while (!sell);
		}
		else {
			cout << "The product you want to sell is not in the inventory" << endl;
		}
		string choix = "";
		do {
			cout << "Do you want to sell another product? (yes/no): ";

			cin >> choix;
			UtilityMethod::toLowerString(choix);
			if (choix == "yes") {
				continuer = true;

			}
			else if (choix == "no") {
				continuer = false;

			}
			else {
				cout << "Invalid input" << endl;
			}
		} while (choix != "yes" && choix != "no");
	} while (continuer);
	
}
void Warehouse::updateStatistique() {

	totalCost= calculateTotalCost();
	totalSale = calculateTotalSale();
	totalSpending=salary+totalCost;
	profit = totalSale - totalSpending;
	totalItemBuy = calculateTotalItemBought();
	totalItemSold = calculateTotalItemSold();
	
	
}
void Warehouse::displayStatistics() {
	this->updateStatistique();
	cout << "Statistic:" << endl;
	cout << "Total item Buy: " << totalItemBuy << endl;
	cout << "Total item Sold: " << totalItemSold << endl;
	cout << "Total Cost of all item bought: " << totalCost << "$" << endl;
	cout << "Total of the salary pay: " << totalPay << "$" << endl;
	cout << "Total Spending: " << totalSpending << "$" << endl;
	cout << "Total Sale of all item sold: " << "$" << totalSale << endl;
	cout << "Profit: " << profit << endl;

}
void Warehouse::payEmployees() {
	time_t currentTime = time(NULL);
	double timeDiff = difftime(currentTime, last_payTime);
	salary = (timeDiff/60)*2600;
	totalPay += salary;
	last_payTime = currentTime;
}
void Warehouse::print()
{
	inventory.print();
}

