#include <iostream>

using namespace std;

int main() {

   int n, k;

   scanf("%d%d", &n, &k);

   if ( n <= k ) {
      printf("2\n");
   } else {
      int x = n/k;
      if ( n%k != 0 ) { 
         x++;
         n -= (k - n%k);
         x += n/k;
         if ( n%k != 0 ) x++;
      } else {
         x *= 2;
      }

      printf("%d\n", x);
   }
   return 0;
}
