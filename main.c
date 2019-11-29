/*
 * main.c
 *
 *  Created on: Nov 18, 2019
 *      Author: yevgenylashtchionov
 */
#include <stdio.h>
#include "myBank.h"

int needToRun = 1;

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
	initialize();
	while (needToRun) {
		char x;
		printf("Transaction type? \n");
		scanf(" %c", &x);
		action(x);
	}
	return 0;
}
