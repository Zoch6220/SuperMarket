#pragma once
#include<iostream>
class Recherche
{
public:
	//search by name in the array
	virtual int searchByName(std::string p_name) = 0;

	//search by index in the array
	virtual int searchByPosition(int p_position) = 0;
	// search by id
	virtual int searchById(string p_Id) = 0;
	virtual void print() = 0;

};


