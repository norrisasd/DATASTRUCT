#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
Polynomial p1 = newPoly();
	Polynomial p2 = newPoly();
	addTerm(p1,10,0);
	addTerm(p1,11,1);
	addTerm(p1,12,2);
	addTerm(p1,13,3);
	addTerm(p1,14,4);
	addTerm(p1,15,5);
	addTerm(p1,16,6);
	addTerm(p1,17,7);
	addTerm(p1,18,8);
	
	addTerm(p2,1,0);
	addTerm(p2,2,1);
	addTerm(p2,-3,2);
	addTerm(p2,4,3);
	addTerm(p2,5,4);
	addTerm(p2,6,5);
	addTerm(p2,7,6);
	addTerm(p2,-8,7);
	addTerm(p2,9,8);
	addTerm(p2,10,9);
	
	
	printf("P1: ");
	display(p1);
	
	printf("P2: ");
	display(p2);
	
	printf("(P1 + P2): ");
	display(add(p1,p2));
	
	printf("(P1 - P2): ");
	display(subtract(p1,p2));
	
	printf("Derivative of P1: ");
	display(derivative(p1));
	
	printf("Evaluate P2, x = 2: %d\n",evaluate(p2,2) );
	printf("Evaluate P1, x = 3: %d\n",evaluate(p1,3) );
	printf("Is P1 constant: %d\n",isConstant(p1));
	Polynomial p3 = newPoly();
	addTerm(p3,25,0);
	printf("Creating new Polynomial... P3: ");
	display(p3);
	printf("Is P3 constant: %d\n",isConstant(p3));
	printf("Is P2 Zero: %d\n",isZero(p2));

	Polynomial p4 = newPoly();
	printf("Creating new Polynomial... P4: ");
	display(p4);
	printf("Is P4 Zero: %d\n",isZero(p4));
	printf("Is P1 complete: %d\n",isComplete(p1));
	printf("Is P2 complete: %d\n",isComplete(p2));

	
	
	destroyPoly(&p1);
	destroyPoly(&p2);
	destroyPoly(&p3);
	destroyPoly(&p4);
	

	return 0;
}
