void mergeSortedHalfs(int *a, int start, int mid, int end) {
  int s1 = start;
  int s2 = mid + 1;
  int e1 = mid;
  int e2 = end;
  int b[end - start + 1];
  int *p = b;

  while (s1 <= e1 && s2 <= e2) {
    if (a[s1] > a[s2]) {
      *(p++) = a[s2++];
    } else {
      *(p++) = a[s1++];
    }
  }
  while (s1 <= e1) {
    *(p++) = a[s1++];
  }
  while (s2 <= e2) {
    *(p++) = a[s2++];
  }

  for (int i = 0; i < end - start + 1; ++i) {
    a[start + i] = b[i];
  }
}

void mergeSort(int *a, int start, int end) {
  if (start < end) {
    int mid = (end + start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    mergeSortedHalfs(a, start, mid, end);
  }
}

void insertionSort(int *a, int start, int end) {
  for (int i = start + 1; i <= end; ++i) {
    int temp = a[i];
    int j = i - 1;
    while (j >= start && a[j] > temp) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
}

void selectiveMergeSort(int *a, int start, int end, int parameter) {
  if (end - start < parameter) {
    insertionSort(a, start, end);
  }
  if (start < end) {
    int mid = (end + start) / 2;
    selectiveMergeSort(a, start, mid, parameter);
    selectiveMergeSort(a, mid + 1, end, parameter);
    mergeSortedHalfs(a, start, mid, end);
  }
}
