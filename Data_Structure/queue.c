#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node *prev;
	struct Node *next;
} node;

bool isempty(node *front)
{
	if ( front == NULL ) {
		return true;
	}
	else {
		return false;
	}
}


void enque(node **front,node **rear, int val)
{
	node *tmp;
	tmp = (node *) malloc (sizeof(node));
	tmp->val = val;
	tmp->prev= NULL;
	tmp->next= NULL;

	if ( isempty(*front) ) {
		*front = *rear = tmp;
	}
	else {
		tmp->next = *rear;
		(*rear)->prev = tmp;
		*rear = tmp;
	}
}

void deque(node **front,node **rear)
{
	node *tmp;
	if ( isempty(*front) ) {
		printf("Error: Empty queue!\n");
	}
	else {
		printf("Removed %d from queue.\n",(*front)->val);
		tmp = *front;
		*front = (*front)->prev;
		if ( *front != NULL){
			(*front)->next = NULL;
		}
		else {
			*rear = NULL;
		}
		free(tmp);
	}
}

int print_queue(node **front)
{
	node *tmp = *front;
	printf("Printing from front to rear:\n");
	while ( tmp ) {
		printf("%d\n",tmp->val);
		tmp = tmp->prev;
	}
}

int print_queue1(node **rear)
{
	node *tmp = *rear;
	printf("Printing from rear:\n");
	while ( tmp ) {
		printf("%d\n",tmp->val);
		tmp = tmp->next;
	}
}

void release_queue(node **front, node **rear)
{
	node *tmp;
	while(*front){
		tmp = *front;
		*front = (*front)->prev;
		free(tmp);
	}
	*rear = NULL;
}

int main()
{
	int choice;
	node *front = NULL, *rear = NULL;
	while(1){
		printf(	"Queue Menu:\n"
			"1. Enque\n"
			"2. Deque\n"
			"3. Print Queue\n"
			"4. Exit\n"
			"Choice: ");
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d",&choice);
				enque(&front, &rear,choice);
				break;
			case 2:
				deque(&front, &rear);
				break;
			case 3:
				print_queue(&front);
				print_queue1(&rear);
				break;
			case 4:
				release_queue(&front,&rear);
				exit(0);
				break;
			default:
				printf("Invalid choice. Try again\n");
		}
	}
	return 0;
}
