#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	payrecord payroll[100];
	int i,n=0;
	double tax,gross = 0;
	while(1){
		int x;
		system("cls");
		menu();
		scanf("%d",&x);
		fflush(stdin);
		switch(x){
			case 1:
				system("cls");
				printf("Input Number of Records: ");
				scanf("%d",&n);
				readRecords(payroll,n);
				break;
			case 2:
				if(n ==0){
					printf("There is no record to calculate!");
					break;
				}
				gross =calcRecords(payroll,n,&tax);
				printf("Success Calculating!");
				break;
			case 3:
				if(n==0 || gross == 0){
					printf("Please Input or Calculate records first !");
					break;
				}
				printRecords(payroll,n);
				break;
			case 4:
				printSummary(gross,tax);
				break;
			case 5:
				printf("Thank You for using the program !");
				return 0;
			default:
				printf("Error!! Try again!");
		}
		
		printf("\n");
		printf("\n");
		system("PAUSE");
	}
	return 0;
}


