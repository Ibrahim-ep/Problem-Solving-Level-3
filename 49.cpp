
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std; 

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
   
        cout << "Acount Number :  " << Client.AccountNumber;     
        cout << "PIN code :  " << Client.PinCode;     
        cout << "Name :  " << Client.Name;     
        cout << "Phone number : " << Client.Phone;     
        cout << "Balance :  " << Client.AccountBalance; 
    
}

string ReadAcountNumber()
{
    string AcNumber;

    cout << "Pleas enter acount number\n";
    cin >> AcNumber;

    return AcNumber;
}

bool FindClientByAcountNumber(stClient &Client,string AcountNumber)
{
    vector <stClient> vClient = LoadCleintsDataFromFile("Clients.txt");

    for (stClient &C : vClient)     
    {         
      if (C.AccountNumber == AcountNumber)
      {
        Client = C;
        return true;
      }  
    }
    return false;
}

int main() 
{  
    stClient Client;
    string AcountNumber = ReadAcountNumber();

    if (FindClientByAcountNumber(Client,AcountNumber))
    {
        PrintClientRecord(Client);
    }
    else 
    {
        cout << "Client Not found";
    }
    
    return 0; 
}    