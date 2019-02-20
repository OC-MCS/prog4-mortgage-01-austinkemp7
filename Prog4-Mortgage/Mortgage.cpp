// implementation file for Mortgage class
//=============================================================================
// Austin Kemp
// 20 February 2019
// Description: File containing the definitions of the functions in the class
//=============================================================================
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "Mortgage.h"

// Default Constructor
Mortgage::Mortgage()
{
	loanAmount = 0.0;
	interestRate = 0.0;
	numYears = 0;
	monthlyPayment = 0.0;
}
// Function: getLoanAmount, returns the loan amount
// Parameters: none
// return: loanAmount, double holding the loan amount
double Mortgage::getLoanAmount() const
{
	return loanAmount;
}

// Function: getNumYears, returns the number of years on the loan
// Parameters: none
// return: numYears, int holding the number of years
int Mortgage::getNumYears() const
{
	return numYears;
}

// Function: setLoanAmount, sets the loan amount to value given by the user
// Parameters:
// loan: double holding the amount to change the loan to
// return: none
void Mortgage::setLoanAmount(double loan)
{
	loanAmount = loan;
}

// Function: setInterestRate, sets the interest rate to the value
// given by the user
// Parameters:
// rate: double holding amount to change the rate to
// return: none
void Mortgage::setInterestRate(double rate)
{
	interestRate = rate;
}

// Function: setNumYears, sets the number of years of the loan
// Parameters:
// years: int holding the amount to change the number of year to
// return: none
void Mortgage::setNumYears(int years)
{
	numYears = years;
}

// Function: getInterestRate, returns the interest rate of the loan
// Parameters: none
// return: interestRate, double holding the interest rate
double Mortgage::getInterestRate() const
{
	return interestRate;
}

// Function: getTerm, calculates and returns the term of the loan
// Parameters: none
// return: term, double holding the calculated term
double Mortgage::getTerm() const
{
	double term;
	term = pow((1 + (interestRate / 12.0)), (12.0 * numYears));
	return term;
}

// Function: getMonthlyPayment, calculates and returns the monthly payment
// on the loan
// Parameters: none
// return: payment, double holding the calculated monthly payment
double Mortgage::getMonthlyPayment() const
{
	double payment;
	payment = (loanAmount * (interestRate / 12.0) * getTerm()) / (getTerm() - 1);
	payment = round(payment * 100.0) / 100.0;
	return payment;
}

// Function: getAmountPaid, calculates and returns the total amount paid
// by the end of the loan period
// Parameters: none
// return: amountPaid, double holding the total amount paid
double Mortgage::getAmountPaid() const
{
	double amountPaid;
	amountPaid = 12.0 * numYears * getMonthlyPayment();
	return amountPaid;
}
