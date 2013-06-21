#include <iostream>

using namespace std;

int x, n, a[100100], b[100], c[100], nans = 0;

int sum( int x ) {
   int s = 0;
   while ( x > 0 ) { 
      s += (x%10);
      x /= 10;
   }
   return s;
}


int main() {
//   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

   scanf("%d", &x);

   for ( int i = 1; i < 100000; i++ ) {
      a[i] = sum(i);
      b[a[i]]++;
   }


   for ( int i = 45; i >= 1; i-- ) {
      while ((b[i] > 0) && (i <= x)) {
         c[i]++;
         b[i]--;
         x -= i; 
         nans++;
      } 
   }

   printf("%d\n", nans);

   for ( int i = 1; i < 100000; i++ ) {
      if ( c[a[i]] > 0 ) {
         printf("%d ", i);
         c[a[i]]--;  
      }
   }

   return 0;
}
