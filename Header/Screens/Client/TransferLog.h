#pragma once
#include "clsScreen.h"
class TransferLog : protected clsScreen
{
private:
    static void PrintTransferRecordLine(clsBankClient::stTransfer TransferRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRecord.SystemDate;
        cout << "| " << setw(8) << left << TransferRecord.sAcc;
        cout << "| " << setw(8) << left << TransferRecord.dAcc;
        cout << "| " << setw(8) << left << TransferRecord.Amount;
        cout << "| " << setw(12) << left << TransferRecord.sBalance;
        cout << "| " << setw(12) << left << TransferRecord.dBalance;
        cout << "| " << setw(8) << left << TransferRecord.UserName;
    }
public:
    static void ShowTransferLogRegister()
    {
        
        vector <clsBankClient::stTransfer> vTransfer;
        vTransfer = clsBankClient::GetTransferLogList();
        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransfer.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acc";
        cout << "| " << left << setw(8) << "d.Acc";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransfer.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else
        for (clsBankClient::stTransfer TransferLogRecord : vTransfer)
        {

            PrintTransferRecordLine(TransferLogRecord);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

