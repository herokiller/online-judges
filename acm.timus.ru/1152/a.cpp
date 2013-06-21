#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 20

int a[MAXN+10], d[(1 << MAXN)+10], s[(1 << MAXN)+10], n;

int main() {
   scanf("%d", &n);
   for ( int i = 1; i <= n; i++ ) 
      scanf("%d", &a[i]);

   for ( int i = 0; i < (1 << n); i++ ) {
      for ( int j = 0; j <= n-1; j++ )  
         if ( (i & (1 << j)) == 0 ) 
            s[i] += a[j+1];
      d[i] = 10000000;
   }

   d[0] = 0;

   for ( int i = 0; i < (1 << n)-1; i++ ) {
      for ( int j = 0; j <= n-1; j++ ) {
         int k = i;
         for ( int q = 0; q < 3; q++ )
            k = k | (1 << ((j+q)%n));

         if ( d[k] > d[i] + s[k])
            d[k] = d[i] + s[k];
      }
   }

   printf("%d\n", d[(1 << n)-1]);
   return 0;
}
