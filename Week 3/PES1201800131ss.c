int isSorted(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1])
      return 0;
  }
  return 1;
}

void bubblePass(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      int temp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = temp;
    }
  }
}

void bubbleSort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    bubblePass(a, n - i);
  }
}

int numBubblePasses(int *a, int n) {
  if (isSorted(a, n))
    return 0;
  else {
    int ctr = 0, flag = 0;
    for (int i = 0; i < n - 1; i++) {
      flag = 0;
      for (int j = 0; j < n - i - 1; j++) {
        if (a[j] > a[j + 1]) {
          int temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
          flag = 1;
        }
      }
      if (flag)
        ctr++;
    }
    return ctr;
  }
}

int maxIndex(int *a, int n) {
  int pos = 0, max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] >= max) {
      max = a[i];
      pos = i;
    }
  }
  return pos;
}

void swapWithMax(int *a, int n) {
  int max_index = maxIndex(a, n);
  if (max_index < n - 1) {
    int temp = a[max_index];
    a[max_index] = a[n - 1];
    a[n - 1] = temp;
  }
}

void selectionSort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    swapWithMax(a, n - i);
  }
}

int numSwaps(int *a, int n) {
  int ctr = 0;
  for (int i = 0; i < n - 1; i++) {
    if (isSorted(a, n)) {
      return ctr;
    }
    if (maxIndex(a, n - i) != n - i - 1) {
      ctr++;
      swapWithMax(a, n - i);
    }
  }
  return ctr;
}