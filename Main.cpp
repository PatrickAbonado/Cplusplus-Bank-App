/*Patrick Abonado
  CS 210
  Project 2*/

#include <iostream>
#include <iomanip>
#include "InvestmentCode.h"

using namespace std;

// declare input variables
int userInput = 0;
double initial = 0;
double deposit = 0;
double interest = 0;
double years = 0;

// define function to output menu options
int Menu() {
    
    // output menu options message
    cout << "\t\t" << string(66, '+') << endl;
    cout << "\t\t" << string(23, '+') << "ENTER A MENU NUMBER" << string(24, '+') << endl;
    cout << "\t\t+ 1 - Enter Financial Information" << string(32, ' ') << "+" << endl;
    cout << endl;
    cout << "\t\t+ 2 - Show Balances Without Deposits" << string(29, ' ') << "+" << endl;
    cout << endl;
    cout << "\t\t+ 3 - Show Balances With Deposits" << string(32, ' ') << "+" << endl;
    cout << endl;
    cout << "\t\t+ To Exit Choose Any Other None Space Character Then Press Enter +" << endl;
    cout << "\t\t" << string(66, '+') << endl;
    cout << "\t\t" << string(66, '+') << endl;

    // store user input choice
    cin >> userInput;

    return userInput;
}

// define function that outputs required financial information
void requiredInfo() {
    
    // output required financial information message
    cout << "\t\t" << string(39, '*') << endl;
    cout << "\t\t" << string(10, '*') << " Required Information " << string(7, '*') << endl;
    cout << "\t\t" << "Initial Investment Amount" << endl;
    cout << "\t\t" << "Monthly Deposit Amount" << endl;
    cout << "\t\t" << "Annual Interest Amount" << endl;
    cout << "\t\t" << "Number Of Years" << endl;
    cout << "\t\t" << string(39, '*') << endl;
    cout << "\t\t" << string(39, '*') << endl;
    cout << endl << endl;
}

// define function to take initial investment amount
double investmentInfo() {

    // loop to output message and take input until valid input is entered
    while (cout << "Initial Investment Amount: $" && !(cin >> initial)) {

        // clear input stream
        cin.clear();

        // discard previous input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return initial;
}

// define function to take monthly deposit amount 
double monthDepoInfo() {
    while (cout << "Monthly Deposit Amount: $" && !(cin >> deposit)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return deposit;
}

// define function to take interest amount 
double interestInfo() {
    while (cout << "Annual Interest Amount: %" && !(cin >> interest)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return interest;
}

// define function to take years amount
double yearsInfo() {
    while (cout << "Number Of Years: " && !(cin >> years)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return years;
}

int main()
{
    // create object
    ProfileObject profile;

    // loop to run program options till program ended
    while (true) {

        // call menu function
        Menu();

        // check if user input is 1
        if (userInput == 1) {

            // clear screen
            system("cls");

            // call required information message function 
            requiredInfo();

            // call initial investment function
            investmentInfo();

            // set object's initial investment amount
            profile.setInitialDeposit(initial);

            // call monthly deposit function
            monthDepoInfo();

            // set object's monthly deposit amount
            profile.setMonthlyDeposit(deposit);

            // call interest function
            interestInfo();

            // set object's interest amount
            profile.setInterest(interest);

            // call years function
            yearsInfo();

            // set object's years amount
            profile.setYears(years);

            system("cls");

        }

        // check if user input is 2
        else if (userInput == 2) {
            system("cls");

            // call balance without deposits function for object's entered information
            profile.balanceWithoutDeposits(profile);
        }

        // check if user input is 3
        else if (userInput == 3) {
            system("cls");

            // call balance with deposit function for object's entered information
            profile.balanceWithDeposits(profile);
        }
        else {

            // output end program message
            cout << endl << endl << endl << "Have A Nice Day." << endl << endl << endl;

            // end program
            break;
        }
    }
    return 0;
}