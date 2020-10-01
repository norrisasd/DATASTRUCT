#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q=createQueue();
	Stack s=createStack();
	enqueue(q,5);
	displayQueue(q);
	return 0;
}
