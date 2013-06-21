#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 110

struct mass {
   long long val;
   int i, j;
};

int n, m;
int a[MAXN][MAXN*5];
mass d[MAXN][MAXN*5];


int main() {

   scanf("%d%d", &n, &m);

   for ( int i = 1; i <= n; i++ )
      for ( int j = 1; j <= m; j++ ) 
         scanf("%I64d", &a[i][j]);

   for ( int j = 1; j <= m; j++ ) 
      d[1][j].val = a[1][j];

   for ( int i = 2; i <= n; i++ ) {
      for ( int j = 1; j <= m; j++ ) {
         d[i][j].val = d[i-1][j].val + a[i][j];
         d[i][j].i = i-1;
         d[i][j].j = j;

         if ( j > 1 ) 
            if ( d[i][j-1].val + a[i][j] < d[i][j].val ) {
               d[i][j].val = d[i][j-1].val + a[i][j];
               d[i][j].i = i;
               d[i][j].j = j-1;
            }
      }
      for ( int j = m; j >= 1; j-- ) {
         if ( j < m ) 
            if ( d[i][j+1].val + a[i][j] < d[i][j].val ) {
               d[i][j].val = d[i][j+1].val + a[i][j];
               d[i][j].i = i;
               d[i][j].j = j+1;
            }
      }
   }
         

   int nans = 0, ans[MAXN*MAXN*5], i0 = n, j0 = 1;
   long long mm = d[n][1].val;

   for ( int j = 2; j <= m; j++ )
      if ( d[n][j].val < mm ) {
         mm = d[n][j].val;
         j0 = j;
      }

   while ( i0 > 0 ) {
      nans++;
      ans[nans] = j0;
      int k1 = d[i0][j0].i;
      int k2 = d[i0][j0].j;
      i0 = k1; j0 = k2;
   } 

   for ( int i = nans; i >= 1; i-- ) 
      printf("%d ", ans[i]);

   return 0;
}
