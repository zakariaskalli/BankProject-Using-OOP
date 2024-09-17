#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber(string TextFromOrTo = "From")
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer " << TextFromOrTo << ": ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate<float>::ReadNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate<float>::ReadNumber();

		}
		return Amount;
	}


public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));

		_PrintClient(DestinationClient);


		float Amount = ReadAmount(SourceClient);

		cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done Successfully.\n";
			}
			else
			{
				cout << "\nTransfer Fail \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}



};

