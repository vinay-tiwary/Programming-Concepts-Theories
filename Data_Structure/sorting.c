#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void bubble_sort(int *arr, int size)
{
	int tmp,i,j;
	for (i=size-1;i>=1;i--) {
		for (j=0;j<i;j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void insertion_sort(int *arr, int size)
{
	int i,j,tmp;
	for (i=1;i<size;i++) {
		for (j=i;j>0;j--) {
			if (arr[j] < arr[j-1]) {
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}

void selection_sort(int *arr, int size)
{
	int i,j,tmp,pos;
	for (i=0;i<size;i++) {
		pos = i;
		for (j=i+1;j<size;j++) {
			if (arr[i] > arr[j]) {
				pos = j;
			}
		}
		if (pos != i) {
			tmp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = tmp;
		}
	}
}

void merge(int *arr, int l, int r, int m)
{
	int templ[50], tempr[50], i, j, k;
	int lsize = m - l + 1;
	int rsize = r - m;

	for (i=0; i<lsize; i++)
		templ[i] = arr[l+i];
	
	for (i=0; i<rsize; i++)
		tempr[i] = arr[i+m+1];

	i=j=0;
	k=l;
	while(i < lsize && j < rsize) {
		if ( templ[i] < tempr[j] ) 
			arr[k++] = templ[i++];
		else
			arr[k++] = tempr[j++];
	}
	while(i < lsize)
		arr[k++]=templ[i++];
	while(j < rsize)
		arr[k++]=tempr[j++];
}

int mc=1;

void merge_sort(int *arr, int start, int end)
{
	int med;
	if (start < end) {
		med = start + (end - start)/2;
		merge_sort(arr, start, med);
		merge_sort(arr, med+1, end);
		merge(arr, start, end, med);
	}
}

int divide_arr(int *arr, int left, int right)
{
	int tmp, pivot = arr[right],ppos=right;
	right--;
//	printf("Dividing from left %d to right %d and pivot is %d\n",left,right,pivot);
	while (1) {
		while( arr[left] < pivot){ 
//			printf("left: %d\n",arr[left]);
			left++;
		}
		while( arr[right] > pivot){
//			printf("right: %d\n",arr[right]);
			right--;
		}
		if ( right <= left ){
//			printf("Right = %d, Left = %d\n",right,left);
			break;
		}
		else {
//			printf("Swapping %d and %d\n",arr[left],arr[right]);
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
//	printf("Final Swapping %d and %d\n",arr[left],arr[ppos]);
	tmp = arr[left];
	arr[left] = arr[ppos];
	arr[ppos] = tmp;
	return left;
	
}

void quick_sort(int *arr, int left, int right)
{
	int partition;
//	printf("--------------Iteration = %d-----------------\n",mc++);
//	printf("Left = %d\t",left);
//	printf("Right = %d\n",right);
	if (right <= left)
		return ;
	else {
		partition = divide_arr(arr, left, right);
		quick_sort(arr,left,partition-1);
		quick_sort(arr,partition+1,right);
	} 
}


void print_elements(int *arr, int size)
{
	int i;
	for (i=0;i<size;i++)
		printf("%d\t",arr[i]);
}

int main()
{
	int arr[MAX], total, i;
	arr[0] = 12;
	arr[1] = 6;
	arr[2] = 14;
	arr[3] = 66;
	arr[4] = 3;
	arr[5] = 13;
	arr[6] = 9;
	arr[7] = 81;
	arr[8] = 25;
	arr[9] = 21;
	total = 10 ;
	printf("Enter total elements:\n");
//	scanf("%d",&total);
	if ( total > 50 || total <= 0) {
		printf("Error! Valid range 1-50\n");
		exit(0);
	}
	printf("Enter elements \n");
	for (i=0;i<total;i++) {
//		scanf("%d", arr + i);
	}

	print_elements(arr,total);
	printf("\n");
//	bubble_sort(arr,total);
//	insertion_sort(arr,total);
//	selection_sort(arr,total);
//	merge_sort(arr,0,total-1);
	quick_sort(arr, 0, total-1);
	print_elements(arr,total);
	
	return 0;
}
