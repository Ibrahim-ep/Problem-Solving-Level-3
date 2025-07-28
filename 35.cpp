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

void PrintEachWordInString(string Text)
{
    string delim = " "; // Delimiter
    short pos = 0;

    string sWord;
    // use find() function to find position of the delimiters
    while ((pos = Text.find(delim)) != std::string::npos)
    {
        sWord = Text.substr(0,pos); // store thr word
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        Text.erase(0,pos + delim.length()); //erase() until position and move to next word
    }
    if (Text != "") // it print last word of the string
    {
        cout << Text << endl;
    }
}

int main()
{
    string S1 = ReadText();

    cout << "Your String words are : \n";
    PrintEachWordInString(S1);

    return 0;
}