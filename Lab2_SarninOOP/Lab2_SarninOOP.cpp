// Lab2_SarninOOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "Lab2_SarninOOP.h"
#include "Sharnin_Auto.h"
#include "Sharnin_AutoCompany.h"
#include "Sharnin_SUV.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

//using namespace std;

void PrintMenu()
{
    cout << "1. Add Auto to AutoCompany    " << endl
         << "2. Add SUV Auto to AutoCompany" << endl
         << "3. View Autos from AutoCompany" << endl
         << "4. Save AutoCompany to File   " << endl
         << "5. Load AutoCompany from File " << endl
         << "6. Delete AutoCompany         " << endl
         << "0. Exit                       " << endl;
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
            Sharnin_AutoCompany Company_Auto;
            while (true)
            {
                PrintMenu();
                int i;
                cout << "Choose the option: ";
                cin >> i;
                switch (i)
                {
                case 1:
                {
                    shared_ptr<Sharnin_Auto> Auto = make_shared<Sharnin_Auto>();
                    Auto.get()->ReadAutos();
                    Company_Auto.AddAuto(Auto);
                    break;
                }
                case 2:
                {
                    shared_ptr<Sharnin_SUV> SUV = make_shared<Sharnin_SUV>();
                    SUV.get()->ReadAutos();
                    Company_Auto.AddAuto(SUV);
                    break;
                }
                case 3:
                {
                    Company_Auto.PrintAutos();
                    break;
                }
                case 4:
                {
                    Company_Auto.WriteAutosToFile();
                    break;
                }
                case 5:
                {
                    Company_Auto.ReadAutosFromFile();
                    break;
                }
                case 6:
                {
                    Company_Auto.DeleteAutos();
                    break;
                }
                case 0:
                {
                    return 0;
                    break;
                }
                default: cout << "Wrong action!" << endl;
                }
            }
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
