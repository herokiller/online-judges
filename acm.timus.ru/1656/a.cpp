#include <iostream>
#include <algorithm>

using namespace std;

int c[200], a[20][20], i, j, k, p, n;

int main() {
   scanf("%d", &n);
   for ( i = 1; i <= n*n; i++ )
      scanf("%d", &c[i]);

   sort(c+1, c+n*n+1); p = n*n+1;


   for ( i = 0; i <= n - 1; i++ ) 
      for ( j = 1; j <= n; j++ )
         for ( k = 1; k <= n; k++ )
            if ( abs(j - n/2 - 1) + abs( k - n/2 - 1) == i ) {
               p--;
               a[j][k] = c[p];
            }

   for ( i = 1; i <= n; i++ ) {
      for ( j = 1; j <= n; j++ )
         printf("%d ", a[i][j]);
      printf("\n");
   }

   return 0;
}
