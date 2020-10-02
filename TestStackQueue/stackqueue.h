typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}STACKQUEUE_NODE;

typedef struct{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef struct{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;
typedef QUEUE_HEAD* Queue;

Nodeptr createNode(int item);
Stack createStack();
Queue createQueue();
void push(Stack s, int item);
int pop(Stack s);
void enqueue(Queue q, int item);
int dequeue(Queue q);
int isEmptyS(Stack s);
int isEmptyQ(Queue q);
void displayQ(Queue q);
void displayS(Stack s);
int checker(Stack s, Queue q);
void menu();
int Run();
int getItem();
void freeQ(Queue q);
void freeS(Stack s);
