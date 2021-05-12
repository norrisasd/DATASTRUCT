#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
Nodeptr createNode(int item){
	Nodeptr temp;
	temp = (Nodeptr)malloc(sizeof(STACK_NODE));
	temp->item = item;
	temp->next = NULL;
	return temp;
}
Stack newStack(){
	Stack s =(Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top=NULL;
	return s; 
}
void push(Stack s, stackItem item){
	Nodeptr temp;
	temp = createNode(item);
	temp->next= s->top;
	s->top = temp;
	s->count++;
}
void pop(Stack s){
	Nodeptr temp;
	temp = s->top;
	s->top= temp->next;
	temp->next=NULL;
	free(temp);
	s->count--;
}
int isEmpty(Stack s){
	if(s->count == 0)return 1;
	return 0;
}
stackItem stackTop(Stack s){
	return s->top->item;
}
int isValid(Stack s, stackItem *str){
	int i;
	for(i=0;str[i]!='\0';i++){
		 if(str[i] == '(' || str[i] == '{' || str[i] == '['){
		 	push(s,str[i]);
		 }else{
		 	if(isEmpty(s)==0){
		 		if(str[i] == ')' && stackTop(s) == '(' || str[i] == '}' && stackTop(s) == '{'|| str[i] == ']' && stackTop(s) == '[')
		 			pop(s);
		 		else
		 			return 0;
			 }else{
			 	return 0;
			 }
		 }
	}
	if(isEmpty(s)==0)
		return 0;
	else
		return 1;
	
}
int validInput(stackItem *str){
	int i;
	for(i=0;str[i]!='\0';i++){
		if(str[i] == ')'||str[i] == '}'||str[i] == ']'||str[i] == '('||str[i] == '{'||str[i] == '[')
			continue;
		else 
			return 0;
	}
	return 1;
}
int again(){
	int x;
	printf("\nPress [1] to Try Again | [0] to exit: ");
	scanf("%d",&x);
	return x;
}
void display(Stack s){
	Nodeptr ptr = s->top;
	while(ptr!=NULL){
		printf("%c",ptr->item);
		ptr=ptr->next;
	}
}
void freeStack(Stack s){
	Nodeptr ptr=s->top;
	while(ptr!=NULL){
		free(ptr);
		ptr=ptr->next;
	}
	s->top=ptr;
	free(s->top);
	free(s);
}
