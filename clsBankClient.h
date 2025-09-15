#pragma once

#include "clsPerson.h"
#include "clsUser.h"


class clsBankClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;
	 
	struct stTransfer;
	static stTransfer _ConvertLinetoLoginRecord(string Line, string Seperator = "#//#")
	{
		vector<string> vTransferData;
		vTransferData = clsString::Split(Line, Seperator);
		stTransfer TransferRecord;
		TransferRecord.SystemDate = vTransferData[0];
		TransferRecord.sAcc = vTransferData[1];
		TransferRecord.dAcc = vTransferData[2];
		TransferRecord.Amount = stoi(vTransferData[3]);
		TransferRecord.sBalance = stoi(vTransferData[4]);
		TransferRecord.dBalance = stoi(vTransferData[5]);
		TransferRecord.UserName = vTransferData[6];
		return TransferRecord;
	}

	static  vector <stTransfer> _LoadTransferDataFromFile()
	{

		vector <stTransfer> vTransfer;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				stTransfer TransferRecord = _ConvertLinetoLoginRecord(Line);

				vTransfer.push_back(TransferRecord);
			}

			MyFile.close();

		}

		return vTransfer;

	}
	 
	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}
	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode
		vector <clsBankClient> vClients;
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); //write mode
		string Line;
		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;

				}

			}
			MyFile.close();
		}
		
	}
	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients); 
	}
	void _AddNew()
	{

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareLogInRecord(float Amount, clsBankClient DestinationClient,string CurrUserName, string Seperator = "#//#")
	{
		string TransferLog = "";
		TransferLog += clsDate::GetSystemDateAndTime() + Seperator;
		TransferLog += _AccountNumber + Seperator;
		TransferLog += DestinationClient.AccountNumber() + Seperator;
		TransferLog += to_string(Amount) + Seperator;
		TransferLog += to_string(_AccountBalance) + Seperator;
		TransferLog += to_string(DestinationClient._AccountBalance) + Seperator;
		TransferLog += CurrUserName;
		return TransferLog;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient,string CurrUserName, string Seperator = "#//#")
	{
		string stDataLine = _PrepareLogInRecord(Amount, DestinationClient,CurrUserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}
public:
	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	 bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); 
		string Line;
		if (MyFile.is_open())
		{
		while (getline(MyFile,Line))
		{
			clsBankClient Client = _ConvertLinetoClientObject(Line);
			if (Client.AccountNumber() == AccountNumber)
			{
				MyFile.close();
				return Client;
			}
		}
		MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}
	}
	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;

	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		} 
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient , string CurrUserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient,CurrUserName);
		return true;
	}
	struct stTransfer 
	{
		string SystemDate;
		string sAcc;
		string dAcc;
		float Amount;
		float sBalance;
		float dBalance;
		string UserName;
	};
	static vector <stTransfer> GetTransferLogList()
	{
		return _LoadTransferDataFromFile();
	}
};
 
