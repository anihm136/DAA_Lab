#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tsp.h"

int tsp(int n, int graph[][n]) {
  int permutation[n];
  int mincost = INT_MAX;
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    int curCost = getCost(n, graph, permutation);
    if (curCost < mincost) {
      mincost = curCost;
    }
  } while(get_next_permutation(permutation, n));

  return mincost;
}

int* printPath(int n, int graph[][n]) {
  int permutation[n];
  int *minperm = (int *)calloc(sizeof(int),n);
  int mincost = tsp(n, graph);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    int curCost = getCost(n, graph, permutation);
    if (curCost == mincost) {
      for (int i = 0; i < n; ++i) {
        minperm[i] = permutation[i];
      }
      return minperm;
    }
  } while(get_next_permutation(permutation, n));
}

int getCost(int n, int graph[][n], int *P) {
  int cost = 0;
  for (int i = 0; i < n; i++) {
    int *curNode = graph[P[i]];
    int curcost = curNode[P[(i+1)%n]];
    cost += curcost;
  }
  return cost;
}
