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
void freeStack(Stack s);
void push(Stack s,stackItem item); // insert at the top - push
void pop(Stack s); // deleting the top element - pop
stackItem stackTop(Stack s); // returns the top item
int isEmpty(Stack s);
void display(Stack s);

Nodeptr createNode(int item);
int isValid(Stack s, stackItem *str);
int validInput(stackItem *str);
int again();

