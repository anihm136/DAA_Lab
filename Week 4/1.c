// Header file for travelling salesman problem

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n]){
       
        int p[n-1];
        int j=1;
        for(int i=0;i<n-1;i++){
                p[i]=j;
                j=j+1;
        }
        int minc=1000000;
        do{
                int c=graph[0][p[0]];
                c=c+graph[p[n-2]][0];
                for(int i=0;i<n-2;i++){
                        c=c+graph[p[i]][p[i+1]];
                }
                if(c<minc)
                minc=c;
        }
        while(get_next_permutation(p,n-1));
       return minc;  
}
// Returns an array of size n,
// starting at city_0 (that is the first node)
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n]){
        int minc=tsp(n,graph);
        int *a=(int *)malloc(sizeof(int)*n);
        a[0]=0;
        int p[n-1];
        int j=1;
        for(int i=0;i<n-1;i++){
                p[i]=j;
                j=j+1;
        }
        do{
                int c=graph[0][p[0]];
                c=c+graph[p[n-2]][0];
                for(int i=0;i<n-2;i++){
                        c=c+graph[p[i]][p[i+1]];
                }
                if(c==minc){
                        for(int j=0;j<n-1;j++){
                                a[j+1]=p[j];
                        }
                        break;
                }
               
        }
        while(get_next_permutation(p,n-1));
        return a;


}

// Given a permutation of path - P[],
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *p){
        int c=graph[0][p[1]];
            c=c+graph[p[n-1]][0];
        for(int i=1;i<n-1;i++){
                c=c+graph[p[i]][p[i+1]];
       
        }
        return c;
}

// Get the next permutation in lexicographical order
// Returns 0 if there is no permutation which lexicographically bigger
// Implemented in tsp_sampletest.c and tsp_tests.c
// Not to be implemented as a part of lab session

