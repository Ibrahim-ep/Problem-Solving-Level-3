#include <iostream>
#include <string>

using namespace std;

char ReadChar()
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

int main()
{
    char S1;

    S1 = ReadChar();

    cout << "\nChar after inverting case : \n";
    cout << InverLetterCase(S1) << endl;

    return 0;
}