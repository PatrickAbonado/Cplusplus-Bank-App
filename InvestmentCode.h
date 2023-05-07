/*Patrick Abonado
  CS 210
  Project 2*/

#pragma once

// declare object class
class ProfileObject {

// declare public object functions
public:
    ProfileObject();
    void setInitialDeposit(double t_initialDeposit);
    double getInitialDeposit();
    void setMonthlyDeposit(double t_monthlyDeposit);
    double getMonthlyDeposit();
    void setInterest(double t_interest);
    double getInterest();
    void setYears(double t_years);
    double getYears();
    void balanceWithoutDeposits(ProfileObject &profile);
    void balanceWithDeposits(ProfileObject &profile);

// declare private object variables
private:
    double m_initialDeposit = 0;
    double m_monthlyDeposit = 0;
    double m_interest = 0;
    double m_years = 0;
    double m_total = 0;
    double m_interestTotal = 0;
    double m_yearTotalInterest = 0;
    const double m_MONTHS_IN_YEAR = 12.0;
};

