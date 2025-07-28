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

void GetFirstLetterFromString(string Text)
{
    bool isFirstLetter = true;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && isFirstLetter)
        {
            cout << Text[i] << endl;
        }
        isFirstLetter = (Text[i] == ' ' ? true : false);
    }
}

int main()
{
    string Text;

    Text = ReadText();

    GetFirstLetterFromString(Text);

    return 0;
}