#include <stdio.h>

#define ARRAYSIZE(x) sizeof(x)/sizeof(x[0])

void quickSort(int *arr, int l, int r);
int binarySearch(int arr[], int l, int r, int x);

int isSubset(int *arr1, int *arr2, int m, int n)
{
    int i=0;
    
    quickSort(arr1, 0, m-1);
    for(i=0; i<n; i++) {
        if(binarySearch(arr1, 0, m-1, arr2[i])==-1)
            return 0;
    }
    
    return -1;
}

void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    int x = arr[r];
    int i = l-1;
    int j;
    
    for(j=l; j<=r-1; j++) {
        if(arr[j]<=x){
            i++;
            exchange(&arr[i], &arr[j]);
        }
    }
    exchange(&arr[i+1], &arr[r]);
    return (i+1);
}

void quickSort(int *arr, int l, int r)
{
    int index;
    if(l<r){
        index = partition(arr, l ,r);
        quickSort(arr, l, index-1);
        quickSort(arr, index+1, r);
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    int mid;
    while(l<=r) {
        mid = l+(r-l)/2;
        printf("l=%d, r=%d, mid=%d arr[mid]=%d\n", l, r, mid, arr[mid]);
        if(arr[mid]==x)
            return mid;
        
        if(arr[mid] < x)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}


int main()
{
    int arr1[] = {11, 1, 13, 21, 3 ,7};
    int arr2[] = {11, 3, 7, 1};
    
    int m = ARRAYSIZE(arr1);
    int n = ARRAYSIZE(arr2);

    (isSubset(arr1, arr2, m, n))
        ? printf("arr2[] is subset of arr1[]")
        : printf("arr2[] is not subset of arr1[]");
    
    return 0;
}
