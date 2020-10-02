#define MAX 50
typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}QUEUE_NODE;

typedef struct{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;
typedef QUEUE_HEAD* Queue;

Queue createQueue();
Nodeptr createNode(int item);
void displayQ(Queue q);
int isEmptyQ(Queue q);
void freeQ(Queue q);
void menu();
void dequeue(Queue q);
void enqueue(Queue q, int item);

