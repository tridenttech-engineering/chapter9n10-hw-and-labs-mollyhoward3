#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
void getPayment(int prin, double monthRate, int months, double monthPay);

int main()
{
    // Declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double creditTotal = 0.0;
    double dealerTotal = 0.0;

    // Get user input
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate (as decimal, e.g., 0.05 for 5%): ";
    cin >> creditRate;
    cout << "Dealer rate (as decimal, e.g., 0.06 for 6%): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment);
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment);

    // Check if either payment calculation is invalid (set to -1)
    if (creditPayment == -1) {
        cout << "Error: Cannot calculate payment with the given credit union rate." << endl;
        return 1; // Exit the program with error
    }
    if (dealerPayment == -1) {
        cout << "Error: Cannot calculate payment with the given dealer rate." << endl;
        return 1; // Exit the program with error
    }

    // Calculate total payments over the loan term
    creditTotal = creditPayment * term * 12;
    dealerTotal = dealerPayment * term * 12;

    // Display monthly payments and total amounts
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union monthly payment: $" << creditPayment << endl;
    cout << "Credit union total payment: $" << creditTotal << endl;
    cout << "Dealer monthly payment: $" << dealerPayment << endl;
    cout << "Dealer total payment: $" << dealerTotal << endl;

    return 0;
} // End of main function    

//***** Function definitions *****
void getPayment(int prin, double monthRate, int months, double monthPay)
{  //calculates and returns a monthly payment
	monthPay = prin * monthRate / 
		(1 - pow(monthRate + 1, -months));
}	//end of getPayment function
