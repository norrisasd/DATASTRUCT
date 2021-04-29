#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

void add(Statistician answer, int *count, int *SIZE, int item)
{
	if(*count == *SIZE){
		(*SIZE)*=2;
		answer=(Statistician)realloc(answer,(*SIZE)*sizeof(int));
	}
	answer[*count] = item;
	*count +=1;
	int i,j,temp;
	for(i=0;i<*count;i++){
		for(j=i+1;j<*count;j++){
			if(answer[i] >=answer[j]){
				temp =answer[i];
				answer[i]= answer[j];
				answer[j]= temp;
			}
		}
	}
	
}
void displayRes(Statistician answer, int count){
	int i;
	printf("[");
	for(i=0;i<count;i++){
		printf(" %d ",answer[i]);
	}
	printf("]");
}
float mean(Statistician answer, int count){
	int sum=0,i;
	for(i=0;i<count;i++){
		sum+=answer[i];
	}
	return (float)sum/count;
}
float median(Statistician answer, int count){
	float med;
	if(count%2==0){
		med =(float)(answer[count/2]+answer[(count/2)-1])/2;
		return med;
	}else{
		med = answer[(count/2)];
		return med;
	}
}
int min(Statistician answer, int count){
	int i ,min=answer[0];
	for(i =1;i<count;i++){
		if(min >= answer[i]){
			min = answer[i];
		}
	}
	return min;
}
int max(Statistician answer, int count){
	int i ,max=answer[0];
	for(i =1;i<count;i++){
		if(max <= answer[i]){
			max = answer[i];
		}
	}
	return max;
}
int range(Statistician answer, int count){
	return max(answer,count) - min(answer,count);
}

void mode(int freq[], int *freqsize, Statistician answer, int count){
	int i,highest=0,freqs=9;
	*freqsize = 0;
	int fre[freqs];
	for(i=0;i<freqs;i++){
		fre[i]=0;
	}
	for(i=0;i<count;i++){
		fre[answer[i]-1]++;
	}
	for(i=0;i<9;i++){
		if(fre[i]>=highest ){
			highest = fre[i];
		}
	}
	for(i=0;i<9;i++){
		if(highest == fre[i] && highest > 1 ){
			freq[(*freqsize)]=i+1;
			*freqsize+=1;
			freq=(Statistician) realloc(freq,((*freqsize)*sizeof(int)));
		}
	}
	if(highest == 1 || highest == 0){
		printf("No Mode!");
	}
	
}
void Menu(){
	printf("Choices: \n");
	printf("1. Add Response\n");
	printf("2. Get Mean\n");//
	printf("3. Get Median\n");//
	printf("4. Get Mode\n");
	printf("5. Get Max\n");//
	printf("6. Get Min\n");//
	printf("7. Get Range\n");//
	printf("8. Display Histogram\n");
	printf("9. Exit\n\n");//
	printf("Choose: ");
	
}
void histogram(Statistician answer, int count){
	int freq[9];
	int i,j,highest=0;
	for(i=0;i<9;i++){
		freq[i]=0;
	}
	for(i=0;i<count;i++){
		freq[answer[i]-1]++;
	}
	for(i=0;i<9;i++){
		if(freq[i]>=highest ){
			highest = freq[i];
		}
	}
	for(i=highest+2;i>0;i--){
		printf("%d\t",i);
		for(j=0;j<9;j++){
			if(i == freq[j]){
				printf("*");
				freq[j]--;
			}
			printf("\t");
		}
		printf("\n");
	}
	printf("\n\t");
	for(i=1;i<=9;i++){
		printf("%d\t",i);
	}
}

