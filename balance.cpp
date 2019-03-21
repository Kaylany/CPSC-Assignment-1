// Kayla Nguyen
// Section 1
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring> //std:: strcpy also string.h
#include <string>

using namespace std;

struct PERSON{
  char Name[20];
  float Balance;
};

void printmenu();
PERSON *readData(int &N);
void Display(PERSON *array, int &N);
void findRichest(PERSON *array, int &N);
void Deposit(PERSON *array, int &N, string custName, float amount);
void newCopy(string FILE, PERSON *array, int &N);

int main(){
  PERSON *array;
  int size = 0;
  array = readData(size);
  string custName;
  float amount;

  int choice;
  do
  {
      printmenu();
      cin >> choice;
      switch(choice)
      {
          case 1:
              // Act on display
              cout << endl;
              Display(array, size);
              cout << endl;
              break;

          case 2:
              // Act on deposit
              cout << endl;
              cout << "Enter your full name to deposit your money: " << endl;
              cin.ignore();
              getline(cin, custName); // gets rid of the \n character
              cout << custName << ", how much would you like to deposit? " << endl << "$";
              cin >> amount;
              Deposit(array, size, custName, amount);
              break;

          case 3:
              // Act highest balance
              cout << endl;
              findRichest(array, size);
              cout << endl;
              break;

          case 4:
              // Act on update records
              cout << endl;
              newCopy("data.txt", array, size);
              break;

          case 5:
              // Must call update records here before exiting the program
              cout << endl;
              newCopy("data.txt", array, size);
              cout << "Exiting program." << endl;
              break;

          default:
              cout << "Invalid entry" << endl;
              break;
      }
      cout << endl;
  } while(choice != 5);
    return 0;
}

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

// This function will read in the .txt file and count how many lines there are.
PERSON *readData(int &N){
  ifstream file;
  file.open("data.txt");
  string line;

  if(file.is_open())
  {
    while(getline(file, line))
    {
      N++;
    }
    file.close();
  }
  else
  {
    cout << "Cannot open input file.\n";
  }

//reopen file
  ifstream file2;
  file2.open("data.txt");
  PERSON *personPtr;
  personPtr = new PERSON[N];

  string fName, lName, fullName;

  if (file2.is_open())
  {
    for (int i = 0; i < N; i++)
    {
      file2 >> fName >> lName;
      file2 >> personPtr[i].Balance;
      fullName = fName + " " + lName;
      strcpy(personPtr[i].Name, fullName.c_str());
    }
    file2.close();
  }
  return personPtr;
}

// This function will display all the names and balances in the .txt file
void Display(PERSON *array, int &N){
  cout << left << setw(19)<< "Name";
  cout << "Balance" << endl;
  cout << "---------------------------------------" << endl;
  for(int i = 0; i < N; i++){
    cout << left << setw(18) << array[i].Name << " ";
    cout << fixed << setprecision(2) << array[i].Balance;
    cout << endl;
  }
}

// This function will find the richest person in the array and print their name
void findRichest(PERSON *array, int &N){
  double max = 0;
  int richest = 0;
  for(int i = 0; i < N; i++){
    if(array[i].Balance > max){
      max = array[i].Balance;
      richest = i;
    }
  }
  cout << "Highest balance: ";
  cout << array[richest].Name << endl;
}

// This function will prompt the user for how much money they want to deposit into their account
void Deposit(PERSON *array, int &N, string custName, float amount){
  for(int i = 0; i < N; i++){
    if(custName == array[i].Name){
      array[i].Balance += amount;
      cout << "Now your new balance is: $" << fixed << setprecision(2) << array[i].Balance << endl;
    }
    else if (i == N){
    cout << "That name does not exist in our system." << endl;
  }
}
}

// This function will overwrite the .txt file
void newCopy(string FILE, PERSON *array, int &N){
  ofstream file;
  file.open(FILE);
  for(int i = 0; i < N; i++){
    file << array[i].Name << " ";
    file << array[i].Balance << endl;
  }
  cout << "File updated..." << endl;
  file.close();
}
