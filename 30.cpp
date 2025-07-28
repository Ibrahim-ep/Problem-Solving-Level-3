#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Text;

    cout << "Pleas enter your text\n";
    getline(cin, Text);

    return Text;
}

char ReadCharacter()
{
    char Char;

    cout << "Pleas enter your charecter\n";
    cin >> Char;

    return Char;
}

short CountCharacter(string S1,char CharWantToCount)
{
    short CharCounter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == CharWantToCount)
        CharCounter++;
    }
    return CharCounter;
}

int main()
{
    string S1 = ReadText();
    char C1 = ReadCharacter();

    cout << "\nLetter '" << C1 << "' count is : " << CountCharacter(S1,C1) << endl;

    return 0;
}