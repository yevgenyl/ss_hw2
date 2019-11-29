/*
 * main.c
 *
 *  Created on: Nov 18, 2019
 *      Author: yevgenylashtchionov
 */
#include <stdio.h>
#include "myBank.h"

int needToRun = 1; // Flag to keep running the menu.

/*
 * Function - showMenu
 * Shows user options menu.
 */
void showMenu(){
	printf(" \t------- Menu -------\nO - Open new account B - Check balance\nD - Deposit \t     "
			"W - Withdraw\nC - Close account    I - Add interest rate\nP - Print all \t     "
			"E - Exit the program\n\n");
}

/*
 * Function - action
 * Takes care of all possible user choices.
 * Parameter1: char type - type of action.
 */
void action(char type) {
	switch(type){
	case 'O':
		openAccount();
		break;
	case 'P':
		printAllAccounts();
		break;
	case 'B':
		checkBalance();
		break;
	case 'D':
		deposit();
		break;
	case 'W':
		withdraw();
		break;
	case 'C':
		closeAccount();
		break;
	case 'I':
		addRate();
		break;
	case 'E':
		closeAll();
		needToRun = 0;
		break;
	default:
		printf("Invalid input '%c' available options: O B D W C I P E\n",type);
		break;
	}
}

int main() {
	initialize(); // Put zeros inside array of data.
	showMenu(); // Show options menu to user.
	while (needToRun) { // Keep showing menu.
		char choice; // User choice.
		printf("Transaction type? \n");
		scanf(" %c", &choice);
		action(choice); // Take care of choice.
	}
	return 0;
}
