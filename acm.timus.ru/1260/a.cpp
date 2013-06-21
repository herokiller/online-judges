#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 60

int d[MAXN][MAXN][MAXN], n;

int main() {
   scanf("%d", &n);

   d[1][1][1] = 1;

   d[2][1][2] = 1;

   for ( int i = 3; i <= n; i++ ) {
      for ( int j = 1; j <= i-1; j++ ) 
         for ( int k = 1; k <= i-1; k++ )
            if ( d[i-1][j][k] != 0 ) {
               if ( j + 1 == k) 
                  d[i][k+1][k] += d[i-1][j][k];

               if ( k + 1 == j ) 
                  d[i][k][k+1] += d[i-1][j][k];

               if ( k == i - 1 ) 
                  d[i][k][k+1] += d[i-1][j][k];

               if ( j == i - 1 ) 
                  d[i][k][i] += d[i-1][j][k];
            }
   }

   int s = 0;

   for ( int i = 1; i <= n; i++ )
      for ( int j = 1; j <= n; j++ ) 
         s += d[n][i][j];


   /*
   for ( int i = 1; i <= n; i++ ) {
      for ( int j = 1; j <= i; j++ )
         for ( int k = 1; k <= i; k++ )
            cout << i << ") " << j << ' ' << k << " - " << d[i][j][k] << endl;
      cout << endl;
   }

   return 0;

   */       

   printf("%d", s);

   return 0;
}
