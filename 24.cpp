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

string UpperFirstLetterOfEachWord(string Text)
{
    bool isFirstLetter = true;
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && isFirstLetter)
        {
            Text[i] = toupper(Text[i]);
        }
        isFirstLetter = (Text[i] == ' ' ? true : false);
    }
    return Text;
}

int main()
{
    string Text;

    Text = ReadText();

    cout << "\nString after conversion\n";
    cout << UpperFirstLetterOfEachWord(Text) << endl;

    return 0;
}