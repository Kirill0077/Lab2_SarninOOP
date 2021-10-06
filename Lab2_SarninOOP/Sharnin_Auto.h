#pragma once
class Sharnin_Auto: public CObject
{
public:
    DECLARE_SERIAL(Sharnin_Auto);
    Sharnin_Auto();
    ~Sharnin_Auto();
    virtual void ReadAutos();
    virtual void PrintAutos();
    CString Model;
    CString Colour;
    int MotorOutput = 0;
    float EngineCapacity = 0;
    int Price = 0;
    virtual void Serialize(CArchive& ar);

};

