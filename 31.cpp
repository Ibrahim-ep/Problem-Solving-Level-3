#include <iostream>
#include <string>

using namespace std;

enum enWhatToCount {SmallLetters = 1, CapitalLetters = 2,All = 3};

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

char InverLetterCase(char S1)
{
    return (isupper(S1) ? tolower(S1) : toupper(S1));
}

short CountLetter(string S1,char Letter,bool Match = true)
{
    short CharCounter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (Match)
        {
            if (S1[i] == Letter)
            {
                CharCounter++;
            }
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
            {
                CharCounter++;
            }
        }
    }
    return CharCounter;
}

int main()
{
    string S1 = ReadText();
    char Ch1 = ReadCharacter();

    cout << "Letter '" << Ch1 << "' count = " << CountLetter(S1,Ch1) << endl;
    cout << "Letter '" << Ch1 << "' " << "or '" << InverLetterCase(Ch1) << "' count = " << CountLetter(S1,Ch1,false) << endl;

    return 0;
}