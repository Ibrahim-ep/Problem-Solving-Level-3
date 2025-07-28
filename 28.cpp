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

char InverLetterCase(char Char1)
{
    return (isupper(Char1) ? tolower(Char1) : toupper(Char1));
}

string InvertAllStringLettersCase(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    { 
        Text[i] = InverLetterCase(Text[i]);
    }
    return Text;
}

int main()
{
    string S1;
    S1 = ReadText();

    cout << InvertAllStringLettersCase(S1) << endl;

    return 0;
}