#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int run=1;
	while(run!=0){
		Stack s= newStack();
		stackItem str[50];
		system("CLS");
		printf("STACK LINK\n");
		printf("Input String: ");
		fflush(stdin);
		gets(str);
		if(!validInput(str)){
			printf("Invalid Input!! Try Again\n");
			system("PAUSE");
			continue;
		}else{
			if(!isValid(s,str))
				printf("String Mismatch!");
			else
				printf("String Match!");
		}
		if(isEmpty(s) == 1)
			printf("\nStack Empty");
		else{
			printf("\nRemaining Stack: ");
			display(s);
		}
		freeStack(s);
		run = again();
	}
	return 0;
}

