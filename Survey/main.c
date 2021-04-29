#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Statistician answer;
	Statistician freq;
	int freqs=0,i;
	int SIZE = 10,count = 0,x,item;
	freq = (Statistician)malloc(freqs*sizeof(int));
	answer = (Statistician)malloc(sizeof(int)*SIZE);
	while(1){
		system("CLS");
		printf("Survey Data\n");
		printf("Current Response Count: %d\n",count);
		printf("DATA: ");
		displayRes(answer,count);
		printf("\n");
		Menu();
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Input Response: ");
				scanf("%d",&item);
				while(item > 9 || item <0){
					printf("Error! Input Response Again: ");
					scanf("%d",&item);
				}
				add(answer,&count,&SIZE,item);
				break;
			case 2:
				if(count == 0)
					printf("No Data!");
				else
					printf("Mean: %.2f",mean(answer,count));
				break;
			case 3:
				if(count == 0)
					printf("No Data!");
				else
					printf("Median: %.2f",median(answer,count));
				break;
			case 4:
				if(count == 0)
					printf("No Data!");
				else{
					mode(freq,&freqs,answer,count);
					printf("Mode: ");
					for(i=0;i<freqs;i++){
						printf("%d ",freq[i]);
					}
				}
				break;
			case 5:
				if(count == 0)
					printf("No Data!");
				else
					printf("Max: %d",max(answer,count));
				break;
			case 6:
				if(count == 0)
					printf("No Data!");
				else
					printf("Min: %d",min(answer,count));
				break;
			case 7:
				if(count == 0)
					printf("No Data!");
				else
					printf("Range: %d",range(answer,count));
				break;
			case 8:
				if(count == 0)
					printf("No Data!");
				else{
					printf("\t\t\t\t\tH I S T O G R A M \n");
					histogram(answer,count);
				}
				break;
			case 9:
				return 0;
			default:
				printf("Choose Wisely!");
		}
		printf("\n");
		system("PAUSE");
		
	}
	
	return 0;
}


