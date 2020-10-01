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
void displayQueue(Queue q){
	Nodeptr ptr;
	ptr = q->front;
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

