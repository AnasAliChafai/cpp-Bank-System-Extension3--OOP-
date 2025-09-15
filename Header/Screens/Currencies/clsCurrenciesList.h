#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrenciesList : protected clsScreen
{
private :
    static void PrintCurrencyRecordLine(clsCurrency Cr)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << Cr.Country();
        cout << "| " << setw(6) << left << Cr.CurrencyCode();
        cout << "| " << setw(40) << left << Cr.CurrencyName();
        cout << "| " << setw(8) << left << Cr.Rate();

    }
public :
    static void ShowCurrenciesList()
    {
        vector <clsCurrency> vCr;
        vCr = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCr.size()) + ") Currency.";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(6) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(8) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vCr.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency C : vCr)
            {

                PrintCurrencyRecordLine(C);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }
};

