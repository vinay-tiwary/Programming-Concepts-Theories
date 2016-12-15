#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool isempty(node *h)
{
	if ( h == NULL ) {
		return true;
	}
	else {
		return false;
	}
}


int push(node **h, int val)
{
	node *tmp;
	tmp = (node *) malloc (sizeof(node));
	tmp->val = val;
	tmp->prev = NULL;
	if ( isempty(*h) ) {
		*h = tmp;
	}
	else {
		tmp->prev = *h;
		*h = tmp;
	}
}

int pop(node **h)
{
	node *tmp;
	if ( isempty(*h) ) {
		printf("Error: Empty stack!\n");
	}
	else {
		printf("Popped %d from stack.\n",(*h)->val);
		tmp = *h;
		*h = (*h)->prev;
		free(tmp);
	}
}

int print_stack(node **h)
{
	node *tmp = *h;
	while ( tmp ) {
		printf("%d\n",tmp->val);
		tmp = tmp->prev;
	}
}

void release_stack(node **h)
{
	node *tmp;
	while(*h){
		tmp = *h;
		*h = (*h)->prev;
		free(tmp);
	}
}

#if 0
int main()
{
	int choice;
	node *h=NULL;
	while(1){
		printf(	"Stack Menu:\n"
			"1. Push element\n"
			"2. Pop element\n"
			"3. Print stack\n"
			"4. Exit\n"
			"Choice: ");
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d",&choice);
				push(&h,choice);
				break;
			case 2:
				pop(&h);
				break;
			case 3:
				print_stack(&h);
				break;
			case 4:
				release_stack(&h);
				exit(0);
				break;
			default:
				printf("Invalid choice. Try again\n");
		}
	}
	return 0;
}

#endif
