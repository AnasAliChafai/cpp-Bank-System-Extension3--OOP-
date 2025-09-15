#pragma once
#include "clsScreen.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
    enum enCurrenceyExchangeMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowCurrenciesList()
    {
        clsCurrenciesList::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindUserScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrenceyExchangeMainMenu()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Main Menu...";
        system("pause>0");
        ShowCurrencyExchangeMainMenu();

    }

    static void _PerformTransactionsMenueOption(enCurrenceyExchangeMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enCurrenceyExchangeMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesList();
            _GoBackToCurrenceyExchangeMainMenu();
            break;
        }

        case enCurrenceyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenceyExchangeMainMenu();
            break;
        }

        case enCurrenceyExchangeMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrenceyExchangeMainMenu();
            break;
        }
        case enCurrenceyExchangeMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenceyExchangeMainMenu();
            break;
        }
        case enCurrenceyExchangeMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowCurrencyExchangeMainMenu()
    {
        //if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        //{
        //    return;// this will exit the function and it will not continue
        //}

        system("cls");
        _DrawScreenHeader("   Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enCurrenceyExchangeMenueOptions)ReadTransactionsMenueOption());
    }

};


