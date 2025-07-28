#include <string>
#include <iostream>

using namespace std;

string ReadText()
{
    string Text;

    cout << "Pleas enter your text\n";
    getline(cin, Text);

    return Text;
}

bool IsVowel(char Ch1)
{
    tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

void PrintVowels(string S1)
{
    short VowelCount = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
        {
            cout << S1[i] << "\t";
        }
    }
}

int main()
{
    string S1 = ReadText();

    cout << "vowels in string are : ";
    PrintVowels(S1);
    cout << endl;

    return 0;
}