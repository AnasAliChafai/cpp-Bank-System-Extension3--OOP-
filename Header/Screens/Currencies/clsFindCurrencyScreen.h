#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen 
{
private :
     static short _ReadFindByCodeOrCountry()
    {
        cout << "Find By : [1] Code or [2] Country ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
        return Choice;
    }
    static void _PrintCurrency(clsCurrency Cr)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry     : " << Cr.Country();
        cout << "\nCode        : " << Cr.CurrencyCode();
        cout << "\nName        : " << Cr.CurrencyName();
        cout << "\nRate (1$)   : " << Cr.Rate();
        cout << "\n___________________\n";
    }
public :
    static void ShowFindUserScreen()
    {
        
        _DrawScreenHeader("\t  Find Currency Screen");

        enum enFind { eCode = 1, eCountry = 2 };
        enFind HowFind = enFind(_ReadFindByCodeOrCountry());
        
        switch (HowFind)
        {
        case eCode:
        {
            cout << "\nPlease Enter Currency Code : ";
            string CurrCode = clsInputValidate::ReadString();
            clsCurrency Curr = clsCurrency::FindByCode(CurrCode);
            if (!Curr.IsEmpty())
            {
                cout << "\nCurrency Found : -)\n";
                _PrintCurrency(Curr);
            }
            else
            {
                cout << "\nCurrency Not Found : -)\n";
            }
            break;
        }
           
        case eCountry:
        {
            cout << "\nPlease Enter Country Name : ";
            string CurrCountry = clsInputValidate::ReadString();
            clsCurrency Curr = clsCurrency::FindByCountry(CurrCountry);
            if (!Curr.IsEmpty())
            {
                cout << "\nCurrency Found : -)\n";
                _PrintCurrency(Curr);
            }
            else
            {
                cout << "\nCurrency Not Found : -)\n";
            }
            break;
        }
        }

    }
};

