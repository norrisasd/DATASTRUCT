#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

Nodeptr createNode(int item){
	Nodeptr temp;
	temp=(Nodeptr)malloc(sizeof(STACKQUEUE_NODE));
	temp->data=item;
	temp->next=NULL;
	return temp;
}
Stack createStack(){
	Stack s=(Stack)malloc(sizeof(STACK_HEAD));
	s->top=NULL;
	s->count = 0;
	return s;
}
Queue createQueue(){
	Queue q=(Queue)malloc(sizeof(QUEUE_HEAD));
	q->front=q->rear=NULL;
	q->count=0;
	return q;
}
int isEmptyS(Stack s){
	return s->count==0;
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
int dequeue(Queue q){
	int item;
	Nodeptr temp;
	temp = q->front;
	if(q->count == 1){
		item=q->front->data;
		q->front=q->rear=NULL;
	}else{
		item = q->front->data;
		q->front=temp->next;
		temp->next=NULL;
	}
	free(temp);
	q->count--;
	return item;
}
void push(Stack s, int item){
	Nodeptr temp=createNode(item);
	temp->next=s->top;
	s->top=temp;
	s->count++;
	
}
int pop(Stack s){
	int item;
	Nodeptr temp = s->top;
	item = temp->data;
	s->top=temp->next;
	temp->next=NULL;
	free(temp);
	s->count--;
	return item;	
}
int checker(Stack s, Queue q){
	if(isEmptyS(s)==1 && isEmptyQ(q)==1)
		return 1;
	return 0;
	
}
void menu(){
	printf("STACK AND QUEUE TEST DRIVER\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Exit\n");
	printf("\n Choose: ");
}
int getItem(){
	int x;
	printf("Input Item: ");
	scanf("%d",&x);
	return x;
}
int Run(){
	int x;
	printf("Choose 1 to Try Again | 0 to Exit: ");
	scanf("%d",&x);
	return x==1;
}
void displayS(Stack s){
	Nodeptr ptr;
	ptr = s->top;
	printf("\n[");
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("]\n");
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
void freeS(Stack s){
	Nodeptr temp;
	while(s->top!=NULL){
		temp = s->top;
		s->top = s->top->next;
		temp->next = NULL; 
		free(temp);
		(s->count)--;
	}
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
