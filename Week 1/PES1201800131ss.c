int searchFirstOccurrence(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int searchLastOccurrence(int arr[], int n, int key) {
  int lastindex = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      lastindex = i;
    }
  }
  return lastindex;
}

int numOccurrences(int arr[], int n, int key) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      count++;
    }
  }
  return count;
}
