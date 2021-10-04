#include "pch.h"
#include "Sharnin_SUV.h"
IMPLEMENT_SERIAL(Sharnin_Auto, Sharnin_SUV, VERSIONABLE_SCHEMA | 0)

void Sharnin_SUV::ReadAutos()
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
	cout << "Type the Auto drive";
	cin >> strr;
	drive = strr.c_str();
	cout << "Type the Auto engine_type";
	cin >> strr;
	engine_type = strr.c_str();
	cout << "Type the Auto Price: ";
	cin >> Price;
}

void Sharnin_SUV::PrintAutos()
{
	cout << "Model " << this->Model << " Color" << this->Colour << " Motor " << this->MotorOutput << " EngineCapacity " << this->EngineCapacity << " Price " << this->Price << " drive" << this->drive << " engine type" << this->engine_type << endl;
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
