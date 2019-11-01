#include <stdio.h>
#include <stdbool.h>

int sum_data(int arr[], int size)
{

static int sum = 0;

	if(size <= 0)
		return sum;
	else
	{
	sum += arr[size-1];
	sum_data(arr, size-1); 
	}
}



int main(int argc, char **argv)
{
	int arr[] = {1,9,8,3,1,0,0,2};
	int n = sizeof(arr)/4;

	printf("result = %d\n", sum_data(arr,n));

 return 0;
}
