#pragma once
#include "clsScreen.h"

class clsDeleteUserScreen :protected clsScreen
{
public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        clsUtil::enWant WantToDelete;
        WantToDelete = clsUtil::DoYouWant("Are You Sure You Want To Delete This User ? y/n : ");
        if (WantToDelete == clsUtil::enWant::Yes)

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }

};
