#include "pch.h"
#include "Sharnin_Auto.h"

IMPLEMENT_SERIAL(Sharnin_Auto, CObject, VERSIONABLE_SCHEMA | 0)
void Sharnin_Auto::ReadAutos()
{
	string strr;
	cout << "Type the Auto Model: ";
	cin >> strr;
	Model = strr.c_str();
	cout << "Type the Auto Colour: ";
	cin >> strr;
	Colour = strr.c_str();
	cout << "Type the Auto Motor Output (horse-power): ";
	cin >> MotorOutput;
	cout << "Type the Auto Engine Capacity (liter): ";
	cin >> EngineCapacity;
	cout << "Type the Auto Price: ";
	cin >> Price;
}

Sharnin_Auto::Sharnin_Auto()
{
	//cout<< "constr auto" << endl;
}

Sharnin_Auto::~Sharnin_Auto()
{
	//cout << "destr auto" << endl;
}

void Sharnin_Auto::PrintAutos()
{
	cout << "Model " << this->Model << " Color" << this->Colour << " Motor " << this->MotorOutput << " EngineCapacity " << this->EngineCapacity << " Price " << this->Price << endl;
}

void Sharnin_Auto::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) 
	{
		ar << Model << Colour << MotorOutput << EngineCapacity << Price;
	}
	else
	{
		ar >> Model >> Colour >> MotorOutput >> EngineCapacity >> Price;
		if (ar.GetObjectSchema() > 0) {}
	}
	
}
