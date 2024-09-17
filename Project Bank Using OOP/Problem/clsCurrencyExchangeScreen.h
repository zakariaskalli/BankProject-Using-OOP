#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeMenuOption
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static  void _GoBackToCurrencyExchangeMenu()
    {
        cout << "\n\tPress any key to go back to Currency Exchange Menu...\n";

        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _ShowListCurrenciesScreen()
    {
        // cout << "\n\tList Currencies Screen Will be here...\n";

        clsListCurrenciesScreen::ShowListCurrenciesScreen();

    }

    static void _ShowFindCurrencyScreen()
    {
        // cout << "\n\tFind Currency Screen Will be here...\n";

        clsFindCurrencyScreen::ShowFindUserScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        // cout << "\n\tUpdate Rate Screen Will be here...\n";

        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "\n\tCurrency Calculator Screen Will be here...\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }


    static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOption CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
            case enCurrencyExchangeMenuOption::eListCurrencies :
            {
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyExchangeMenu();
                break;
            }
            case enCurrencyExchangeMenuOption::eFindCurrency:
            {
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyExchangeMenu();
                break;
            }
            case enCurrencyExchangeMenuOption::eUpdateCurrencyRate:
            {
                system("cls");
                _ShowUpdateCurrencyRateScreen();
                _GoBackToCurrencyExchangeMenu();
                break;
            }
            case enCurrencyExchangeMenuOption::eCurrencyCalculator:
            {
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyExchangeMenu();
                break;
            }

            case enCurrencyExchangeMenuOption::eMainMenu:
            {

            }
        }

    }


public:

    static void ShowCurrencyExchangeMenu()
    {

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOption)ReadCurrencyExchangeMenuOption());

    }


};
