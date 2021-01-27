#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"

void destroyPoly(Polynomial *p){
	free(*p);
	*p=NULL;
}
Polynomial newPoly(){
	Polynomial poly =(Polynomial)calloc(MAX,sizeof(int));
	return poly;
}
void addTerm(Polynomial p,int coef,int exp){
	p[exp] = coef;
}

Polynomial add(const Polynomial p1,const Polynomial p2 ){
	int i;
	Polynomial res = newPoly();
	for(i=0;i<MAX;i++){
		res[i]=p1[i]+p2[i];
	}
	return res;
}
Polynomial subtract(const Polynomial p1,const Polynomial p2 ){
	int i;
	Polynomial res = newPoly();
	for(i=0;i<MAX;i++){
		res[i]=p1[i]-p2[i];
	}
	return res;
}
Polynomial derivative(const Polynomial p){
	int i;
	Polynomial res=newPoly();
	for(i=0;i<MAX;i++){
		if(p[i]!=0){
			res[i-1]=i*p[i];
		}
	}
	return res;
}
int evaluate(const Polynomial p,int x){
	int i,res=0,temp;
	for(i=0;i<MAX;i++){
		temp=p[i]*pow(x,i);
		res+=temp;
	}
	return res;
}
int isConstant(const Polynomial p){
	int i;
	for(i=0;i<MAX;i++){
		if(p[i]!=0 && i!=0)
			return 0;
	}
	return 1;
}
void display(const Polynomial p){
	int i,check=0;
	for(i=0;i<MAX;i++){
		if(p[i]!=0 ){
			if(p[i]>0 && check == 1)
				printf("+");
			if(i==0||p[i]!=1 )
				printf("%d",p[i]);
			if(i>0)
				printf("x");
			if(i>1)
				printf("^%d",i);
			
			check=1;
		}
	}
	if(check ==0)
		printf("0");
		
	printf("\n");

}
int isZero(const Polynomial p){
	int i;
	for(i=0;i<MAX;i++){
		if(p[i]>1)
			return 0;
	}
	return 1;
}
int isComplete(const Polynomial p){
	int i;
	for(i=0;i<MAX;i++){
		if(p[i]==0)
			 return 0;
	}
	return 1;
}


