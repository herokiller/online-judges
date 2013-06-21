#include <iostream>

using namespace std;

int a[110][110], c[110], money[110], b[110], i, j, n, m, k, q, res, ans;

int main() {
   scanf("%d%d", &n, &m);

   for ( i = 1; i <= n; i++ )
      for ( j = 1; j <= n; j++ ) 
         if ( i == j ) a[i][j] = 0; else a[i][j] = 100000;

         
   for ( i = 1; i <= m; i++ ) {
      scanf("%d", &k);
      for ( j = 1; j <= k; j++ )
         scanf("%d", &c[j]);

      for ( j = 1; j <= k; j++ )
         for ( q = j+1; q <= k; q++ ) {
            a[c[j]][c[q]] = 1;
            a[c[q]][c[j]] = 1; 
         }
   }

   for ( k = 1; k <= n; k++ )
      for ( i = 1; i <= n; i++ )
         for ( j = 1; j <= n; j++ )
            if ( a[i][k] + a[k][j] < a[i][j] ) a[i][j] = a[i][k] + a[k][j];


   scanf("%d", &m);

   for ( i = 1; i <= m; i++ )
      scanf("%d%d%d", &money[i], &c[i], &b[i]);

   ans = 0; res = 100000;

   for ( i = 1; i <= n; i++ ) {
      k = 0;
      for ( j = 1; j <= m; j++ ) {
         if ( a[c[j]][i] == 100000 ) {
            k = -1;
            break;
         } 
         
         if ( b[j] == 1 ) continue;

         if ( a[c[j]][i]*4 > money[j] ) {
            k = -1;
            break;
         }

         k += a[c[j]][i]*4;
      }

      if ( k < 0 )
         continue;

      if ( k < res ) {
         res = k;
         ans = i;
      }
   }

   if ( ans == 0 ) {
      printf("0\n");
      return 0;
   }

   printf("%d %d", ans, res);

   return 0;
}
