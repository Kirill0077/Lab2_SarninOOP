#pragma once
#include "pch.h"
#include "Sharnin_Auto.h"
class Sharnin_AutoCompany
{
public:
	vector <shared_ptr<Sharnin_Auto>> Company;
	void AddAuto(shared_ptr<Sharnin_Auto> sptr);
	void PrintAutos();
	virtual void WriteAutosToFile();
	virtual void ReadAutosFromFile();
	void DeleteAutos();
};

