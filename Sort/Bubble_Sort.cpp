//ref:https://c.biancheng.net/view/192.html
//data:2024-03-13
// it's work!
// output => After bubble sort: -234 -70 -58 2 3 32 34 35 43 56 76 532 543 900 2500

#include <iostream>

void bubble_sort(int arr[], int n)
{
  for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-1-i;j++) {
      if(arr[j]>arr[j+1]) {
        int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main()
{
  int arr[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
  int size = sizeof(arr)/sizeof(arr[0]);
  bubble_sort(arr, size);

  printf("After bubble sort: ");
  for(int i=0;i<size;i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
