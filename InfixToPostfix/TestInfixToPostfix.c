#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int run=1,i,k;
	while(run){
		Stack s=newStack();
		Stack s1=newStack();
		int j=0;
		char output[50]={'\0'};
		char item[50];
		system("CLS");
		printf("Input Infix String: ");
		fflush(stdin);
		gets(item);
		if(!validInput(item)){
			printf("Invalid Input\n");
			system("PAUSE");
			continue;
		}
		infixToPostfix(s,item,output);
		printf("\nPostfix Evaluation:\nPostFix: %s",output);
		printf("\nResult: %.2f",postfixEvaluation(s,output));
		printf("\n");
		freeS(s);
		freeS(s1);
		run = again();
	}
	return 0;
}


