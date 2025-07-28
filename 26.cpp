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

string LowerLettersOfEachWord(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = tolower(Text[i]);
    }
    return Text;
}

string UpperLettersOfEachWord(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    { 
        Text[i] = toupper(Text[i]);
    }
    return Text;
}

int main()
{
    string Text;

    Text = ReadText();

    cout << "\nString after Lowerring all letters\n";
    cout << LowerLettersOfEachWord(Text) << endl;

    cout <<"\nString after upperring all letters\n";
    cout << UpperLettersOfEachWord(Text) << endl;

    return 0;
}