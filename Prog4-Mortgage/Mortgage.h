#pragma once
// header file for Mortgage class
//=============================================================================
// Austin Kemp
// 20 February 2019
// Description: Header file containing the function declarations and 
// class constructor declaration
//=============================================================================
#pragma once

class Mortgage
{
private:
	double loanAmount;
	double interestRate;
	int numYears;
	double monthlyPayment;
	double getTerm() const;
public:
	Mortgage(); // Class constructor
	void setLoanAmount(double loanAmount);
	void setInterestRate(double interestRate);
	void setNumYears(int numYears);
	double getMonthlyPayment() const;
	double getAmountPaid() const;
	double getLoanAmount() const;
	int getNumYears() const;
	double getInterestRate() const;
};

