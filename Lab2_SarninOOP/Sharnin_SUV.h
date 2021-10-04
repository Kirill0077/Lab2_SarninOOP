#pragma once
#include "pch.h"
#include "Sharnin_Auto.h"

class Sharnin_SUV :
    public Sharnin_Auto
{
public:
    DECLARE_SERIAL(Sharnin_SUV);
    CString drive;
    CString engine_type;   
    Sharnin_SUV();
    ~Sharnin_SUV();
    void PrintAutos();
    void ReadAutos();
    virtual void Serialize(CArchive& ar);
};

