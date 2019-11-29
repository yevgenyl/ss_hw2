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

double round(double num) {
	long value = (long) (num * 100);
	return (double) value / 100;
}

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
				printf("Initial deposit?: \n");
				if (scanf(" %lf", &init)) {
					data[row][column] = 1.0;
					data[row + 1][column] = round(init);
					printf("Account No %d\n", account + column);
					currentSize++;
					break;
				} else {
					printf("Only real numbers allowed..\n ");
					break;
				}
			}
			column++;
		}
	} else {
		printf("No available accounts..\n");
	}
}

void checkBalance() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	printf("Account number?: \n");
	if (scanf(" %d", &accountID)) {
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
	} else {
		printf("Only integers allowed..\n ");
	}
}

void deposit() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	double amount = 0.0;
	printf("Account number?: \n");
	if (scanf(" %d", &accountID)) {
		printf("Amount?: \n");
		if (scanf(" %lf", &amount)) {
			while (column < BANK_SIZE) {
				if (accountID == (column + account)) {
					if ((int) data[row][column]) {
						data[row + 1][column] += round(amount);
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
			printf("Only real numbers allowed..\n ");
		}
	} else {
		printf("Only integers allowed..\n ");
	}
}

void withdraw() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	double amount = 0.0;
	printf("Account number?: \n");
	if (scanf(" %d", &accountID)) {
		printf("Amount?: \n");
		if (scanf(" %lf", &amount)) {
			while (column < BANK_SIZE) {
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
			printf("Only real numbers allowed..\n ");
		}
	} else {
		printf("Only integers allowed..\n ");
	}
}

void closeAccount() {
	int row = 0, column = 0, account = 901;
	int accountID = 0;
	int found = 0;
	printf("Acount number?: ");
	if (scanf(" %d", &accountID)) {
		while (column < BANK_SIZE) {
			if (accountID == (column + account)) {
				found = 1;
				if ((int) data[row][column]) {
					data[row][column] = 0.0;
					data[row + 1][column] = 0.0;
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
		printf("Only integers allowed..\n ");
	}
}

void addRate() {
	int row = 0, column = 0;
	double interest_rate = 0.0;
	printf("Interest rate?: \n");
	if (scanf(" %lf", &interest_rate)) {
		while (column < BANK_SIZE) {
			if ((int) data[row][column]) { // If account is open
				data[row + 1][column] *= (1 + ((interest_rate) / 100));
			}
			column++;
		}
	} else {
		printf("Only real numbers allowed..\n ");
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
