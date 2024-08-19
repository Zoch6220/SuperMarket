#include "UtilityMethod.h"
using namespace std;
/*les deux methodes permet de lire des nombre et de faire la gestion des exeptions*/
int UtilityMethod::lireEntier()
{
	int entier;
	cin >> entier;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid number: ";
		cin >> entier;
	}
	return entier;
}
double UtilityMethod::lireDouble()
{
	double reel;
	cin >> reel;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid number: ";
		cin >> reel;
	}
	return reel;
}
/*Methode qui permet de separer les ligne du fichier txt en string*/
vector<string> UtilityMethod::split(string p_string, char p_delimiter, vector<string> p_vector)
{
	string temp="";
	for (int i = 0; i < p_string.length(); i++)
	{
		if (p_string[i] != p_delimiter)
			temp += p_string[i];
		else
		{
			p_vector.push_back(temp);
			temp = "";
		}
	}
	return p_vector;
	
}

string UtilityMethod::toLowerString(string p_string)
{
	for (int i = 0; i < p_string.length(); i++)
		p_string[i] = tolower(p_string[i]);
	return p_string;
}
void UtilityMethod::readFileCatalogue(string p_nameFile, ItemCatalogue* p_catalogue[]) {
	ifstream newFile;
	newFile.open(p_nameFile,ios::in);
	if (newFile.is_open())
	{
		vector<string> temp;
		string line;
		string name;
		string categoriesItem;
		string nameItem;
		string id;
		int quantity;
		double price;
		int i = 0;
		


		while (i<6)
		{
			getline(newFile, line);
			temp = split(line, ';', temp);

			
				nameItem = temp[0];
				quantity = stoi(temp[1]);
				price = stod(temp[2]);
				id=temp[3];	
				p_catalogue[i]->setId(id);
				p_catalogue[i]->setName(nameItem);
				p_catalogue[i]->setQuantity(quantity);
				p_catalogue[i]->setPrice(price);
				i++;
			
				temp.clear();
				
		}
		newFile.close();
	}
	else
		cout << "Unable to open file";
}
void UtilityMethod::readFileInventory(string p_nameFile, vector<Item>& p_inv) {
	ifstream newFile;
	newFile.open(p_nameFile, ios::in);
	if (newFile.is_open())
	{
		vector<string> temp;
		string line;
		string nameItem;
		int quantity;
		double price;
		double cost;
		int sold;
		int bought;
		
		
		while (getline(newFile, line))
		{
			if (line.empty())
				break;
			temp = split(line, ';', temp);


			nameItem = temp[0];
			quantity = stoi(temp[1]);
			price = stod(temp[2]);
			cost = stod(temp[3]);
			sold = stoi(temp[4]);
			bought = stoi(temp[5]);
			Item item(nameItem, quantity, price, cost, sold, bought);
			p_inv.push_back(item);
			
			
			temp.clear();

		}
		newFile.close();
	}
	else
		cout << "Unable to open file";
}
void UtilityMethod::writeFileInventory(string p_nameFile, vector<Item>& p_inv) {
	p_nameFile += ".txt";
	ofstream newFile;
	newFile.open(p_nameFile, ios::out);
	if (newFile.is_open())
	{
		for (int i = 0; i < p_inv.size(); i++)
		{
			newFile << p_inv[i].getName() << ";" << p_inv[i].getQuantity() << ";" << p_inv[i].getPrice() << ";" << p_inv[i].getCost() << ";" << p_inv[i].getSold() << ";" << p_inv[i].getBought() <<";" << endl;
		}
		newFile.close();
	}
	else
		cout << "Unable to open file";
}
void UtilityMethod::getSystemDate() {
auto now=chrono::system_clock::now();
time_t currentTime=chrono::system_clock::to_time_t(now);
tm localtime;
localtime_s(&localtime,&currentTime);
cout << "Date: " << localtime.tm_mday << "/" << localtime.tm_mon + 1 << "/" << (localtime.tm_year%100) << endl;
}
void UtilityMethod::getSystemTime() {
	auto now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	tm localtime;
	localtime_s(&localtime, &currentTime);
	cout << "Clock: " << localtime.tm_hour << ":" << localtime.tm_min << endl;
}