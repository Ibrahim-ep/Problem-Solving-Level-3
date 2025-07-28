
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std; 

const string ClientsFileName = "Clients.txt";

struct stClient 
{ 
    string AccountNumber; 
    string PinCode; 
    string Name; 
    string Phone; 
    double AccountBalance; 
};

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

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#") 
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

vector <stClient> LoadCleintsDataFromFile(string FileName)
{
    vector <stClient> vClients; 
    fstream MyFile;     

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line; 
        stClient Client;

        while (getline(MyFile, Line))         
        { 
            Client = ConvertLinetoRecord(Line); 

            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecord(stClient Client) 
{     
    cout << "| " << setw(15) << left << Client.AccountNumber;     
    cout << "| " << setw(10) << left << Client.PinCode;     
    cout << "| " << setw(40) << left << Client.Name;     
    cout << "| " << setw(12) << left << Client.Phone;     
    cout << "| " << setw(12) << left << Client.AccountBalance; 
}

void PrintAllClientsData(vector <stClient> vClients) 
{     
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";     
    cout << "\n_______________________________________________________";     
    cout << "_________________________________________\n" << endl;     
    cout << "| " << left << setw(15) << "Accout Number";     
    cout << "| " << left << setw(10) << "Pin Code";     
    cout << "| " << left << setw(40) << "Client Name";     
    cout << "| " << left << setw(12) << "Phone";     
    cout << "| " << left << setw(12) << "Balance";     
    cout << "\n_______________________________________________________";     
    cout << "_________________________________________\n" << endl; 

    for (stClient Client : vClients)     
    {         
        PrintClientRecord(Client);         
        cout << endl;    
    }     

    cout << "\n_______________________________________________________";     
    cout << "_________________________________________\n" << endl; 
}

int main() 
{ 
    vector <stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);    
     
    PrintAllClientsData(vClients);     
    
    return 0; 
}    