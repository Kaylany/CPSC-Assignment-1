#include <iostream>
#include <string>
#include <cstring> // if you want to use functions
//such as strcat(), strlen(), strcomp()
#include <iomanip>
#include <fstream>

using namespace std;

struct PERSON {
  char Name[20];
  float Balance;
} ;

 void Display(string personArray[], int count);
 void FindRichest(string personArray[], int count);
 void Deposit(string custName, string personArray[], int count);
// Reading from file

int main()
{
  int count = 0;
  string line;
  string personArray[20];
  string custName;
  int deposit;

//  ifstream file("data.txt");
  ifstream inputFile;
  inputFile.open("data.txt");

  while (getline(inputFile, line))
  {
    count++;
  }
  cout << "Number of records in the file: " << count << endl;

  cout << "Name           	  Balance" << endl;
  cout << "-----------------------------------------------" << endl;
  Display(personArray, 6);

  cout << "\nThe customer with maximum balance is ";
  FindRichest(personArray, 6);


  Deposit(custName, personArray, 6);
  return 0;
}

void Display(string personArray[], int count)
{
  ifstream inputFile; // define ifstream object named file
  inputFile.open("data.txt"); // opens data.txt file and links it with the file object
  // when executed you will be able to use file to read data from data.txt file

  char Name[20];
  string firstName;
  string lastName;
  float balance;
  if (!inputFile.fail())
  {
    for (int i = 0; i < count; i++)
    {
      inputFile >> firstName;
      inputFile >> lastName;
      inputFile >> balance;
      string fullName = firstName + " " + lastName;
      strcpy(Name, fullName.c_str());
      cout << Name << " ";
      cout << setprecision(2) << fixed << balance << "\n";
    }
    inputFile.close();
  }
  else
  {
    cout << "Error opening file. \n";
  }
}

void FindRichest(string personArray[], int count)
{
  ifstream inputFile;
  inputFile.open("data.txt");

  char Name[20];
  string firstName;
  string lastName;
  float balance, max, min;
  if (!inputFile.fail())
  {
    for (int i = 0; i < count; i++)
    {
      inputFile >> firstName;
      inputFile >> lastName;
      inputFile >> balance;
      string fullName = firstName + " " + lastName;
      strcpy(Name, fullName.c_str());

      if (balance > max)
      {
        max = balance;
        cout << Name << endl;
      }
    }
  }
  else
  {
    cout << "Error opening file. \n";
  }

}

void Deposit(string custName, string personArray[], int count)
{
  ifstream inputFile;
  inputFile.open("data.txt");

  char Name[20];
  string firstName;
  string lastName;
  float balance;
  int deposit;

  //balance += inputValue;
  //cout << "Now your new balance is " << balance;
  cout << "Enter your full name to deposit money: ";
  cin >> custName;
  cout << custName << ", how much would you like to deposit? ";
  cin >> deposit;
  while(inputFile)
  {
    inputFile >> firstName;
    inputFile >> lastName;
    inputFile >> balance;
    string fullName = firstName + " " + lastName;
    strcpy(Name, fullName.c_str());
  }
        while (strcmp(Name, custName.c_str()) == 0)
        {
          cout << custName << ", how much would you like to deposit? ";
          cin >> deposit;
          balance += deposit;
        }
}
