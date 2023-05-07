/*Patrick Abonado
  CS 210
  Project 2*/

#include <iostream>
#include <iomanip>
#include "InvestmentCode.h"

using namespace std;

// define and initialize object constructor
ProfileObject::ProfileObject() {
    m_initialDeposit = 0;
    m_monthlyDeposit = 0;
    m_interest = 0;
    m_years = 0;
}

// define function to set object's initial deposit amount
void ProfileObject::setInitialDeposit(double t_deposit) { m_initialDeposit = t_deposit; }

// define function to get object's initial deposit amount
double ProfileObject::getInitialDeposit() { return m_initialDeposit; }

// define function to set object's monthly deposit amount
void ProfileObject::setMonthlyDeposit(double t_monthlyD) { m_monthlyDeposit = t_monthlyD; }

// define function to get object's monthly deposit amount
double ProfileObject::getMonthlyDeposit() { return m_monthlyDeposit; }

// define function to set object's interest amount
void ProfileObject::setInterest(double t_interest) { m_interest = t_interest; }

// // define function to get object's interest amount
double ProfileObject::getInterest() { return m_interest; }

// define function to set object's years amount
void ProfileObject::setYears(double t_years) { m_years = t_years; }

// define function to get object's years amount
double ProfileObject::getYears() { return m_years; }

// define function that calculates and outputs balance information without deposits 
void ProfileObject::balanceWithoutDeposits(ProfileObject &profile) {

    // output entered information message
    cout << "\t\t" << string(10, '*') << " Entered Information " << string(7, '*') << endl;
    cout << "\t\t" << "Initial Investment Amount: $" << m_initialDeposit << endl;
    cout << "\t\t" << "Annual Interest Amount: " << m_interest << "%" << endl;
    cout << "\t\t" << "Number Of Years: " << m_years << endl;
    cout << "\t\t" << string(38, '*') << endl;

    // assign total with initial deposit
    m_total = m_initialDeposit;

    //  output table headings
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << string(64, '=') << endl;
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << string(64, '-') << endl;

    // loop to create number of rows based on entered years
    for (int i = 0; i < m_years; i++) {

        // calculate interest total
        m_interestTotal = (m_total) * (m_interest / 100);

        // calculate balance total
        m_total += m_interestTotal;

        // output yearly calculations on new lines
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_total << "\t\t\t$" << m_interestTotal << "\n";
    }
    
    // skip 2 lines
    cout << endl << endl;
}

// define function that calculates and outputs balance information with deposits
void ProfileObject::balanceWithDeposits(ProfileObject &profile) {

    // output user entered information message
    cout << "\t\t" << string(10, '*') << " Entered Information " << string(7, '*') << endl;
    cout << "\t\t" << "Initial Investment Amount: $" << m_initialDeposit << endl;
    cout << "\t\t" << "Monthly Deposit Amount: $" << m_monthlyDeposit << endl;
    cout << "\t\t" << "Annual Interest Amount: " << m_interest << "%" << endl;
    cout << "\t\t" << "Number Of Years: " << m_years << endl;
    cout << "\t\t" << string(38, '*') << endl;

    // assign total with initial deposit
    m_total = m_initialDeposit;

    // output table headings
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << string(64, '=') << endl;
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << string(64, '-') << endl;

    // loop to create number of rows based on entered years
    for (int i = 0; i < m_years; i++) {

        // initialize the year's total interest with 0
        m_yearTotalInterest = 0;
        
        // loop to calculate interest totals with 12 monthly deposits
        for (int j = 0; j < m_MONTHS_IN_YEAR; j++) {

            // calculate interest total with monthly deposit amount
            m_interestTotal = (m_total + m_monthlyDeposit) * ((m_interest / 100) / 12);

            // calculate interest total
            m_yearTotalInterest += m_interestTotal;

            // calculate balance total
            m_total += m_monthlyDeposit + m_interestTotal;
        }

        // check if iteration is at 0
        if (i == 0) {

            // ouput this line iteration format
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_total << "\t\t\t$" << m_yearTotalInterest << "\n";
        }

        //everything else
        else {

            // output this line iteration format
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_total << "\t\t$" << m_yearTotalInterest << "\n";
        }
    }

    // skip 2 lines
    cout << endl << endl;
}

