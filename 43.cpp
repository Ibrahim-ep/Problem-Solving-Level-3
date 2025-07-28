#include <string>
#include <iostream>
#include <vector>
#include "/Users/ibrahimimad/Library/Mobile Documents/com~apple~CloudDocs/Documents/C++problems/Algorithms & Problem-Solving Level 3/MyStringLib.hpp"

using namespace std;

string ReplaceWordInString(string S1, string StringToReplace, string sRplaceTo, bool Match = true)
{
    if (Match)
    {
        UpperFirstLetterOfEachWord(StringToReplace);
    }

    vector <string> vString = SplitEachWord(S1," ");
    vector <string>::iterator itor = vString.begin();
    short pos = S1.find(StringToReplace);

    while (S1.find(StringToReplace) != std::string::npos && itor != vString.end())
    {
        
        S1.erase(pos,StringToReplace.length());
        S1 = S1.insert(pos,sRplaceTo);
        pos = S1.find(StringToReplace);
      
        itor++;
       
    }
    return S1;
}

int main()
{
    string S1 = "Welcom to Jordan, Jordan is a Nice country";

    cout << "Original string : " << S1 << endl;
    cout << "String after replace no match case : " << ReplaceWordInString(S1,"jordan","Iraq") << endl;
    cout << "String after replace  match case : " << ReplaceWordInString(S1,"jordan","Iraq", false) << endl;

    return 0;
}