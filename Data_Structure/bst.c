#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;	
} node;

void insert_element(node **h, int element)
{
	int flag;
	node *tmp = (node *) malloc (sizeof(node)), *traverse, *parent;
	tmp->val = element;
	tmp->left = NULL;
	tmp->right = NULL;
	if (*h == NULL)
		*h = tmp;
	else {
		traverse = *h;
		while ( traverse ) {
			parent = traverse;
			if ( element < traverse->val ) {
				traverse = traverse->left;
				flag = 0;
			} else {
				traverse = traverse->right;
				flag = 1;
			}
		}
		if ( flag )
			parent->right = tmp;
		else
			parent->left = tmp;
	}
}

void search_element(node **h, int element)
{
	node *tmp = *h;
	while (tmp) {
		if (tmp->val == element) {
			printf("Value Found.\n");
			return;
		}
		else if (element < tmp->val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	printf("Value not found.\n");
}

void inorder_traversal(node *h)
{
	if (h == NULL)
		return;
	inorder_traversal(h->left);
	printf("%d\t",h->val);
	inorder_traversal(h->right);
}

void preorder_traversal(node *h)
{
	if (h== NULL)
		return;
	printf("%d\t",h->val);
	preorder_traversal(h->left);
	preorder_traversal(h->right);
}

void postorder_traversal(node *h)
{
	if (h== NULL)
		return;
	postorder_traversal(h->left);
	postorder_traversal(h->right);
	printf("%d\t",h->val);
}

int main()
{
	node *h = NULL;
	insert_element(&h,5);
	insert_element(&h,3);
	insert_element(&h,9);
	insert_element(&h,7);
	insert_element(&h,8);
	insert_element(&h,15);
	insert_element(&h,52);
	insert_element(&h,35);
	insert_element(&h,55);
	insert_element(&h,75);
	insert_element(&h,50);
	insert_element(&h,33);
	insert_element(&h,45);
	insert_element(&h,69);

	printf("\nIn order_traversal: ");
	inorder_traversal(h);
	printf("\nPre order_traversal: ");
	preorder_traversal(h);
	printf("\nPost order_traversal: ");
	postorder_traversal(h);
	return 0;
}
