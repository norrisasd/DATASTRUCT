#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Set s1 = initialize();
	Set s2 = initialize();
	Set result = initialize();
	int x,x1,num;
	while(1){
		system("CLS");
		menu();
		printf("Choose: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("What Set ? [(1)Set1, (2)Set2 , (3)Result]: ");
				scanf("%d",&x1);
				switch(x1){
					case 1:
						if(count(s1) == 0)
							printf("Set is Empty");
						else
							display(s1);
						break;
					case 2:
						if(count(s1) == 0)
							printf("Set is Empty");
						else
							display(s2);
						break;
					case 3:
						if(count(s1) == 0)
							printf("Set is Empty");
						else
							display(result);
						break;
					default:
						printf("Choose Wisely!");
				}
				break;
			case 2:
				printf("What Set ? [(1)Set1, (2)Set2]: ");
				scanf("%d",&x1);
				switch(x1){
					case 1:
						printf("Input Number: ");
						scanf("%d",&num);
						s1 = add(s1,num);
						printf("Successfully Added !");
						break;
					case 2:
						printf("Input Number: ");
						scanf("%d",&num);
						s2 = add(s2,num);
						printf("Successfully Added !");
						break;
					default:
						printf("Choose Wisely!");
				}
				break;
			case 3:
				printf("Find Element in Set ? [(1)Set1, (2)Set2] ");
				scanf("%d",&x1);
				switch(x1){
					case 1:
						printf("Input Element: ");
						scanf("%d",&num);
						if(contains(s1,num) == 1)
							printf("Element Found!");
						else
							printf("Element Not Found!");
						break;
					case 2:
						printf("Input Element: ");
						scanf("%d",&num);
						if(contains(s2,num) == 1)
							printf("Element Found!");
						else
							printf("Element Not Found!");
						break;	
					default:
						printf("Choose Wisely! ");
				}
				break;
			case 4:
				result = getUnion(result,s1,s2);
				printf("Success!");
				break;
			case 5:
				result = intersection(result,s1,s2);
				printf("Success!");
				break;
			case 6:
				result = difference(result,s1,s2);
				printf("Success!");
				break;
			case 7:
				result = symmetricdifference(result,s1,s2);
				printf("Success!");
				break;
			case 8:
				if(subset(s1,s2) == 1){
					printf("Set 1 is a Subset of Set 2");
				}else{
					printf("Set 1 is not a Subset of Set 2");
				}
				break;
			case 9:
				if(disjoint(s1,s2) == 1)
					printf("Set 1 and Set 2 are disjoint");
				else
					printf("Set 1 and Set 2 are not disjoint");
				break;
			case 0:
				if(equal(s1,s2) == 1)
					printf("Set 1 and Set 2 are Equal");
				else
					printf("Set 1 and Set 2 are not Equal");
				break;
			case 10:
				return 0;
				break;
			default:
				printf("Choose Wisely!");
		}
		printf("\n");
		system("PAUSE");
	}
	
	return 0;
}
