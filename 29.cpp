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

short CountSmallLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        Counter++;
    }

    return Counter;
}

short CountCapitalLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        Counter++;
    }

    return Counter;
}

int main()
{
    string S1;
    S1 = ReadText();

    cout << "\nString length = " << S1.length() << endl;
    cout << "Capital letter count = " << CountCapitalLetters(S1) << endl;
    cout << "Small letter count = " << CountSmallLetters(S1) << endl;

    return 0;
}