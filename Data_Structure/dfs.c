#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
	node *n=NULL;
	push(&n,1);
	push(&n,2);
	push(&n,3);
	print_stack(&n);
	release_stack(&n);
	return 0;
}

