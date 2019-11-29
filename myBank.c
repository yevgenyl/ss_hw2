/*
 * myBank.c
 *
 *  Created on: Nov 18, 2019
 *      Author: yevgenylashtchionov
 */
#include <stdio.h>
#include "myBank.h"

double data[2][BANK_SIZE]; // Two dimensional array which contains bank data. First row: open/close, Second row: balance.

/*
 * Function - round
 * Given a real number (double), the function return the number after setting decimal precision with two digits after floating point.
 * Parameter1 - double num: the number from input.
 * Return - double: the new number.
 */
double round(double num) {
	long value = (long) (num * 100);
	return (double) value / 100;
}

/*
 * Function - initialize
 * The function initializes 'data' array with zeros.
 */
void initialize() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < BANK_SIZE; j++)
			data[i][j] = 0.0;
}

/*
 * Function - openAccount
 * The function opens new bank account.
 * User will be asked to deposit initial sum.
 */
void openAccount() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	double init = 0.0; // Initial sum.
	int found = 0;
	while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
		if (!(int) data[row][column]) { // If account number is available.
			found = 1;
			printf("Initial deposit?: \n");
			if (scanf(" %lf", &init) && init >= 0) { // If user input is valid.
				data[row][column] = 1.0; // Set account status - open (1).
				data[row + 1][column] = round(init); // Set initial sum for new account.
				printf("Account No %d\n", account + column); // Print account data.
				break;
			} else {
				printf("Only real positive numbers allowed..\n ");
				break;
			}
		}
		column++;
	}
	if(!found){
		printf("No available accounts..\n");
	}
}

/*
 * Function - checkBalance
 * The function check balance for existing account.
 * User will be asked to type account number.
 */
void checkBalance() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	int accountID = 0; // Account number from user input.
	printf("Account number?: \n");
	if (scanf(" %d", &accountID) && accountID >= account && accountID <= 950) { // Get account number from user.
		while (column < BANK_SIZE) { // If account number is available.
			if (accountID == (column + account)) { // If we found the account.
				if ((int) data[row][column]) { // If account is open.
					printf("Balance for account %d is %0.2lf\n", accountID,
							data[row + 1][column]);
				} else {
					printf("Error - Account doesn't exist\n");
				}
				break;
			}
			column++;
		}
	} else {
		printf("Only integers between 901 - 950 allowed..\n ");
	}
}

/*
 * Function - deposit
 * Deposit for existing account.
 * User will be asked to type account number and amount to deposit.
 */
void deposit() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	int accountID = 0; // Account number.
	double amount = 0.0; // Amount to deposit.
	printf("Account number?: \n");
	if (scanf(" %d", &accountID) && accountID >= account && accountID <= 950) { // If user input is valid.
		printf("Amount?: \n");
		if (scanf(" %lf", &amount) && amount >= 0) { // If user input for amount is valid.
			while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
				if (accountID == (column + account)) { // If we found the account.
					if ((int) data[row][column]) { // If account status is open.
						data[row + 1][column] += round(amount); // Add amount from user input to current balance.
						printf("Balance for account %d is %0.2lf\n", accountID,
								data[row + 1][column]);
					} else {
						printf("Error - Account doesn't exist\n");
					}
					break;
				}
				column++;
			}
		} else {
			printf("Only real positive numbers allowed..\n ");
		}
	} else {
		printf("Only integers between 901 - 950 allowed..\n ");
	}
}

/*
 * Function - withdraw
 * withdraw for existing account.
 * User will be asked to type account number and amount to withdraw.
 */
void withdraw() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	int accountID = 0; // Account number.
	double amount = 0.0; // Amount to withdraw.
	printf("Account number?: \n");
	if (scanf(" %d", &accountID) && accountID >= account && accountID <= 950) { // If user input is valid.
		printf("Amount?: \n");
		if (scanf(" %lf", &amount) && amount >= 0) { // If user input is valid.
			while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
				if (accountID == (column + account)) {
					if ((int) data[row][column]) { // If account exist
						if (data[row + 1][column] + EPSILON >= amount) { // If there is enough balance for withdraw
							data[row + 1][column] -= (round(amount) - EPSILON); // Subtract withdraw amount from total balance
							printf(
									"Updated balance for account %d after withdraw is %0.2lf\n",
									accountID, data[row + 1][column]);
						} else {
							printf(
									"Illegal operation - not enough balance for withdraw\n");
						}
					} else {
						printf("Error - Account doesn't exist\n");
					}
					break;
				}
				column++;
			}
		} else {
			printf("Only real positive numbers allowed..\n ");
		}
	} else {
		printf("Only integers between 901 - 950 allowed..\n ");
	}
}

/*
 * Function - closeAccount
 * Close account specified by user.
 * User will be asked for account number to close.
 */
void closeAccount() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	int accountID = 0; // Account number.
	int found = 0; // if account is found.
	printf("Acount number?: ");
	if (scanf(" %d", &accountID) && accountID >= account && accountID <= 950) { // If user input is valid.
		while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
			if (accountID == (column + account)) { // If account was found.
				found = 1;
				if ((int) data[row][column]) { // If account is open.
					data[row][column] = 0.0; // Change status to closed.
					data[row + 1][column] = 0.0; // Change balance to zero.
					printf("Successfully closed account %d\n", accountID);
				} else {
					printf("Error - Account doesn't exist\n");
				}
				break;
			}
			column++;
		}
		if (!found) {
			printf("Error - Account doesn't exist\n");
		}
	} else {
		printf("Only integers between 901 - 950 allowed..\n ");
	}
}

/*
 * Function - addRate
 * Add Interest rate to all accounts.
 */
void addRate() {
	int row = 0, column = 0;
	double interest_rate = 0.0; // Interest rate (in %).
	printf("Interest rate?: \n");
	if (scanf(" %lf", &interest_rate) && interest_rate >= 0) { // If user input is valid.
		while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
			if ((int) data[row][column]) { // If account is open
				data[row + 1][column] *= (1 + ((interest_rate) / 100));
			}
			column++;
		}
	} else {
		printf("Only real positive numbers allowed..\n ");
	}
}

/*
 * Function - closeAll
 * Close all accounts (put zeros in 'data' array).
 */
void closeAll() {
	initialize();
}

/*
 * Function - printAllAccounts
 * Print all open accounts and balances.
 */
void printAllAccounts() {
	int row = 0, column = 0, account = 901; // account - bank starting point (901).
	while (column < BANK_SIZE) { // While row limit (50) is not exceeded.
		if ((int) data[row][column]) { // If account is open.
			printf("Account No %d - Balance %0.2lf\n", account + column,
					data[row + 1][column]);
		}
		column++;
	}
}
