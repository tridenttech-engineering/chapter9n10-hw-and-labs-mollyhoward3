#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
double getPayment(int, double, int);

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

    // User input
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

    // Calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);
    
    // Check if either payment calculation returned -1 (error)
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
double getPayment(int prin, double monthRate, int months)
{
    // Check if the interest rate is 0 and avoid division by zero
    if (monthRate == 0) {
        return prin / months; // If interest rate is 0, simply divide principal by number of months
    }

    // Calculate monthly payment, check denominator for zero
    double denominator = 1 - pow(1 + monthRate, -months);
    if (denominator == 0) {
        return -1; // Error: division by zero in the formula
    }

    double monthPay = prin * monthRate / denominator;
    return monthPay;
} // End of getPayment function
