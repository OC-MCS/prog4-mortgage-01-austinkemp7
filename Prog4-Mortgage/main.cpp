
// main goes here. Code that *uses* the Mortgage class
// goes in this file
//=============================================================================
// Austin Kemp
// 20 February 2019
// Description: Program that calculates the monthly payment of a home mortgage
// and displays the total amount paid at the end of the period and the monthly 
// payment.
//=============================================================================
#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;
#include "Mortgage.h"

// Function Prototypes
bool parseInt(string sval, int& val);
bool parseFloat(string sval, double& val);
void checkInput(string&, double&);
void checkInput(string&, int&);

int main()
{
	Mortgage mortgageObject;
	double loan = 0.0;
	string stringInput;
	double rate = 0.0;
	double payment = 0.0;
	double total = 0.0;
	int years = 0;

	cout << "How much is the loan? ";
	getline(cin, stringInput);
	checkInput(stringInput, loan);
	mortgageObject.setLoanAmount(loan);
	cout << endl;

	cout << "How much is the annual interest rate? (in %) ";
	getline(cin, stringInput);
	checkInput(stringInput, rate);
	mortgageObject.setInterestRate(rate);
	cout << endl;

	cout << "How many years is the loan? ";
	getline(cin, stringInput);
	checkInput(stringInput, years);
	mortgageObject.setNumYears(years);
	cout << endl;

	payment = mortgageObject.getMonthlyPayment();

	cout << "Payment: $" << payment << endl;
	total = mortgageObject.getAmountPaid();
	cout << "Total Amount Paid: $" << setprecision(2) << fixed << total << endl;

	return 0;
}

// Function: parseFloat, converts a valid string to a double and throws
// an exception if the string cannot be converted to a double
// Parameters:
// sval: string input by user to be converted to a double if valid
// val: double to hold the converted string
// return: success, boolean that indicates whether the string was
// successfully converted to a double
bool parseFloat(string sval, double &val)
{
	double num;
	bool success = true;
	try
	{
		num = stof(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

// Function: parseInt, converts a valid string to an int and throws an 
// exception if the string cannot be converted to an integer
// Parameters:
// sval: string input by user to be converted to an int if valid
// val: integer to hold the converted string
// return: success, boolean that indicates whether the string was 
// successfully converted to a integer
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

// Function: checkInput, checks the input of the user and converts the
// string to a double if it is valid and displays an error message if 
// it is invalid
// Parameters:
// stringInput: string input by user to be converted to a double if
// valid
// num: double to hold the converted string
// return: none
void checkInput(string& stringInput, double& num)
{
	while (!parseFloat(stringInput, num))
	{
		cout << "Invalid amount. Enter a valid $ amount: ";
		getline(cin, stringInput);
	}
	while (num < 0 || !parseFloat(stringInput, num))
	{
		cout << "The amount entered is negative. Try another value: ";
		getline(cin, stringInput);
		parseFloat(stringInput, num);
	}
}

// Function: checkInput, checks the input of the user and converts the
// string to am int if it is valid and displays an error message if 
// it is invalid
// Parameters:
// stringInput: string input by user to be converted to an int if
// valid
// num: int to hold the converted string
// return: none
void checkInput(string& stringInput, int& num)
{
	while (!parseInt(stringInput, num))
	{
		cout << "Invalid amount. Enter a valid $ amount: ";
		getline(cin, stringInput);
	}
	while (num < 0 || !parseInt(stringInput, num))
	{
		cout << "The amount entered is negative. Try another value: ";
		getline(cin, stringInput);
		parseInt(stringInput, num);
	}
}