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

typedef struct STACK_HEAD* Stack;
typedef struct QUEUE_HEAD* Queue;

Nodeptr createNode(int item);
Stack createStack();
void push(Stack s, int item);
int pop(Stack s);
int isEmptyS(Stack s);
void displayStack(Stack s);
Queue createQueue();
void enqueue(Queue q, int item);
int dequeue(Queue q);
void displayQueue(Queue q);
int isEmptyQ(Queue q);


