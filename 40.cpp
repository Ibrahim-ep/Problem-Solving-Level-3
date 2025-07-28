#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(vector <string> vString,string delim)
{
    string S1 = "";

    for (string &s : vString)
    {
        S1 = S1 + s + delim;
    }
    
    return S1.substr(0,S1.length() - delim.length());
}

string JoinString(string arrString[],short arrLength,string delim)
{
    string S1 = "";
    for (short i = 0; i < arrLength; i++)
    {
        S1 = S1 + arrString[i] + delim;
    }

   return S1.substr(0,S1.length() - delim.length());
}

int main()
{
    string arrString[] = {"Mohammed","Ali","Shadi","Maher"};
    vector <string> vString = {"Mohammed","Ali","Shadi","Maher"};

    cout << "Vector after join string :\n";
    cout << JoinString(vString," ") << endl;

    cout << "\nArray after join :\n";
    cout << JoinString(arrString,4," ") << endl;

    return 0;
}