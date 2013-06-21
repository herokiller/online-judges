#include <cstdio>

using namespace std;

int a[100500], n, m, y0;

int main() {
   //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
   scanf("%d%d", &n, &m);
   for ( int i = 1; i <= n+m-1; i++ )
      scanf("%d", &a[i]);

   y0 = 0;

   for ( int i = 1; i <= n; i++ ) {

      int k1 = 1000000, k2 = -1, x = 0;

      for ( int j = i; j <= i+m-1; j++ ) {

         if ( a[j] < y0 ) {
            x = (y0-a[j])/(j-i+1);
            /*
            if ( (y0-a[j])%(j-i+1) != 0 ) 
               x--;
            */
            if ( x < k1 ) k1 = x;

         } else {
            x = (a[j]-y0)/(j-i+1);
            if ( (a[j]-y0)%(j-i+1) != 0 ) x++;

            if ( x > k2 ) k2 = x;
         }

      }

      if ( k2 >= 0 ) {
         printf("%d ", k2); 
         y0 += k2;
      } else
      if ( k1 > 0 ) {
         printf("-%d ", k1); 
         y0 -= k1;
      } else printf("0 ");

   }

   return 0;
}
                               
