#include <string.h>

int searchFirstOccurrence(char *pattern, char *text) {
  int textLength = strlen(text);
  int patternLength = strlen(pattern);
  for (int i = 0; i <= textLength-patternLength; i++) {
    int textindex = i;
    int j;
    for (j = 0; pattern[j]; j++) {
      if (text[textindex] != pattern[j])
        break;
      textindex++;
    }
    if (!pattern[j])
      return i;
  }
  return -1;
}

int searchLastOccurrence(char *pattern, char *text) {
  int textLength = strlen(text);
  int patternLength = strlen(pattern);
  int lastindex = -1;
  for (int i = 0; i <= textLength-patternLength; i++) {
    int textindex = i;
    int j;
    for (j = 0; pattern[j]; j++) {
      if (text[textindex] != pattern[j])
        break;
      textindex++;
    }
    if (!pattern[j])
      lastindex = i;
  }
  return lastindex;
}

int numOccurrences(char *pattern, char *text) {
  int textLength = strlen(text);
  int patternLength = strlen(pattern);
  int numoccur = 0;
  for (int i = 0; i <= textLength-patternLength; i++) {
    int textindex = i;
    int j;
    for (j = 0; pattern[j]; j++) {
      if (text[textindex] != pattern[j])
        break;
      textindex++;
    }
    if (!pattern[j])
      numoccur++;
  }
  return numoccur;
}

int longestPrefix(char *pattern, char *text) {
  int textLength = strlen(text);
  int patternLength = strlen(pattern);
  int prefixLength = 0;
  for (int i = 0; i <= textLength-patternLength; i++) {
    int textindex = i;
    int j;
    for (j = 0; pattern[j]; j++) {
      if (text[textindex] != pattern[j])
        break;
      textindex++;
    }
    if (j > prefixLength)
      prefixLength = j;
  }
  return prefixLength;
}

int charactersCompared(char *pattern, char *text) {
  int textLength = strlen(text);
  int patternLength = strlen(pattern);
  int compared = 0;
  for (int i = 0; i <= textLength-patternLength; i++) {
    int textindex = i;
    for (int j = 0; pattern[j]; j++) {
      compared++;
      if (text[textindex] != pattern[j])
        break;
      textindex++;
    }
  }
  return compared;
}
