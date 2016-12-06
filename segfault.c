#include <stdio.h>
#include <stdlib.h>

int main(){
	char *p = NULL, *x=0;
	p = malloc(3); 

	*p = 'a'; 
	*(p+1) = 'b'; 
	*(p+2) = 'c';
	printf("%c\t%c\t%c\n",*p,*(p+1),*(p+2)); 
	free(p); 
	*p = 'a';
	*x = '4'; 
	printf("%c\n",*p); 
	return 0;
}
