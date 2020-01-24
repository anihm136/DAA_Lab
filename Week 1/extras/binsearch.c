#include <stdio.h>

int* sort(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i+1; j < size; j++) {
      if (arr[j] < arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  return arr;
}

int search(int *input, int size, int key) {
  int *arr = sort(input,size);
  int low = 0;
  int high = size;
  int mid = (high+low)/2;
  while(low <= high) {
    if (arr[mid] == key) {
      return 1;
    } else if (key > arr[mid]) {
      low = mid+1;
      mid = (high+low)/2;
    } else {
      high = mid-1;
      mid = (high+low)/2;
    }
  }
  return 0;
}

int main(void)
{
  int arr[] = {10,30,50,20,40,60,90,70};
  int input;
  do {
    scanf("%d",&input);
    printf("%d\n",search(arr, 8, input));
  } while (input != 0);
  return 0;
}
