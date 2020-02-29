#include "quickSort.h"
void swap(int *i1, int *i2) {
  int i = *i1;
  *i1 = *i2;
  *i2 = i;
}

ptrPair divide(int *a, int n) {
  int i = getPartitionIndex(a, n) + 1;

  ptrPair p;
  p.first = a;
  p.second = a + i;
  p.firstLen = i;
  p.secondLen = n - i;
  return p;
}

int getPartitionIndex(int *a, int n) {
  int x = a[0];
  int i = -1;
  int j = n;
  while (1) {
    do {
      j--;
    } while (a[j] > x);

    do {
      i++;
    } while (a[i] < x);

    if (i < j) {
      swap(&a[i], &a[j]);
    } else
      return j;
  }
}

void conquer(int *a, int n) {
  if (n > 1) {
    ptrPair newPair = divide(a, n);
    conquer(newPair.first, newPair.firstLen);
    conquer(newPair.second, newPair.secondLen);
  }
}

void quickSort(int *a, int n) { conquer(a, n); }

int isSorted(int *a, int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1])
      return 0;
  }
  return 1;
}
