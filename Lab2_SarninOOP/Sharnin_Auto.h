#pragma once
#include "pch.h"



class Sharnin_Auto: public CObject
{
public:
    DECLARE_SERIAL(Sharnin_Auto)
    Sharnin_Auto();
    ~Sharnin_Auto();
    virtual void ReadAutos();
    virtual void PrintAutos();
    CString Model;
    CString Colour;
    int MotorOutput;
    float EngineCapacity;
    int Price;
    virtual void Serialize(CArchive& ar);

};

