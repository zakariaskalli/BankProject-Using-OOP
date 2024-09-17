#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "fstream"

using namespace std;

class clsLoginScreen :protected clsScreen
{
private:



    static bool _Login()
    {

        bool LoginFail = false;
        short FailLoginCount = 0;

        string Username, Password;

        do
        {

            if (LoginFail)
            {
                FailLoginCount++;

                cout << "Invalid Username/Password!\n\n";
                cout << "\nYou have " << (3 - FailLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FailLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 fail trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFail = CurrentUser.IsEmpty();

        } while (LoginFail);
        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenu();
        return true;
    }


public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t Login Screen");
        return _Login();
    }

};

