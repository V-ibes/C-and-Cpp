#include<stdio.h>
#include<stdbool.h>
#include <iostream>
#include <cctype>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include "money.h"
using namespace std;


void checkout_taxCalc() {
    double amount, taxRate;

    // Ask the user to enter an amount
    printf("Enter an amount: $");
    scanf("%lf", &amount); // Use scanf_s to get the double value

    // Ask the user to enter the tax rate (as a percentage)
    printf("Enter the tax rate (as a percentage): ");
    scanf("%lf", &taxRate); // Use scanf_s to get the double value

    // Calculate the tax based on the entered tax rate
    double tax = amount * (taxRate / 100);

    // Calculate the total amount with tax
    double totalAmount = amount + tax;

    // Display the total amount with tax added using printf (2 decimal places)
    printf("With tax added: $%.2lf\n", totalAmount);

}


void bill_split() {
    int amount;

    // Ask the user to enter a dollar amount
    printf("Enter a dollar amount: ");
    scanf("%d", &amount); // Use scanf_s to get the integer value

    // Calculate the number of $20 bills
    int twentyBills = amount / 20;
    amount %= 20; // Update the remaining amount

    // Calculate the number of $10 bills
    int tenBills = amount / 10;
    amount %= 10; // Update the remaining amount

    // Calculate the number of $5 bills
    int fiveBills = amount / 5;
    amount %= 5; // Update the remaining amount

    // Calculate the number of $1 bills
    int oneBills = amount;

    // Display the results
    printf("\n$20 bills: %d\n", twentyBills);
    printf("$10 bills: %d\n", tenBills);
    printf("$5 bills: %d\n", fiveBills);
    printf("$1 bills: %d\n", oneBills);


}