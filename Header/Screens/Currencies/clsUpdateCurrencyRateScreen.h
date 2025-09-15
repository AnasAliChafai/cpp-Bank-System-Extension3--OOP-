#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

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

    static float _ReadNewRate()
    {
        cout << "\n\nUpdate Currency Rate :";
        cout << "\n______________________\n";
        cout << "\nEnter New Rate : ";
        short NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }
public:
    
    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\t  Update Currency Screen");

        cout << "Please Enter Currency Code : ";
        string CurrCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrCode = clsInputValidate::ReadString();
        }

        clsCurrency Curr = clsCurrency::FindByCode(CurrCode);

        _PrintCurrency(Curr);
        clsUtil::enWant WantToUpdate;
        WantToUpdate = clsUtil::DoYouWant("\nAre You Sure You Want To Update The Rate Of This Currency ? y/n : ");
        if (WantToUpdate == clsUtil::enWant::Yes)
        {
            Curr.UpdateRate(_ReadNewRate());
        }
         

        cout << "\nCurrency Rate Updated Successfully :-)\n";
        _PrintCurrency(Curr);
      
    }
};

