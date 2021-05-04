#include <stdio.h>
#include <stdlib.h>
#include "set.h"
Set initialize(){
	Set Head;
	Head = NULL;
	return Head;
}

void display(Set s){
	nodeptr ptr = s;
    printf("[");
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
            printf("%d", ptr->data);
        else
            printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

Set add(Set s, int elem){
	nodeptr temp;
	temp = (nodeptr)malloc(sizeof(Node));
	temp->data = elem;
	temp->next = s;
	return temp;
}

int contains(Set s, int elem){
	nodeptr ptr = s;
	while(ptr!=NULL){
		if(ptr->data == elem)
			return 1;
		ptr = ptr->next;
	}
	return -1;
}
Set getUnion(Set result, Set s1, Set s2){
	result = initialize();
	nodeptr ptr1 = s1;
	nodeptr ptr2 = s2;
	while(ptr2 != NULL){
		result = add(result,ptr2->data);
		ptr2= ptr2->next;
	}
	while(ptr1 != NULL){
        if(contains(result,ptr1->data) != 1){
           result = add(result,ptr1->data);
        }
        ptr1 = ptr1->next;
    }

    return result;
}

Set intersection(Set result, Set s1, Set s2){
	result = initialize();
    nodeptr ptr = s1;

    while(ptr != NULL){
        if(contains(s2,ptr->data) ==1){
               result = add(result,ptr->data);
        }
        ptr = ptr->next;
    }
    return result;
}
Set difference(Set result, Set s1, Set s2){
	result = initialize();
    nodeptr ptr = s1;
    while(ptr != NULL){
        if(contains(s2,ptr->data) != 1)
            result = add(result,ptr->data);
        ptr = ptr->next;
    }
    return result;
}
Set symmetricdifference(Set result, Set s1, Set s2){
	result = initialize();
    nodeptr ptr1 = s1;
    nodeptr ptr2 = s2;
    
    while(ptr1 != NULL){
        if(contains(s2,ptr1->data) != 1)
            result = add(result,ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        if(contains(s1,ptr2->data) != 1)
            result = add(result,ptr2->data);
        ptr2 = ptr2->next;
    }
    return result;
}
int subset(Set s1, Set s2){
	nodeptr ptr1 = s1;
    nodeptr ptr2 = s2;
    int ctr = 0;
    while(ptr1 != NULL){
        ptr2 = s2;
        while (ptr2 != NULL)
        {
            if(ptr1->data == ptr2->data)
                ctr++;

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    if(ctr == count(s1) )
        return 1;
    return -1;
}
int disjoint(Set s1, Set s2){
	nodeptr ptr = s1;
    while(ptr != NULL){
        if(contains(s2,ptr->data) == 1)
            return -1;
        ptr = ptr->next;
    }
    return 1;
}
int equal(Set s1, Set s2){
	if(subset(s1,s2) == 1 && subset(s2,s1) == 1)
        return 1;
    return -1;
}
void menu(){
    printf("1. Display\n");
    printf("2. Add\n");
    printf("3. Contains\n");
    printf("4. Get Union\n");
    printf("5. Intersection\n");
    printf("6. Difference\n");
    printf("7. Symmetric Difference\n");
    printf("8. Subset\n");
    printf("9. Disjoint\n");
    printf("0. Equal\n");
    printf("10. Exit\n"); 
}
int count(Set s){
	nodeptr ptr = s;
    int ctr = 0;
    while(ptr != NULL){
        ctr++;
        ptr = ptr->next;
    }
    return ctr;
}

