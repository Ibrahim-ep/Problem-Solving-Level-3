#include <iostream>
#include <string>

using namespace std;

string ReplaceWordUsinfBuiltINFunction(string S1,string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos,StringToReplace.length(),sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

int main()
{
    string S1 = "Welcom to Jordan, Jordan is a nice country ";

    cout << "Original string : \n" << S1 << endl;
    cout << "\nString After Replace : \n";
    cout << ReplaceWordUsinfBuiltINFunction(S1,"Jordan","Iraq") << endl;

    return 0;
}