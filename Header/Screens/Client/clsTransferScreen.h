#pragma once
#include "clsScreen.h"
class clsTransferScreen : protected clsScreen
{
private : 
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}
	static void _Print(clsBankClient Client)
	{

		cout << "\n___________________\n";
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");
		string AccountNumber = "";

		AccountNumber = _ReadAccountNumber();

		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		_Print(ClientFrom);

		AccountNumber = _ReadAccountNumber();
		
		clsBankClient ClientTo = clsBankClient::Find(AccountNumber);
		if (ClientFrom.AccountNumber() != ClientTo.AccountNumber())
		{
		_Print(ClientTo);

		double Amount =ReadAmount(ClientFrom);
		
		
		clsUtil::enWant WantToPerform;
		WantToPerform = clsUtil::DoYouWant("\nAre You Sure You Want To Perform This Operation ? y/n : ");
		if (WantToPerform == clsUtil::enWant::Yes)
		{
			if (ClientFrom.Transfer(Amount, ClientTo,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}else
			{
				cout << "\nTransfer Faild \n";
			}
			_Print(ClientFrom);
			_Print(ClientTo);
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	    }
		else
		{
			cout << "\nYou Can't Transfer Because It Is The Same Account!\n";
		}
	}
	
};

