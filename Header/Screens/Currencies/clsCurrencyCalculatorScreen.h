#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
//#include "clsUtil.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }
    static void _PrintCurrency(clsCurrency Cr,string FromOrTo)
    {
        cout << "\n"<<FromOrTo;
        cout << "\n___________________";
        cout << "\nCountry     : " << Cr.Country();
        cout << "\nCode        : " << Cr.CurrencyCode();
        cout << "\nName        : " << Cr.CurrencyName();
        cout << "\nRate (1$)   : " << Cr.Rate();
        cout << "\n___________________\n";
    }

    static void _CurrencyCalculator()
    {
        _DrawScreenHeader("\t  Currency Calculator Screen");

        
        clsCurrency CurrFrom = _GetCurrency("\nPlease Enter Currency1 Code : ");

        clsCurrency CurrTo = _GetCurrency("\nPlease Enter Currency2 Code : ");

        float Amount = _ReadAmount();

        if (CurrFrom.CurrencyCode() == "USD" || CurrTo.CurrencyCode() == "USD")
        {
            if (CurrFrom.CurrencyCode() == "USD")
            {
                _PrintCurrency(CurrTo, "Convert To:");
                cout << endl << Amount << " USD " << " = " << clsCurrency::ExchangeDollarTo(CurrTo, Amount) << " " << CurrTo.CurrencyCode();
            }
            else
            {
                _PrintCurrency(CurrFrom, "Convert From:");
                cout << endl << Amount << " " << CurrFrom.CurrencyCode() << " = " << clsCurrency::ExchangeFromToDollar(CurrFrom, Amount) << " " << "USD";
            }
        }
        else
        {
            _PrintCurrency(CurrFrom, "Convert From:");
            float USD = clsCurrency::ExchangeFromToDollar(CurrFrom, Amount);
            cout << endl << Amount << " " << CurrFrom.CurrencyCode() << " = " << USD << " " << "USD";
            cout << endl << "\nConverting From Dollar To " << endl;
            _PrintCurrency(CurrTo, "Convert To:");
            cout << endl << USD << " USD " << " = " << clsCurrency::ExchangeDollarTo(CurrTo, USD) << " " << CurrTo.CurrencyCode();
        }
    }
public :
    static void ShowCurrencyCalculatorScreen()
    {
        clsUtil::enWant DoAgain;
        do
        {
            system("cls");
            _CurrencyCalculator();
            DoAgain = clsUtil::DoYouWant("\n\nDo You Want To Preform Another Calculation ? y/n : ");

        } while (DoAgain == clsUtil::enWant::Yes);
    }

};

