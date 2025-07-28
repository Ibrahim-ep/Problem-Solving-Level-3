#include <string>
#include <iostream>
#include <vector>
#include "/Users/ibrahimimad/Library/Mobile Documents/com~apple~CloudDocs/Documents/C++problems/Algorithms & Problem-Solving Level 3/MyStringLib.hpp"

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode; 
    string Name; 
    string Phone; 
    double AccountBalance; 
};

stClient ConvertLinetoRecord(string Line, string Seperator)
{
    stClient Client; 
    vector<string> vClientData;    

    vClientData = SplitEachWord(Line, Seperator);

    Client.AccountNumber = vClientData[0];     
    Client.PinCode = vClientData[1];     
    Client.Name = vClientData[2];     
    Client.Phone = vClientData[3];     
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

void PrintClientRecord(stClient  Client)
{
    cout << "\n\nThe following is the extracted client record:\n";

    cout << "\nAcount number : " << Client.AccountNumber << endl;
    cout << "PIN code : " << Client.PinCode << endl;
    cout << "Name : " << Client.Name << endl;
    cout << "Phone number : " << Client.Phone << endl;
    cout << "Acount balance : " << Client.AccountBalance << endl;
}

int main()
{
    string s = "A200#//#1234#//#ibrahim imad#//#673217#//#599";
    stClient Client = ConvertLinetoRecord(s,"#//#");

    cout << "\nLine Record is:\n";
    cout << s;

    PrintClientRecord(Client);

    return 0;
}