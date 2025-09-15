#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUtil.h"
class clsLoginScreen :protected clsScreen
{

private :
    static bool _Login()
    {
        bool LoginFaild = false;
        short countLogin = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                cout << "You Have " << countLogin << "Trail(s) To Login.\n\n";
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username,Password);

            LoginFaild = CurrentUser.IsEmpty();
            countLogin--;

        } while (LoginFaild&& (countLogin != 0) );
        
        if(countLogin!=0)
        { 
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
        }
        else
        {
            cout << "\n\nyou are locked after 3 failed trails";
            return false;
        }
    }
public :
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
        return _Login();
	}
};


