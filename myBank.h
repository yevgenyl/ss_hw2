/*
 * myBank.h
 *
 *  Created on: Nov 18, 2019
 *      Author: yevgenylashtchionov
 */

#ifndef MYBANK_H_
#define MYBANK_H_
#define BANK_SIZE 50
#define EPSILON 0.0000000001 // Epsilon for comparing doubles.

extern double data[2][BANK_SIZE]; // Two dimensional array which contains bank data. First row: open/close, Second row: balance.

void initialize();
void openAccount();
void checkBalance();
void deposit();
void withdraw();
void closeAccount();
void addRate();
void closeAll();
void printAllAccounts();

#endif /* MYBANK_H_ */
