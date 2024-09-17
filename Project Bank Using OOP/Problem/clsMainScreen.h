#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionsMenu.h"
#include "clsFindClient.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;


class clsMainScreen :protected clsScreen
{

private:

    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9 ,eExit = 10
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";

        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";

        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";

        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << "\nDelete Client Screen Will be here...\n";

        clsDeleteClientScreen::ShowDeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";

        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";

        clsFindClient::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenu()
    {
        // cout << "\nTransactions Menu Will be here...\n";

        clsTransactionsMenu::ShowTransactionsMenu();

    }

    static void _ShowManageUsersMenu()
    {
        // cout << "\nUsers Menu Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();

    }


    //static void _ShowEndScreen()
    //{
    //    cout << "\nEnd Screen Will be here...\n";
    //}

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");
    
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
            case enMainMenuOptions::eListClients:
            {
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eAddNewClient:
            {
                system("cls");
                _ShowAddNewClientsScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eDeleteClient:
            {
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eUpdateClient:
            {
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eFindClient:
            {
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eShowTransactionsMenu:
            {
                system("cls");
                _ShowTransactionsMenu();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eManageUsers:
            {
                system("cls");
                _ShowManageUsersMenu();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eLoginRegister:
            {
                system("cls");
                _ShowLoginRegisterScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eCurrencyExchange:
            {
                system("cls");
                _ShowCurrencyExchangeScreen();
                _GoBackToMainMenu();
                break;
            }
            case enMainMenuOptions::eExit:
            {
                system("cls");
                _Logout();
                break;
            }
        }

    }



public:


    static void ShowMainMenu()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }


};
