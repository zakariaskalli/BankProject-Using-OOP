#pragma once

#include <iostream>
#include "clsString.h"
#include "clsPerson.h"
#include <fstream>
#include <vector>

using namespace std;


class clsBankClient : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;



	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRegisterRecord;


		vector <string> TransferLogRegisterDataLine = clsString::Split(Line, Seperator);

		TransferLogRegisterRecord.DateTime = TransferLogRegisterDataLine[0];
		TransferLogRegisterRecord.SourceAccountNumber = TransferLogRegisterDataLine[1];
		TransferLogRegisterRecord.DestinationAcccountNumber = TransferLogRegisterDataLine[2];
		TransferLogRegisterRecord.Amount = stoi(TransferLogRegisterDataLine[3]);
		TransferLogRegisterRecord.srcBalanceAfter = stoi(TransferLogRegisterDataLine[4]);
		TransferLogRegisterRecord.destBalanceAfter = stoi(TransferLogRegisterDataLine[5]);
		TransferLogRegisterRecord.UserName = TransferLogRegisterDataLine[6];

		return TransferLogRegisterRecord;

	}


	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

	}
	
	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.FirstName + Separator;
		stClientRecord += Client.LastName + Separator;
		stClientRecord += Client.Email + Separator;
		stClientRecord += Client.Phone + Separator;
		stClientRecord += Client._AccountNumber + Separator;
		stClientRecord += Client._PinCode + Separator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}
	
	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);

					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveClientsDataToFile(_vClients);

	}
	
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
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

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogRecord += AccountNumber() + Separator;
		TransferLogRecord += DestinationClient.AccountNumber() + Separator;
		TransferLogRecord += to_string(Amount) + Separator;
		TransferLogRecord += to_string(AccountBalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDateLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{
			MyFile << stDateLine << endl;

			MyFile.close();
		}
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAcccountNumber;
		int Amount;
		int srcBalanceAfter;
		int destBalanceAfter;
		string UserName;

	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	//Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	//Property Get
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	//Property Set
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	//Property Get
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	// Print Method Is (UI)

	/*
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nPin Code       : " << _PinCode;
		cout << "\nBalance        : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	*/

	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber)
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

		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();

	}

	enum enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2,
		svFaildAccountNumberExists = 3};

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case enMode::EmptyMode:
			{

				return enSaveResults::svFaildEmptyObject;
			}

			case enMode::UpdateMode:
			{
				_Update();

				return enSaveResults::svSucceeded;

				break;
			}
			case enMode::AddNewMode:
			{

				if (clsBankClient::IsClientExist(_AccountNumber))
				{
					return enSaveResults::svFaildAccountNumberExists;
				}
				else
				{
					_AddNew();

					_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}

			}
			default:
			{
				return enSaveResults::svFaildEmptyObject;
				break;
			}
		}

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}


		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;


	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(float Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		return true;
	}

	static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        float TotalBalances = 0;

            for (clsBankClient Client : vClients)
            {

                TotalBalances += Client.AccountBalance;
            }

            return TotalBalances;

    }

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}

	static vector <stTransferLogRecord> GetTransfersLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);
			}

			MyFile.close();
		}
		return vTransferLogRecord;
	}


};
