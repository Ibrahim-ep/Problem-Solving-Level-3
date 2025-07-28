#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct  stClient
{
    string AccountNumber;
    string PinCode; 
    string Name; 
    string Phone; 
    double AccountBalance; 
};

stClient ReadClientInfo()
{
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);    

    cout << "Enter Phone? ";     
    getline(cin, Client.Phone);     

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client,string Seperator = "#//#") 
{
    string sClient;

    sClient += Client.AccountNumber + Seperator;
    sClient += Client.PinCode + Seperator;
    sClient += Client.Name + Seperator;
    sClient += Client.Phone + Seperator;
    sClient += to_string(Client.AccountBalance);

    return sClient;
}

int main()
{
    stClient Client;

    Client = ReadClientInfo();

    cout << "\n\nClient record for saving is : \n";
    cout << ConvertRecordToLine(Client) << endl;

    return 0;
}