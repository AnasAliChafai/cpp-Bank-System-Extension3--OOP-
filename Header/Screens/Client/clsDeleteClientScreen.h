#pragma once
#include "clsScreen.h"

class clsDeleteClientScreen : public clsScreen
{
public :
   static void ShowDeleteClient()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
       {
           return;// this will exit the function and it will not continue
       }
       _DrawScreenHeader("\tDelete Client Screen");
        cout << "please enter account number : ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        clsUtil::enWant WantToDelete;
        WantToDelete = clsUtil::DoYouWant("Are You Sure You Want To Delete This Client ? y/n : ");
        if (WantToDelete == clsUtil::enWant::Yes)
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    } 
};

