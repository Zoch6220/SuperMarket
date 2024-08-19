#pragma once
#include "Inventory.h"
#include "Catalogue.h"
#include"UtilityMethod.h"
#include<ctime>
class Warehouse
{
private:
	double totalSpending;
	double totalSale;
	double profit;
	double salary;
	double totalCost;
	Inventory inventory;
	time_t last_payTime;
	int totalItemBuy;
	int totalItemSold;
	double totalPay;
public:
	Warehouse(Inventory& p_inv);
	double getSalary();
	double calculateTotalCost();
	double calculateTotalSale();
	int calculateTotalItemSold();
	int calculateTotalItemBought();
	vector<Item> getInventory();
	void buyCatalogue(Catalogue p_catalogue);
	void sellInventory();

	void updateStatistique();
	void displayStatistics();
	void payEmployees();
	void print();
};

