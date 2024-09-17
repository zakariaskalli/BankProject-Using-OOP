#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{
private:
	enum enChoice {
		eCode = 1, eCountry = 2
	};

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}


public:

	static void ShowFindUserScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "Find By: [1] Code or [2] Country ? ";
		short Answer = 1;

		Answer = clsInputValidate<short>::ReadNumberBetween(1,2);

		if (Answer == 1)
		{
			string CurrencyCode ;

			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;

			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate<float>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}


};

