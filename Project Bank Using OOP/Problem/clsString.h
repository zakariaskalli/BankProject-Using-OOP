
#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;



class clsString
{

private:
    string _Value;


    static bool isvowel(char i)
    {
        i = tolower(i);
        return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ? true : false;
    }

public:

    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    // 1 CountWords

    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = short(S1.find(delim)))  != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until position and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    // 2 PrintFirstLettersOfString

    static char PrintFirstLettersOfString(string S1)
    {
        bool IsSpace = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsSpace)
                return S1[i];
            IsSpace = (S1[i] == ' ') ? true : false;
        }
    }

    char PrintFirstLettersOfString()
    {
        return PrintFirstLettersOfString(_Value);
    }

    // 3 UpperFirstLetterOfEachWord

    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool IsSpace = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsSpace)
                S1[i] = toupper(S1[i]);
            IsSpace = (S1[i] == ' ') ? true : false;
        }
        return S1;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    // 4 LowerFirstLetterOfEachWord

    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool IsSpace = true;
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && IsSpace)
                S1[i] = tolower(S1[i]);
            IsSpace = (S1[i] == ' ') ? true : false;
        }
        return S1;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    // 5 UpperAllLetterOfString

    static string UpperAllLetterOfString(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void UpperAllLetterOfString()
    {
        _Value = UpperAllLetterOfString(_Value);
    }

    // 6 LowerAllLetterOfString

    static string LowerAllLetterOfString(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void LowerAllLetterOfString()
    {
        _Value = LowerAllLetterOfString(_Value);
    }

    // 7 InvertAllLettersOfString

    static char InvertingCharacter(char MyChar)
    {
        return (isupper(MyChar)) ? tolower(MyChar) : toupper(MyChar);
    }


    static string InvertAllLettersOfString(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = clsString::InvertingCharacter(S1[i]);
        }
        return S1;
    }

    void InvertAllLettersOfString()
    {
        _Value = InvertAllLettersOfString(_Value);
    }

    // 8 CountLetters

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
            return short(S1.length());

        short Counter = 0;


        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;
            else if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short CountLetters()
    {
        return CountLetters(_Value);
    }

    // 9 Count Capital Letters

    static short CountCapitalLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    // 10 CountSmallLetters

    static short CountSmallLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    // 11 CountLettersDontMatchCase

    static short CountLettersDontMatchCase(string S1, char CharToCount)
    {
        short Counter = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == CharToCount)
                Counter++;
        }
        return Counter;
    }

    short CountLettersDontMatchCase(char CharToCount)
    {
        return CountLettersDontMatchCase(_Value, CharToCount);
    }

    // 12 CountLettersByMatchCase

    static short CountLettersByMatchCase(string S1, char CharToCount)
    {
        short Counter = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (toupper(S1[i]) == toupper(CharToCount))
                Counter++;
        }
        return Counter;
    }

    short CountLettersByMatchCase(char CharToCount)
    {
        return CountLettersByMatchCase(_Value, CharToCount);
    }

    // 13 CountVowelLetters

    static short CountVowelLetters(string S1)
    {
        short Counter = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isvowel(S1[i]))
                Counter++;
        }
        return Counter;
    }

    short CountVowelLetters()
    {
        return CountVowelLetters(_Value);
    }

    // 14 PrintAllVowelsInString

    static string PrintAllVowelsInString(string S1, string Space = "  ")
    {
        string Vowels;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isvowel(S1[i]))
                Vowels += S1[i] + Space;
        }
        return Vowels;
    }

    string PrintAllVowelsInString()
    {
        return PrintAllVowelsInString(_Value);
    }

    // 15 PrintEachWordInString

    static void PrintEachWordInString(string S1)
    {
        string Space = " ";
        string NewS1;
        short Pos;
        while ((Pos = short(S1.find(Space))) != string::npos)
        {
            NewS1 = S1.substr(0, Pos);
            if (NewS1 != "")
                cout << NewS1 << endl;
            S1.erase(0, Pos + Space.length());
        }
        if (S1 != "")
            cout << S1 << endl;
    }

    void PrintEachWordInString()
    {
        return PrintEachWordInString(_Value);
    }

    // 16 CountEachWordInString

    static short CountEachWordInString(string S1)
    {
        short Counter = 0;
        string Space = " ";
        string NewS1;
        short Pos;
        while ((Pos = short(S1.find(Space))) != string::npos)
        {
            NewS1 = S1.substr(0, Pos);
            if (NewS1 != "")
                Counter++;
            S1.erase(0, Pos + Space.length());
        }
        if (S1 != "")
            return ++Counter;
    }

    short CountEachWordInString()
    {
        return CountEachWordInString(_Value);
    }

    // 17 SplitString

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = short(S1.find(Delim))) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            // if (sWord != "")
            // {
            vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    // 18 Trim Left / Right / Complet

    static string TrimLeft(string S1, char Delim = ' ')
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != Delim)
                return S1 = S1.substr(i, S1.length());
        }
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }


    static string TrimRight(string S1, char Delim = ' ')
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[S1.length() - i - 1] != Delim)
                return S1 = S1.substr(0, S1.length() - i);
        }
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }


    static string Trim(string S1, char Delim = ' ')
    {
        return TrimLeft(TrimRight(S1, Delim), Delim);
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    // 19 JoinString

    static string JoinString(vector <string> vSplit, string Delim)
    {
        string Line;
        for (string& temp : vSplit)
            Line += temp + Delim;
        return Trim(Line, '#');
    }

    void JoinString(string Delim)
    {
        _Value = JoinString(Split(_Value), Delim);
    }

    // 20 ReverseWordsInString

    static string ReverseWordsInString(string S1)
    {
        vector <string> vString;

        string S2 = "";

        vString = Split(S1, " ");

        vector <string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;

            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);

        return S2;
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    // 21 ReplaceWordsInMatchCase

    static string ReplaceWordsInMatchCase(string S1, string Word, string Replace)
    {
        int Pos;
        while ((Pos = int(S1.find(Word))) != string::npos)
            S1 = S1.replace(Pos, Word.length(), Replace);
        return S1;
    }

    void ReplaceWordsInMatchCase(string Word, string Replace)
    {
        _Value = ReplaceWordsInMatchCase(_Value, Word, Replace);
    }

    // 22 ReplaceWordsDontMatchCase

    static string ReplaceWordsDontMatchCase(string S1, string Word, string Replace)
    {
        vector <string> vS1 = Split(S1, " ");
        for (string& temp : vS1)
            if (LowerAllLetterOfString(Word) == LowerAllLetterOfString(temp))
                temp = Replace;
        return JoinString(vS1, " ");
    }

    void ReplaceWordsDontMatchCase(string Word, string Replace)
    {
        _Value = ReplaceWordsDontMatchCase(_Value, Word, Replace);
    }

    // 23 RemovePunctuations

    static string RemovePunctuations(string S1)
    {

        for (int i = 0; i < S1.length(); i++)
        {
            if (ispunct(S1[i]))
                S1[i] = '\0';
        }
        return S1;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }

    // 24 PrintStringWithoutPunct

    static string PrintStringWithoutPunct(string S1, string Space)
    {
        string Word;
        vector <string> vS1 = Split(S1, " ");
        for (string& temp : vS1)
            Word += temp + Space;
        return Word.substr(0, Word.length() - 1);
    }

    void PrintStringWithoutPunct(string Space)
    {
        _Value = PrintStringWithoutPunct(_Value, Space);
    }

    // 25 Length

    static short Length(string S1)
    {
        return short(S1.length());
    };

    short Length()
    {
        return short(_Value.length());
    };

};