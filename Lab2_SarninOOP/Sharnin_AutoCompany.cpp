#include "pch.h"
#include "Sharnin_Auto.h"
#include "Sharnin_AutoCompany.h"
#include <vector>
void Sharnin_AutoCompany::AddAuto(shared_ptr<Sharnin_Auto> Auto)
{
	Company.push_back(Auto);
}

void Sharnin_AutoCompany ::PrintAutos()
{
	if (Company.empty()) 
	{
		cout << "Company is empty." << endl;
		return;
	}
	else
	{
		for (auto sptr : Company) 
		{
			sptr->PrintAutos();
		}
	}
	
}


void Sharnin_AutoCompany::WriteAutosToFile()
{
	if (Company.size() != 0) {
		string filename;
		CString name_of_file;
		cout << "Enter the name of file: ";
		cin.ignore();
		getline(cin, filename);
		name_of_file = filename.c_str();
		CFile f(name_of_file, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&f, CArchive::store);
		ar << Company.size();
		for (auto &st : Company) {
			ar << st.get();
		}
		Company.clear();
	}
	else cout << "There aren't any added autos" << endl;
}

void Sharnin_AutoCompany::ReadAutosFromFile()
{
	string filename;
	CString name_of_file;
	cout << "Enter the name of file: ";
	cin.ignore();
	getline(cin, filename);
	name_of_file = filename.c_str();
	CFile f(name_of_file, CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	int n;
	ar >> n;
	for (int i = 0; i < n; ++i) 
	{
		Sharnin_Auto* p;
		ar >> p;
		shared_ptr<Sharnin_Auto> strp(p);
		Company.push_back(strp);
	}
}

void Sharnin_AutoCompany::DeleteAutos()
{
	Company.clear();
}
