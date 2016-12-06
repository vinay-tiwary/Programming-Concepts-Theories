#include <stdio.h>

#define MAX 500

int multiply(int x, int res[], int res_size)
{
	int i, carry = 0, prod = 0;
	for (i=0;i < res_size;i++){
		prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while(carry){
		res[res_size] = carry%10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

int factorial(int n)
{
	int res[MAX],x,res_size;
	
	res[0] = 1;
	res_size = 1;
	for (x=2;x<=n;x++){
		res_size = multiply(x,res,res_size);
	}
	printf("Factorial: ");
	for(x = res_size -1;x >=0;x--)
		printf("%d",res[x]);
	printf("\n");
}

int main()
{
	factorial(5);
	factorial(100);
	return 0;
}
