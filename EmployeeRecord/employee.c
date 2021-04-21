#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "employee.h"

void gotoxy(int x, int y)
{
	COORD p = {x, y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void menu(){
		printf("\n1. Create and add Record");
		printf("\n2. Calculate Records");
		printf("\n3. Print Records");
		printf("\n4. Print Summary");
		printf("\n5. Exit");
		printf("\n\nInput Choice: ");
}
void readName(payrecord payroll[], int i){
	
	printf("Input First name: "); 
	fflush(stdin);
	gets(payroll[i].name.first);
	printf("Input Last name: ");  
	fflush(stdin);
	gets(payroll[i].name.last);
	printf("Input Middle name: "); 
	fflush(stdin);
	gets(payroll[i].name.middle);
	printf("Input Hours of work(weekly): ");
	scanf("%f",&payroll[i].hours);
	printf("Input Rate: ");
	scanf("%f",&payroll[i].rate);
	payroll[i].id = i+1;
}
void readRecords(payrecord payroll[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("Input Details!\n");
		readName(payroll,i);
		
	}
}
void printName(payrecord payroll[], int i){
	payroll[i].name.last[0]=toupper(payroll[i].name.last[0]);
	payroll[i].name.first[0]=toupper(payroll[i].name.first[0]);
	payroll[i].name.middle[0]=toupper(payroll[i].name.middle[0]);
	gotoxy(1,15+i);printf("%d",payroll[i].id);//id
	gotoxy(5,15+i);printf("%s, %s %s",payroll[i].name.last,payroll[i].name.first,payroll[i].name.middle);//name
	gotoxy(33,15+i);printf("%.2f",payroll[i].hours);
	gotoxy(48,15+i);printf("%.2f",payroll[i].rate);
	gotoxy(60,15+i);printf("%.2f",payroll[i].regular);
	gotoxy(74,15+i);printf("%.2f",payroll[i].overtime);
	gotoxy(88,15+i);printf("%.2f",payroll[i].tax_withheld);
	gotoxy(103,15+i);printf("%.2f",payroll[i].net);
	gotoxy(115,15+i);printf("%.2f",payroll[i].gross);
}
void printRecords(payrecord payroll[], int n){
	int i;
	gotoxy(60,10);printf(" R  E  C  O  R  D  S");
	gotoxy(1,12);printf("ID#");
	gotoxy(13,12);printf("Name");
	gotoxy(33,12);printf("Hrs/week");
	gotoxy(48,12);printf("Rate");
	gotoxy(60,12);printf("Regular");
	gotoxy(74,12);printf("Overtime");
	gotoxy(88,12);printf("Tax Withheld");
	gotoxy(103,12);printf("Net");
	gotoxy(115,12);printf("Gross");
	for(i=0;i<n;i++){
		printName(payroll,i);
	}
	
	
}
double calcRecords(payrecord payroll[], int n, double *taxptr){
	
	int i;
	float excess,tax;
	double total;
	for(i =0;i<n;i++){
		if(payroll[i].hours >40){
			payroll[i].regular=payroll[i].rate*40;
			excess = payroll[i].hours - 40;
			payroll[i].overtime = payroll[i].rate * excess*1.5;
		}else{
			payroll[i].overtime = 0;
			payroll[i].regular = payroll[i].rate * payroll[i].hours;
		}
		payroll[i].gross = payroll[i].overtime + payroll[i].regular;
		
		if(payroll[i].gross > 1000){
			tax = 0.33;
		}else if (payroll[i].gross>500){
			tax = 0.28;
		}else{
			tax = 0.15;
		}
		payroll[i].tax_withheld = payroll[i].gross * tax;
		payroll[i].net = payroll[i].gross - payroll[i].tax_withheld;
		(*taxptr) += payroll[i].tax_withheld;
		total +=payroll[i].gross;
	}
	return total;
}
void printSummary(double gross, double tax){
	
	printf("Total Gross: %0.2f\n",gross);
	printf("Total Tax: %0.2f\n",tax);
	
}



