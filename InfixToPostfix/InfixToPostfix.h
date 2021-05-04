typedef float stackItem;
typedef struct node* Nodeptr;
typedef struct node{
	stackItem item;
	Nodeptr next;
}STACK_NODE;

typedef struct{
	int count;
	Nodeptr top;
}STACK_HEAD;
typedef STACK_HEAD* Stack;

Stack newStack();
Nodeptr createNode(stackItem item);
stackItem pop(Stack s);
void push(Stack s, stackItem item);
int validInput(char *item);
stackItem stackTop(Stack s);
int isEmpty(Stack s);
void freeS(Stack s);
float getResult(stackItem n1,stackItem n2, char op);
void infixToPostfix(Stack s, char item[], char output[]);
float postfixEvaluation(Stack s,char post[]);
int again();


