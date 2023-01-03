// C program to implement recursive Binary Search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if( r>=l ) {
		int mid = 1 + (r+l)/2;
		
		// If the element is present at the middle itself
		if(arr[mid]==x)
			return mid;
		
		// If element is smaller than mid, then it can only be present in ledt subarray
		if(arr[mid]>x)
			return binarySearch(arr, l, mid-1, x);
		// Else the element can only be present in right subarray
		else
			return binarySearch(arr, mid+1, r, x);
	}
	// We reach hee when element is not present in array
	return -1;
}

int main() {
	// your code goes here
	int arr[]= {2, 3, 4, 10, 40};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x=10;
	
	int result = binarySearch(arr,0, n-1, x);
	
	(result==-1)
		? printf("Element is not present in array\n")
		: printf("Element is present at index %d\n", result);
	
	return 0;
}

/*
output:
  Element is present at index 3
*/
