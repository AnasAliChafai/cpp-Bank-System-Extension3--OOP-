#pragma once
#include "clsScreen.h"
class LoginRegister : protected clsScreen
{
private :
    static void PrintLoginRecordLine(clsUser::stLoginRecord LoginRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRecord.DateAndTime;
        cout << "| " << setw(15) << left << LoginRecord.UserName;
        cout << "| " << setw(15) << left << LoginRecord.Password;
        cout << "| " << setw(15) << left << LoginRecord.Permissions;
    }
public :
	static void ShowLoginRegister()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;// this will exit the function and it will not continue
		}
        vector <clsUser::stLoginRecord> vLogin;
        vLogin = clsUser::GetLoginList();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLogin.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permmissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        
        for (clsUser::stLoginRecord LoginRecord : vLogin)
        {

            PrintLoginRecordLine(LoginRecord);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

