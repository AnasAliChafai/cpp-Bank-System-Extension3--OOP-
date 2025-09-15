#pragma once
#include "clsScreen.h"
class clsDepositScreen : public clsScreen
{
public :
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

       
        clsUtil::enWant WantToDelete;
        WantToDelete = clsUtil::DoYouWant("\nAre you sure you want to perform this transaction?  ");
        if (WantToDelete == clsUtil::enWant::Yes)
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

