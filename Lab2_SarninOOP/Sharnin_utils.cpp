#include "Sharnin_utils.h"
#include "pch.h"
#include "Sharnin_Auto.h"
#include "Sharnin_SUV.h"
CArchive& operator << (CArchive& ar, string& s)
{
	ar << CString(s.c_str());
	return ar;
}

CArchive& operator >> (CArchive& ar, string& s)
{
	CString tmp;
	ar >> tmp;
	s = tmp;
	return ar;
}