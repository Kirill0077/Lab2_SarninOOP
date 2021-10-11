#include "pch.h"
#include "Sharnin_SUV.h"
#include "Sharnin_utils.h"
IMPLEMENT_SERIAL(Sharnin_SUV, Sharnin_Auto, VERSIONABLE_SCHEMA | 0)


void Sharnin_SUV::ReadAutos()
{
	cout << "Type the Auto Model: ";
	cin >> Model;
	cout << "Type the Auto Colour: ";
	cin >> Colour;
	cout << "Type the Auto Motor Output (horse-power): ";
	cin >> MotorOutput;
	cout << "Type the Auto Engine Capacity (liter): ";
	cin >> EngineCapacity;
	cout << "Type the Auto drive: ";
	cin >> drive;
	cout << "Type the Auto engine_type: ";
	cin >> engine_type;
	cout << "Type the Auto Price: ";
	cin >> Price;
}

void Sharnin_SUV::PrintAutos()
{
	cout << "Model " << Model << endl;
	cout << " Color" << Colour << endl;
	cout << " Motor " << MotorOutput << endl;
	cout << " EngineCapacity " << EngineCapacity << endl;
	cout << " drive " << drive << endl;
	cout << " engine type " << engine_type << endl;
	cout << " Price " << Price << endl;
	cout << "++++++++++++++++++++++++++" << endl;
}

Sharnin_SUV::Sharnin_SUV()
{
	//cout << "constr SUV" <<endl;
}

Sharnin_SUV::~Sharnin_SUV()
{
	//cout << "deconstr SUV" << endl;
}

void Sharnin_SUV::Serialize(CArchive& ar)
{
	Sharnin_Auto::Serialize(ar);
	if (ar.IsStoring()) {
		ar << drive;
		ar << engine_type;
	}
	else {
		ar >> drive;
		ar >> engine_type;
		if (ar.GetObjectSchema() > 0){}
	}
}
