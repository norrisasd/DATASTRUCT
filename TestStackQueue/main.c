#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue InputQ=createQueue();
	Queue OutputQ=createQueue();
	Stack InputS=createStack();
	Stack OutputS=createStack();
	int item,run=1,flag=0;
	while(run){
		system("CLS");
		if(flag == 1){
			printf("Input Stack: ");
			displayS(InputS);
			printf("Input Queue: ");
			displayQ(InputQ);
		}
		if(checker(InputS,InputQ) && flag == 1){
			system("CLS");
			printf("Input STACK & QUEUE are now Empty!");
			printf("Output Stack: ");
			displayS(OutputS);
			freeS(OutputS);
			printf("Output Queue: ");
			displayQ(OutputQ);
			freeQ(OutputQ);
			run = Run();
			flag=0;
			continue;
		}
		int x,y;
		menu();
		scanf("%d",&x);
		switch(x){
			case 1:
				flag =1;
				item =getItem();
				enqueue(InputQ,item);
				push(InputS,item);
				break;
			case 2:
				if(isEmptyS(InputS) && isEmptyQ(InputQ)){
					printf("Input Stack and Queue are Empty!\n");
					break;
				}
				printf("Delete Success!");
				item = dequeue(InputQ);
				enqueue(OutputQ,item);
				item  = pop(InputS);
				push(OutputS,item);
				break;
			case 3:
				run = 0;
				printf("Thank You For Using The Program");
				continue;
			default:
				printf("Choose Wisely!");
		}
		printf("\n\n");
		system("PAUSE");
	}
	printf("Thank You for Using The Program");
	return 0;
}
