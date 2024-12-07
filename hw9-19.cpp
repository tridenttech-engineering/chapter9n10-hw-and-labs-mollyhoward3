//Lab9-2.cpp - displays two monthly car payments
  //Created/revised by <Molly Howard> on <11/27/24>
 
 
  #include <iostream>
  #include <cmath>
  #include <iomanip>
  using namespace std;
 
  //function prototype
 double getPayment(int, double, int);
 double getTotal(double, int);

 int main()
 {
 int carPrice = 0;
 int rebate = 0;
 double creditRate = 0.0;
 double dealerRate = 0.0;
 int term = 0;
 double creditPayment = 0.0;
 double dealerPayment = 0.0;
 double totalCredit;
 double totalDealer;

 cout << "Car price (after any trade-in): ";
 cin >> carPrice;
 cout << "Rebate: ";
 cin >> rebate;
 cout << "Credit union rate: ";
 cin >> creditRate;
 cout << "Dealer rate: ";
 cin >> dealerRate;
 cout << "Term in years: ";
 cin >> term;

 //call function to calculate payments
 creditPayment = getPayment(carPrice - rebate,
 creditRate / 12, term * 12);
 dealerPayment = getPayment(carPrice,
 dealerRate / 12, term * 12);
 //function to calculate the totals
 totalCredit = getTotal(creditPayment, term * 12);
 totalDealer + getTotal(dealerPayment, term * 12);
 //display payments/totals
 cout << fixed << setprecision(2) << endl;
 cout << "Credit union payment: $"
 << creditPayment << endl;
 cout << "Total paid after financing through credit union: $" << totalCredit << endl;
 cout << "Dealer payment: $"
 << dealerPayment << endl;
 cout << "Total paid after financing through dealer: $" << totalDealer << endl;
 return 0;
 }//end of main function

 //*****function definitions*****
 double getPayment(int prin,
 double monthRate,
 int months)
 {
 //calculates and returns a monthly payment
 double monthPay = 0.0;
 monthPay = prin * monthRate /
 (1 - pow(monthRate + 1, -months));
 return monthPay;
 } //end of getPayment function

 double getTotal(double monthPay, int months) {
     double total = 0.0;
     double roundedPay = 0.0;

     roundedPay = static_cast<int>((monthPay + .005) / 100.0);
     total = roundedPay * months;
     return total;
 } //end of get total function
