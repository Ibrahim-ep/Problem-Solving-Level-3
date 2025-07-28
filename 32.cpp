#include <iostream>
#include <string>

using namespace std;

char ReadCharacter()
{
    char Char;

    cout << "Pleas enter your charecter\n";
    cin >> Char;

    return Char;
}

bool IsVowel(char Ch1)
{
    tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

int main()
{
    char Ch1 = ReadCharacter();

    if(IsVowel(Ch1))
    {
        cout << "Yes, it is a vowel character\n";
    }
    else
    {
        cout << "No, it is NOT a vowel character\n";
    }

    return 0;
}