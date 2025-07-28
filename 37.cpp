#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReadText()
{
    string Text;

    cout << "Pleas enter your text\n";
    getline(cin, Text);

    return Text;
}

vector <string> SplitEachWord(string S1,string delim)
{
    short pos = 0;

    string sWord;
    vector <string> vWord;
    // use find() function to find position of the delimiters

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0,pos); // store thr word

        if (S1 != " ")
        {
            vWord.push_back(sWord);
        }

        (S1.erase(0,pos + delim.length())); //erase() until position and move to next word
    }
    if (S1 != "") // it print last word of the string
    {
        vWord.push_back(S1);
    }
    return vWord;
}

int main()
{
    vector <string> vWord = SplitEachWord(ReadText()," ");

    cout << "Tokens = " << vWord.size() << endl;

    for (string & Word : vWord)
    {
        cout << Word << endl;
    }

    return 0;
}