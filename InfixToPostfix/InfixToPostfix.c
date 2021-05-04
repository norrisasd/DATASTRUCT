#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
Nodeptr createNode(stackItem item){
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
stackItem stackTop(Stack s){
	return s->top->item;
}
void push(Stack s, stackItem item){
	Nodeptr temp;
	temp = createNode(item);
	temp->next= s->top;
	s->top = temp;
	s->count++;
}
stackItem pop(Stack s){
	stackItem item;
	Nodeptr temp;
	temp = s->top;
	item = temp->item;
	s->top= temp->next;
	temp->next=NULL;
	free(temp);
	s->count--;
	return item;
}
void algorithm(Stack s, stackItem *item, stackItem *output){
	int i,j=0,k=s->count;
	char top=stackTop(s);
	
}
int validInput(char *item){
	int i,flag =0,flag2=0;
	for(i=0;item[i]!='\0';i++){
		if(isdigit(item[i]))
			flag =1;
		else if(item[i] == '+' ||item[i] == '-' ||item[i] == '*' ||item[i] == '/'){
			flag2 = 1;
			flag = 0;
		}
		else
			return 0;
	}
	return flag == flag2;
}
void infixToPostfix(Stack s, char item[], char output[]){
	int i,j=0;
	char k;
	for(i=0;item[i]!='\0';i++){
			if(isdigit(item[i])){
				output[j]=item[i];
				j++;
			}else{
				if(isEmpty(s)){
						push(s,item[i]);
				}else{
					if(item[i] == stackTop(s)){
						k=pop(s);
						output[j]=k;
						j++;
						push(s,item[i]);
					}
					else if(item[i] == '*' || item[i] == '/' || item[i] == '%'){
						push(s,item[i]);
					}
					else{
					while(!isEmpty(s)){
						k=pop(s);
						output[j]=k;
						j++;
					}
					push(s,item[i]);
					}
				}
			}
		}
		while(!isEmpty(s)){
			k=pop(s);
			output[j]=k;
			j++;
		}
}
float postfixEvaluation(Stack s,char post[]){
	int i;
	float ans=0;
	float n1,n2;
	for(i=0;post[i] != '\0';i++){
		if(isdigit(post[i])){
			push(s,post[i] - '0');
		}else{
			n1=pop(s);
			n2=pop(s);
			ans = getResult(n1,n2,post[i]);
			push(s,ans);
		}
	}
	return pop(s);
}
int isEmpty(Stack s){
	if(s->count==0)
		return 1;
	return 0;
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
float getResult(stackItem n1,stackItem n2, char op){
	float ans = 0;
	if(op == '*')
		ans = n2 * n1;
	else if(op == '+')
		ans = n2 + n1;
	else if(op == '-')
		ans = n2 - n1;
	else if(op == '/')
		ans = n2 / (float) n1;
	else if(op=='%'){
		ans = (int)n2%(int)n1;
	}
	return ans;
}
int again(){
	int x;
	printf("Input 1 to try again | 0 to exit : ");
	scanf("%d",&x);
	return x;
}

