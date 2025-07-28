#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string FileName = "Clients.txt";

struct  stClient
{
    string AcountNumber;
    string PINcode;
    string Name;
    string PhoneNumber;
    double Balance;
};

stClient ReadClientRecord()
{
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AcountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PINcode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);    
 
    cout << "Enter Phone? ";     
    getline(cin, Client.PhoneNumber);     

    cout << "Enter AccountBalance? ";
    cin >> Client.Balance;

    return Client;
}

string ConvertRecordToLine(stClient Client,string Seperator = "#//#") 
{
    string sClient;

    sClient += Client.AcountNumber + Seperator;
    sClient += Client.PINcode + Seperator;
    sClient += Client.Name + Seperator;
    sClient += Client.PhoneNumber + Seperator;
    sClient += to_string(Client.Balance);

    return sClient;
}

void SaveClientRecordToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open("Clients.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client = ReadClientRecord();

    SaveClientRecordToFile(FileName,ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = ' ';
    do
    {
        cout << "\nAdding new client\n\n";

        AddNewClient();

       cout << "Client Added Successfully, Do you want to add more clients? Y/N\n";
       cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
    
}

int main()
{

    AddClients();

    return 0;
}