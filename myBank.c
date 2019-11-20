/*
 * myBank.c
 *
 *  Created on: Nov 18, 2019
 *      Author: yevgenylashtchionov
 */
#include <stdio.h>
#include "myBank.h"

double data[2][BANK_SIZE];
int currentSize = 0;

void initialize() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < BANK_SIZE; j++)
			data[i][j] = 0.0;
}

void openAccount() {
	int row = 0, column = 0, account = 901;
	double init = 0.0;
	if (currentSize <= 50) {
		while (column < BANK_SIZE) {
			if (!(int) data[row][column]) {
				printf("Please enter initial deposit sum for new account: ");
				scanf(" %lf", &init);
				data[row][column] = 1.0;
				data[row + 1][column] = init;
				printf("Account No %d\n", account + column);
				currentSize++;
				break;
			}
			column++;
		}
	} else {
		printf("No available accounts..");
	}
}

void checkBalance() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	printf("Please enter account number to check balance: ");
	scanf(" %d", &accountID);
	while (column < BANK_SIZE) {
		if (accountID == (column + account)) {
			if ((int) data[row][column]) {
				printf("Balance for account %d is %0.2lf\n", accountID,
						data[row + 1][column]);
			} else {
				printf("Error - Account doesn't exist\n");
			}
			break;
		}
		column++;
	}
}

void deposit() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	double amount = 0.0;
	printf("Please enter account number for deposit: ");
	scanf(" %d", &accountID);
	printf("Please enter deposit amount: ");
	scanf(" %lf", &amount);
	while (column < BANK_SIZE) {
		if (accountID == (column + account)) {
			if ((int) data[row][column]) {
				data[row + 1][column] += amount;
				printf("Balance for account %d is %0.2lf\n", accountID,
						data[row + 1][column]);
			} else {
				printf("Error - Account doesn't exist\n");
			}
			break;
		}
		column++;
	}
}

void withdraw() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	double amount = 0.0;
	printf("Please enter account number for withdraw: ");
	scanf(" %d", &accountID);
	printf("Please enter withdraw amount: ");
	scanf(" %lf", &amount);
	while (column < BANK_SIZE) {
		if (accountID == (column + account)) {
			if ((int) data[row][column]) { // If account exist
				if (data[row + 1][column] >= amount) { // If there is enough balance for withdraw
					data[row + 1][column] -= amount; // Subtract withdraw amount from total balance
					printf(
							"Updated balance for account %d  after withdraw is %0.2lf\n",
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
}

void closeAccount() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	printf("Please enter account number to close: ");
	scanf(" %d", &accountID);
	while (column < BANK_SIZE) {
		if (accountID == (column + account)) {
			if ((int) data[row][column]) {
				data[row][column] = 0.0;
				data[row+1][column] = 0.0;
				printf("Successfully closed account %d\n",accountID);
			} else {
				printf("Error - Account doesn't exist\n");
			}
			break;
		}
		column++;
	}
}

void addRate() {
	int row = 0, column = 0;
	double interest_rate = 0.0;
	printf("Please enter interest rate: ");
	scanf(" %lf", &interest_rate);
	while (column < BANK_SIZE) {
		if ((int) data[row][column]) { // If account is open
			data[row+1][column] *= (1+((interest_rate)/100));
		}
		column++;
	}
}

void closeAll() {
	initialize();
}

void printAllAccounts() {
	int row = 0, column = 0, account = 901;
	while (column < BANK_SIZE) {
		if ((int) data[row][column]) {
			printf("Account No %d - Balance %0.2lf\n", account + column,
					data[row + 1][column]);
		}
		column++;
	}
}
