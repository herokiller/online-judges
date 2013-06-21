#include <iostream>

using namespace std;

#define MAXN 10010

int a[MAXN], d[MAXN], n;

int main() {
   int l1, l2, l3, c1, c2, c3;
   scanf("%d%d%d%d%d%d", &l1, &l2, &l3, &c1, &c2, &c3);

   int k1, k2, c;
   scanf("%d%d%d", &n, &k1, &k2);

   if ( k1 > k2 ) {
      c = k1; k1 = k2; k2 = c;
   }


   int x;
   for ( int i = 2; i <= n; i++ ) {
      scanf("%d", &x);
      a[i] = x;
   }

   d[k1] = 0;

   for ( int i = k1+1; i <= k2; i++ ) 
      for ( int j = i-1; j >= k1; j-- ) {
         if ( a[i] - a[j] <= l1 ) {
            if ( (d[i] == 0 ) || (d[j] + c1 < d[i]))
               d[i] = d[j] + c1;
         } else 
         if ( a[i] - a[j] <= l2 ) {
            if ( (d[i] == 0 ) || (d[j] + c2 < d[i])) 
               d[i] = d[j] + c2;
         } else 
         if ( a[i] - a[j] <= l3 ) {
            if ( (d[i] == 0 ) || (d[j] + c3 < d[i]))
               d[i] = d[j] + c3;
         } else break;
      }


   printf("%d\n", d[k2]);

   return 0;
}
