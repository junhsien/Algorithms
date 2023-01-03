#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	while(l<=r) {
		int mid = l+(r-1)/2;
		
		// check if x is present at mid
		if(arr[mid]==x)
			return mid;
		
		// If x is greater, ignore left half
		if(arr[mid]<x)
			l = mid+1;
		// If x is smaller, ignore right half
		else
			r = mid-1;
	}

	return -1;
}

int main()
{
	int arr[] = {2, 3, 4, 10, 40};
	int x = 10;
	int N = sizeof(arr)/sizeof(arr[0]);
	int result = binarySearch(arr, 0, N-1, x);
	
	(result==-1)
		? printf("Element is not present in array\n")
		: printf("Element is present at index %d\n", result);
	
	return 0;
}
