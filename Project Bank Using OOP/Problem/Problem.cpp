
#include <iostream>
#include "clsLoginScreen.h"
#include <iomanip>

using namespace std;

// Update Client

/*

void ReadClientInfo(clsBankClient & Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void UpdateClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();

	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n____________________\n";

	ReadClientInfo(Client1);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = Client1.Save();

	switch (SaveResult)
	{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			Client1.Print();
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
	}

}

*/

// Add New

/*

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void AddNewClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();

	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Add Successfully :-)\n";
			NewClient.Print();
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
	}

}

*/

// Delete Client

/*

void DeleteClient()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\nAre you sure you want to delete this client y/n? ";

	char Answer = 'n';
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{

		if (Client1.Delete())
		{
			cout << "Client Deleted Successfully :-)\n";
			Client1.Print();
		}
		else
		{
			cout << "Error Client Was not Deleted :-)\n";
		}
	}
}

*/

// List Clients

/*

void PrintClientRecordLine(clsBankClient Client)
{
	cout << " | " << left << setw(15) << Client.AccountNumber();
	cout << " | " << left << setw(20) << Client.FullName();
	cout << " | " << left << setw(12) << Client.Phone;
	cout << " | " << left << setw(20) << Client.Email;
	cout << " | " << left << setw(10) << Client.Phone;
	cout << " | " << left << setw(12) << Client.AccountBalance;
}

void ShowClientsList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "______________________________________________\n" << endl;

	cout << " | " << left << setw(15) << "Account Number";
	cout << " | " << left << setw(20) << "Client Name";
	cout << " | " << left << setw(12) << "Phone";
	cout << " | " << left << setw(20) << "Email";
	cout << " | " << left << setw(10) << "Pin Code";
	cout << " | " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "______________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
		for (clsBankClient& Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
	cout << "\n____________________________________________________________________";
	cout << "_________________________________\n\n";
	
}

*/

// Total Balances

/*

void PrintClientRecordBalanceLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.AccountNumber();
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowTotalBalances()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}

*/





int main()
{
	// Project 1: Utility Library

	/*
	
		clsUtil::Srand();

		cout << clsUtil::RandomNumber(1, 10) << endl;
		cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << endl;
	
		clsUtil::Generatorkeys(10);


		int ArrNum[5];

		clsUtil::FillArrayWithRandomNumbers(ArrNum, 5, 20, 50);

		cout << "Random Numbers: " << endl;

		for (int i =0; i < 5; i++)
		{
			cout << ArrNum[i] << endl;
		}

		cout << "\n\n";

		string ArrWord[5];

		clsUtil::FillArrayWithRandomWords(ArrWord, 5, clsUtil::MixChars, 8);

		cout << "Random Words: " << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << ArrWord[i] << endl;
		}


		cout << "\n\n";

		string ArrKey[5];

		clsUtil::FillArrayWithRandomKeys(ArrKey, 5, clsUtil::MixChars);

		cout << "Random Keys: " << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << ArrKey[i] << endl;
		}


		int Arr5[10] = {10,20,30,40,50,60,70,80,90,100};

		clsUtil::ShuffleArray(Arr5, 10);


		cout << "Shuffle Numbers : " << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << Arr5[i] << endl;
		}
	
	*/


	// Project 2:  Input and Validation Library

	/*

	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(5.3, 1.8, 10.5) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(),
										clsDate(8, 12, 2023),
										clsDate(5, 1, 2024)) << endl;
	
	cout << clsInputValidate::IsDateBetween(clsDate(),
										clsDate(5, 1, 2024),
										clsDate(8, 12, 2023)) << endl;


	cout << "\nPlease Enter a Number:\n";
	int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
	cout << "x=" << x;
	
	cout << "\nPlease Enter a Number Between 1 and 5:\n";
	int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again: ");
	cout << "y=" << y;
	
	cout << "\nPlease Enter a Number:\n";
	double a = clsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
	cout << "a=" << a;

	cout << "\nPlease Enter a Number Between 1 and 5:\n";
	double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again: ");
	cout << "b=" << b;

	cout << endl << clsInputValidate::IsValideDate(clsDate(37, 5, 2022));

	*/


	// Project 3: Bank System


	// Find Client

	/*

	clsBankClient Client1 = clsBankClient::Find("A101");
	if (!Client1.IsEmpty())
	{
		cout << "\nClient Found :-)\n";
	}
	else
	{
		cout << "\nClient Was not Found :-(\n";
	}

	Client1.Print();

	clsBankClient Client2 = clsBankClient::Find("A101", "1234");
	if (!Client2.IsEmpty())
	{
		cout << "\nClient Found :-)\n";
	}
	else
	{
		cout << "\nClient Was not Found :-(\n";
	}
	Client2.Print();


	cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");

	*/

	// Update Client

	/*
	
	UpdateClient();

	*/

	// Add New

	/*
	
	AddNewClient();
	
	*/

	// Delete Account

	/*
	
	DeleteClient();
	
	*/

	// List Clients

	/*

	ShowClientsList();
	
	*/

	// Total Balances

	/*
	
	ShowTotalBalances();

	*/

	// Main Screen (UI)


	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}



	system("pause>0");
	return 0;

}

