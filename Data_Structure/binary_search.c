#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void binary_search(int *arr, int size)
{
	int low=0,high= size - 1,med,search;
	printf("Enter search element: \n");
	scanf("%d",&search);
	med = low + (high - low) / 2;
	while (1) {
		if ( arr[med] == search ) {
			printf("Found %d @ index %d\n", search, med);
			break;
		}
		else if ( arr[med] > search ) {
			high = med - 1;
			med = low + (high - low) / 2;
		} else {
			low = med + 1;
			med = low + (high - low) / 2;
		}
		if (low > high) {
			printf("Element %d not found.\n", search);
			break;
		}
	}
}

int main()
{
	int arr[MAX], total, i;
	printf("Enter total elements:\n");
	scanf("%d",&total);
	if ( total > 50 || total <= 0) {
		printf("Error! Valid range 1-50\n");
		exit(0);
	}
	printf("Enter elements (in sorted order):\n");
	for (i=0;i<total;i++) {
		scanf("%d", arr + i);
	}
	binary_search(arr, total);
	return 0;
}
