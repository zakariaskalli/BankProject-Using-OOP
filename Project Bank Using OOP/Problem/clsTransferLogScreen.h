#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;


class clsTransferLogScreen : protected clsScreen
{
private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(8) << left << LoginRegisterRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << LoginRegisterRecord.DestinationAcccountNumber;
        cout << "| " << setw(8) << left << LoginRegisterRecord.Amount;
        cout << "| " << setw(10) << left << LoginRegisterRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << LoginRegisterRecord.destBalanceAfter;
        cout << "| " << setw(8) << left << LoginRegisterRecord.UserName;


    }


public:


    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();
        
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

