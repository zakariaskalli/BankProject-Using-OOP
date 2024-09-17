#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsMenu : protected clsScreen
{

private:

    enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5 ,eShowMainMenu = 6 };

    static short ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        // cout << "\n Client Deposit Screen Will be here...\n";

        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        //cout << "\n WithDraw Client Screen Will be here...\n";

        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        // cout << "\nTotal Balances Client Screen Will be here...\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        // cout << "\nTotal Balances Client Screen Will be here...\n";
        
        clsTransferScreen::ShowTransferScreen();

    }

    static void _ShowTransferLogScreen()
    {
        // cout << "\nTotal Balances Client Screen Will be here...\n";

        clsTransferLogScreen::ShowTransferLogScreen();

    }


    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
            case enTransactionsMenuOptions::eDeposit:
            {
                system("cls");
                _ShowDepositScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            case enTransactionsMenuOptions::eWithdraw:
            {
                system("cls");
                _ShowWithDrawScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            case enTransactionsMenuOptions::eShowTotalBalance:
            {
                system("cls");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            
            case enTransactionsMenuOptions::eTransfer:
            {
                system("cls");
                _ShowTransferScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOptions::eTransferLog:
            {
                system("cls");
                _ShowTransferLogScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransactionsMenuOptions::eShowMainMenu:
            {

            }

        }

    }



public:


    static void ShowTransactionsMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";    
    
        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    
    }


};

