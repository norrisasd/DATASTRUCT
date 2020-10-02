#include <stdio.h>
#include <stdlib.h>
#include "interview.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q= createQueue();
	int num;
	int run=1;
	int flag = 0;
	while(run){
		system("CLS");
		if(isEmptyQ(q))
			flag = 0;
		if(flag == 1){
			printf("Numbers in Queue: ");
			displayQ(q);
		}
		
		int x;
		menu();
		scanf("%d",&x);
		fflush(stdin);
		switch(x){
			case 1:
				flag = 1;
				num=getNum();
				if(findNum(q,num)){
					printf("Number is already in queued, Try Again!");
					break;
				}else if(num>MAX){
					printf("The number should be 1 - 50");
					break;
				}else{
					enqueue(q,num);
					printf("You are queued");
				}
				break;
			case 2:
				if(isEmptyQ(q)){
					printf("Queue is Empty");
				}else{
					printf("Number %d, it is now your turn to be interviewed",q->front->data);
					dequeue(q);
				}
				break;
			case 3:
				run =0;
				continue;
				
			default:
				printf("choose wisely!");
		}
		printf("\n");
		system("PAUSE");
	}
	freeQ(q);
	printf("Thank You for Using The Program!");
	return 0;
}

