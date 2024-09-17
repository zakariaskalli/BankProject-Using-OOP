#pragma once


#include <iostream>
#include <cstdlib>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}

	enum enRandom { SmallLetter = 1, CapitallLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };

	static char GetRandomCharacter(enRandom Random)
	{
		switch (Random)
		{
		case SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case CapitallLetter:
			return char(RandomNumber(65, 90));
			break;
		case Digit:
			return char(RandomNumber(48, 57));
			break;
		case SpecialCharacter:
			return char(RandomNumber(32, 47));
			break;
		case MixChars:
			return GetRandomCharacter((enRandom)RandomNumber(1,3));
			break;
		}

	}

	static string GeneratorWord(enRandom CharType, int Length)
	{
		string word;

		for (int i = 1; i <= Length; i++)
		{
			word += GetRandomCharacter(CharType);
		}
		return word;
	}

	static string Generatorkey()
	{
		string key = "";

		key += GeneratorWord(enRandom::CapitallLetter, 4) + "-";
		key += GeneratorWord(enRandom::CapitallLetter, 4) + "-";
		key += GeneratorWord(enRandom::CapitallLetter, 4) + "-";
		key += GeneratorWord(enRandom::CapitallLetter, 4);

		return key;
	}

	static void Generatorkeys(int NumberOFKeys)
	{
		for (int i = 1; i <= NumberOFKeys; i++)
		{
			cout << "Key [" << i << "]: ";
			cout << Generatorkey() << endl;
		}
	}

	static void FillArrayWithRandomNumbers(int Arr[], int ArrLength, int NumStart, int NumEnd)
	{

		for (int i = 0; i < ArrLength; i++)
			Arr[i] = RandomNumber(NumStart, NumEnd);
	}

	static void FillArrayWithRandomWords(string Arr[], int NumWords, enRandom CharType, int LengthWord)
	{

		for (int i = 0; i < NumWords; i++)
			Arr[i] = GeneratorWord(CharType, LengthWord);
	}

	static void FillArrayWithRandomKeys(string Arr[], int NumKeys, enRandom CharType)
	{

		for (int i = 0; i < NumKeys; i++)
			Arr[i] = Generatorkey();
	}

	static void Swap(int& A, int& B)
	{
		int Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static void Swap(double& A, double& B)
	{
		double Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static void Swap(char& A, char& B)
	{
		char Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static void Swap(string& A, string& B)
	{
		string Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate Swap;

		Swap = A;
		A = B;
		B = Swap;
	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t += "\t";
		}
		return t;
	}

	
	static void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string ConvertTextToEncryption(string Text, int EncryptedKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptedKey);
		}
		return Text;
	}

	static string ConvertEncryptionToText(string Text, int EncryptedKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptedKey);
		}
		return Text;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

	static string EncryptText(string Text, short EncryptedKey = 2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptedKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptedKey = 2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptedKey);
		}
		return Text;
	}

};

