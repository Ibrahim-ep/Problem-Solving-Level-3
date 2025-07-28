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

short CountWords(string Text)
{
    string delim = " "; // Delimiter
    short pos = 0;

    string sWord;
    short counter = 0;
    // use find() function to find position of the delimiters
    while ((pos = Text.find(delim)) != std::string::npos)
    {
        sWord = Text.substr(0,pos); // store thr word
        if (sWord != "")
        {
            counter++;
        }
        Text.erase(0,pos + delim.length()); //erase() until position and move to next word
    }
    if (Text != "") // it print last word of the string
    {
        counter++;
    }
    return counter;
}

int main()
{
    string S1 = ReadText();

    cout << "The number of words in you string = ";
    cout << CountWords(S1) << endl;

    return 0;
}