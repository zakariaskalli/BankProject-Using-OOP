#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nUser Name      : " << User.UserName;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions;
		cout << "\n___________________\n";
	}


public:

	static void ShowFindUserScreen()
	{

		_DrawScreenHeader("\t  Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser not is found, choose another one: ";
			UserName = clsInputValidate<string>::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

		_PrintUser(User1);

	}



};

