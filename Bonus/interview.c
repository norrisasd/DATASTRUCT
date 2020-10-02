#include <stdio.h>
#include <stdlib.h>
#include "interview.h"
Nodeptr createNode(int item){
	Nodeptr temp;
	temp=(Nodeptr)malloc(sizeof(QUEUE_NODE));
	temp->data = item;
	temp->next=NULL;
	return temp;
}
Queue createQueue(){
	Queue q=(Queue)malloc(sizeof(QUEUE_HEAD));
	q->front=q->rear=NULL;
	q->count=0;
	return q;
}
int isEmptyQ(Queue q){
	return q->count==0;
}
void enqueue(Queue q, int item){
	Nodeptr temp;
	temp=createNode(item);
	if(isEmptyQ(q)){
		q->front=temp;
	}else{
		q->rear->next=temp;
	}
	q->rear=temp;
	q->count++;
}
void dequeue(Queue q){
	Nodeptr temp;
	temp = q->front;
	if(q->count == 1){
		q->front=q->rear=NULL;
	}else{
		q->front=temp->next;
		temp->next=NULL;
	}
	free(temp);
	q->count--;
}
void menu(){
	printf("Job Interview Queuing\n");
	printf("1. Queue for interview\n");
	printf("2. Call the Interviewee\n");
	printf("3. Exit\n");
	printf("\n Choose: ");
}
void displayQ(Queue q){
	Nodeptr ptr = q->front;
	printf("\n[");
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("]\n");
}
void freeQ(Queue q){
	Nodeptr temp; 
	while(q->front!=NULL){
		temp = q->front;
		q->front = q->front->next;
		temp->next = NULL; 
		free(temp);
		(q->count)--;
	}
}
int getNum(){
	int num;
	printf("Input Number: ");
	scanf("%d",&num);
	return num;
}
int findNum(Queue q, int num){
	Nodeptr ptr=q->front;
	while(ptr !=NULL){
		if(num == ptr->data)
			return 1;
		ptr=ptr->next;
	}
	return 0;
}

