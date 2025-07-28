
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
    bool MarkForDelete = false;
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
   
        cout << "Acount Number :  " << Client.AccountNumber << endl;     
        cout << "PIN code :  " << Client.PinCode << endl;     
        cout << "Name :  " << Client.Name << endl;        
        cout << "Phone number : " << Client.Phone << endl;         
        cout << "Balance :  " << Client.AccountBalance<< endl;     
    
}

string ReadAcountNumber()
{
    string AcNumber;

    cout << "Pleas enter acount number\n";
    cin >> AcNumber;

    return AcNumber;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#") 
{ 
    string stClientRecord = "";     
    stClientRecord += Client.AccountNumber + Seperator;     
    stClientRecord += Client.PinCode + Seperator;     
    stClientRecord += Client.Name + Seperator;     
    stClientRecord += Client.Phone + Seperator;    
    stClientRecord += to_string(Client.AccountBalance); 
    return stClientRecord; 
} 

bool FindClientByAcountNumber(stClient &Client,vector <stClient> vClient,string AcountNumber)
{
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

bool YouWantToDeleteClient()
{
    char Delete = ' ';

    cout << "Are you sure you want to delete this client ? Y/N";
    cin >> Delete;

    if (toupper(Delete) == 'Y')
    {
        return true;
    }
    return false;
}

bool MarkClientForDeleteByAcountNumber(string AcountNumber, vector <stClient> &vClient)
{
    for (stClient &c : vClient)
    {
        if (c.AccountNumber == AcountNumber)
        {
            c.MarkForDelete = true;
            return true;
        }
    }
    return  false;
}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClient)
{
    fstream MyFile;

    MyFile.open("Clients.txt", ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient & c : vClient)
        {
           if (c.MarkForDelete == false)
           {
             DataLine = ConvertRecordToLine(c);

             MyFile << DataLine << endl;
           }
        }
        MyFile.close();
    }
    return vClient;
}

bool DeletClient(vector <stClient> &vClient,string AcountNumber)
{
    stClient Client;

    if (FindClientByAcountNumber(Client,vClient,AcountNumber))
    {
        PrintClientRecord(Client);

        if(YouWantToDeleteClient())
        {
            MarkClientForDeleteByAcountNumber(AcountNumber,vClient);

            SaveClientsDataToFile("Clients.txt",vClient);

            vClient = LoadCleintsDataFromFile("Clients.txt");
            cout << "\n\nClient Deleted Successfully\n";
            return true;
        }
    }
    else
    {
        cout << "Client not found";
    }
    return false;
}

int main() 
{  
    vector <stClient> vClient = LoadCleintsDataFromFile("Clients.txt");
    string AcountNumber = ReadAcountNumber();

    DeletClient(vClient,AcountNumber);
    
    return 0; 
}    