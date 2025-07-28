#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std; 

const string FileName = "Clients.txt";

struct stClient 
{ 
    string AccountNumber; 
    string PinCode; 
    string Name; 
    string Phone; 
    double AccountBalance;
    bool MarkForUpdate = false;
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

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClient)
{
    fstream MyFile;

    MyFile.open("Clients.txt", ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient & c : vClient)
        {
            if (c.MarkForUpdate == false)
            {
                DataLine = ConvertRecordToLine(c);

                MyFile << DataLine << endl;
            }    
        }
        MyFile.close();
    }
    return vClient;
}

void SaveClientRecordToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

bool YouWantToUpdateClient()
{
    char Answer = ' ';

    cout << "\nAre you sure you want to update this client ? Y/N ? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        return true;
    }
    return false;
}

stClient ChangeClientRecord(string AcountNumber)
{
    stClient c;

    c.AccountNumber = AcountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, c.PinCode);

    cout << "Enter Name? ";
    getline(cin, c.Name);    
 
    cout << "Enter Phone? ";     
    getline(cin, c.Phone);     

    cout << "Enter AccountBalance? ";
    cin >> c.AccountBalance;
    
    return c;
}

bool UpdateClient(vector <stClient> &vClient,string AcountNumber)
{
    stClient Client;

    if (FindClientByAcountNumber(Client,vClient,AcountNumber))
    {
        PrintClientRecord(Client);

       if (YouWantToUpdateClient())
       {
           for (stClient &c : vClient)
           {
             if (c.AccountNumber == AcountNumber)
             {
                c = ChangeClientRecord(AcountNumber);
                break;
             }
           }

            SaveClientsDataToFile("Clients.txt",vClient);

            cout << "\n\nClient Updated Successfully" << endl;
            return true;
       }
    }
    else
    {
        cout << "Client with Acount Number " << (AcountNumber) <<  " not found" << endl;
    }
    return false;
}

int main()
{
    vector <stClient> vClient = LoadCleintsDataFromFile(FileName);
    string AcountNumber = ReadAcountNumber();

    UpdateClient(vClient,AcountNumber);

    return 0;
}