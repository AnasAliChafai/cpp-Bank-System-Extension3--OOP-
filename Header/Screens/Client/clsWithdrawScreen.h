#pragma once
#include "clsScreen.h"
class clsWithdrawScreen : public clsScreen
{
public :
	static void ShowWithdrawScreen()
	{
        _DrawScreenHeader("\t   Withdraw Screen");

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
        cout << "\nPlease enter withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        clsUtil::enWant WantToDelete;
        WantToDelete = clsUtil::DoYouWant("\nAre you sure you want to perform this transaction?  ");
        if (WantToDelete == clsUtil::enWant::Yes)
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}
};

