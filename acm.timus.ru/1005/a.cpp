#include <iostream>
#include <cstdio>

using namespace std;

int n, a[30], allsum = 0, ans = 0;

int main() {
   scanf("%d", &n);

   for ( int i = 1; i <= n; i++ ) {
      scanf("%d", &a[i]);
      allsum += a[i];
      
   }

   ans = allsum;

   for ( int i = 0; i < (1 << n); i++ ) {
      int  s = 0;
      for ( int j = n-1; j >= 0; j-- ) 
         if ( (i&(1 << j)) != 0 ) 
            s += a[j+1];

      int y = allsum - s - s;
      if ( y < 0 ) y = -y;

      if ( y < ans ) ans = y;

   }

   printf("%d\n", ans);
      
   return 0;
}
