#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate : "; clsDate::Print(clsDate::GetSystemDate()); cout << endl;
    }
   static  void _ReadClientInfo(clsBankClient& Client)
    {
        string StringInput;
        float FloatInput;

        cout << "\nEnter FirstName: ";
        StringInput = clsInputValidate::ReadString();
        if (StringInput != "-99")  Client.FirstName = StringInput;

        cout << "\nEnter LastName: ";
        StringInput = clsInputValidate::ReadString();
        if (StringInput != "-99")  Client.LastName = StringInput;
       

        cout << "\nEnter Email: ";
        StringInput = clsInputValidate::ReadString();
        if (StringInput != "-99")  Client.Email = StringInput;
        
        cout << "\nEnter Phone: ";
        StringInput = clsInputValidate::ReadString();
        if (StringInput != "-99")  Client.Phone = StringInput;

        cout << "\nEnter PinCode: ";
        StringInput = clsInputValidate::ReadString();
        if (StringInput != "-99")  Client.PinCode = StringInput;

        cout << "\nEnter Account Balance: ";
        FloatInput = clsInputValidate::ReadFloatNumber();
        if (FloatInput != -99)  Client.AccountBalance = FloatInput;
    }
   
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\n___________________\n";
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';

       
        if (clsInputValidate::DoYouWantToAddThisPerm("\nDo you want to give full access? y/n? "))
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        if (clsInputValidate::DoYouWantToAddThisPerm("\nShow Client List? y/n? "))
        {

            Permissions += clsUser::enPermissions::pListClients;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nAdd New Client? y/n? "))
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nDelete Client? y/n? "))
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nUpdate Client? y/n? "))
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }
       
        if (clsInputValidate::DoYouWantToAddThisPerm("\nFind Client? y/n? "))
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nTransactions? y/n? "))
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nManage Users? y/n? "))
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        if (clsInputValidate::DoYouWantToAddThisPerm("\nLogin Register? y/n? "))
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;

    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};
