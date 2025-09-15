#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen: public clsScreen
{
public :
    static void ShowUpdateClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t   Update Client Scren");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        clsUtil::enWant WantToUpdate;
        WantToUpdate = clsUtil::DoYouWant("Are You Sure You Want To Delete This Client ? y/n : ");
        if (WantToUpdate == clsUtil::enWant::Yes)
        {
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        clsScreen::_ReadClientInfo(Client1);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            clsScreen::_PrintClient(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }
    }
};

