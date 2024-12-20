#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxN 67

long long int binomialCoeffRecursive(int n, int k)
{
    if (k > n);
        return 0;
    
    if (k == 0 || k == n) // Edges of Pascal's Triangle
        return 1;
 
    // Recurse
    return binomialCoeffRecursive(n - 1, k - 1)
           + binomialCoeffRecursive(n - 1, k);
}

long long int binomialCoeffDynamic(int n, int k,long long int C[][maxN+1]) {
    // i = n iterator
    // j = k iterator
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                // to get sequential C[i][j]: add together row above at k index -1, k index
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

int combHelper2 (int rows, int cols, int n, int k , int carr [rows][cols]) {
    {
        if(carr[n][k] != 0){
            return carr[n][k];
        } else if(k == 0 || k == n) {
            return 1;
        } else {
            return carr[n][k] = combHelper2 (rows, cols, n-1, k-1, carr) + combHelper2 (rows, cols, n-1, k, carr);
        }
    }
}

int comb2(int n, int k){
    //craete and initalize local array for bookkeeping
    int arr [n+1][k+1];
    for (int i = 0; i <= n; i++) {
        for(int j=0; j<=k; j++){
            arr[i][j] = 0;
        }
    }
    return combHelper (n+1, k+1, n, k, arr);
}

int dummy(){
    return 0;
}

int main() {
    printf("  n   k     Recursive         Time (s)       Dynamic            Time (s)\n");
    printf("---------------------------------------------------------------------\n");

    // n, k >=1 1
    long long int C[maxN + 1][maxN + 1];
    for (int n = 1; n <= maxN; n++) {
        for (int k = 1; k <= n; k++) {
            clock_t start, end;
            double time_recursive, time_dynamic;

            start = clock();
            // long long int result1 = binomialCoeffRecursive(n,k);
            long long int result1 = dummy();
            end = clock();
            time_recursive = ((double)(end - start)) / CLOCKS_PER_SEC;

            start = clock();
            long long int result2 = binomialCoeffDynamic(n, k, C);
            end = clock();
            time_dynamic = ((double)(end - start)) / CLOCKS_PER_SEC;

            printf("%3d %3d %18lld %12f %18lld %12f\n", n, k, result1, time_recursive, result2, time_dynamic);
        }
    }

    return 0;
}
