#include <stdio.h>
#include "graphSearch.h"

void dfs(int n, const int graph[][n], int visited[n], int i, int par) {
  visited[i]+=1;
  for (int k = 0; k < n; k++) {
    if (graph[i][k] && k!=par) {
      if (visited[k]) {
        visited[k]+=1;
      } else {
        dfs(n, graph, visited, k, i);
      }
    }
  }
}

void frog_dfs(int n, const int graph[][n], int visited[n], int i, int j, int *count) {
  visited[i] = 1;
  (*count)++;
  for (int k = 0; k < n; k++) {
    int chk = (i>k?i-k:k-i);
    if (graph[i][k] && chk<=j) {
      if (!visited[k]) {
        frog_dfs(n, graph, visited, k, j, count);
      }
    }
  }
}

bool isTree(int n, const int graph[][n]) {
  int visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  dfs(n, graph, visited, 0, 0);
  for (int i = 0; i < n; i++) {
    if (visited[i] != 1) {
      return false;
    }
  }
  return true;
}

Result pepesAnswers(int n, const int safeSeq[][n]) {
  Result res;
  int visited[n];
  int comp = 0;
  int count = 0;
  int max = 0;

  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      count = 0;
      comp++;
      frog_dfs(n, safeSeq, visited, i, n, &count);
      if (count > max) {
        max = count;
      }
    }
  }

  res.numDeliveryFrogs = comp;
  res.maxHouses = max;

  return res;
}

Result pepesAnswersWithK(int n, const int safeSeq[][n], int k) {
  Result res;
  int visited[n];
  int comp = 0;
  int count = 0;
  int max = 0;

  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      count = 0;
      comp++;
      frog_dfs(n, safeSeq, visited, i, k, &count);
      if (count > max) {
        max = count;
      }
    }
  }


  res.numDeliveryFrogs = comp;
  res.maxHouses = max;

  return res;
}

