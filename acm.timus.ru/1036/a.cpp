#include <iostream>
#include <cstdio>

using namespace std;

struct mass {
   int a[210];
};

mass a[60][500], c, d;
int n, sum;

int main() {
   scanf("%d%d", &n, &sum);

   if ( sum%2 != 0 ) {
      printf("0\n");
      return 0;
   }

   sum /= 2;

  
   a[0][0].a[1] = 1;

   for ( int i = 1; i <= n; i++ )
      for ( int j = 0; j <= i*9; j++ ) 
         for ( int k = 0; k <= 9; k++ )
            if ( j - k >= 0 ) {
               c = a[i-1][j-k];

               for ( int q = 1; q < 100; q++ ) {
                  a[i][j].a[q] += c.a[q];   
                  a[i][j].a[q+1] += a[i][j].a[q]/10;
                  a[i][j].a[q] %= 10;
               }

            } 

   c = a[n][sum];

   for ( int i = 1; i < 100; i++ )
      for ( int j = 1; j < 100; j++ )
         d.a[i+j-1] += c.a[i]*c.a[j];


   for ( int q = 1; q < 200; q++ ) {
      d.a[q+1] += d.a[q]/10;
      d.a[q] %= 10;
   }

   for ( int i = 200; i >= 1; i-- ) 
      if ( d.a[i] > 0 ) {
         for ( int j = i; j >= 1; j-- )
            printf("%d", d.a[j]);
         printf("\n");
         return 0;
      }

   printf("0\n");

   return 0;
}
