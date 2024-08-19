#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include "Catalogue.h"
#include "Item.h"
using namespace std;
class UtilityMethod
{
	/*J'ai cree cette class afin de separer mes différentes methode que j'ai utilsé durant tous le travail et pour ne par surcharcher le main*/
public:
	static int lireEntier();
	static	double lireDouble();
	static string toLowerString(string p_string);
	static vector<string> split(string p_string, char p_delimiter, vector<string> p_vector);
	static void readFileCatalogue(string p_nameFile,ItemCatalogue* p_catalogue[]);
	static void readFileInventory(string p_nameFile, vector<Item>& p_inv);
	static void writeFileInventory(string p_nameFile, vector<Item>& p_inv);
	static void getSystemDate();
	static void getSystemTime();
};

