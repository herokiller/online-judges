#include <iostream>
#include <cstdio>

using namespace std;

int a[10], b[10];

bool check() {
   if (((b[2] + b[3] + b[4])%2 == b[5]) 
    && ((b[1] + b[3] + b[4])%2 == b[6]) 
    && ((b[1] + b[2] + b[4])%2 == b[7])) 
      return true; else return false;
}

int main() {
   for ( int i = 1; i <= 7; i++ )
      scanf("%d", &a[i]);

   for ( int i = 0; i <= 7; i++ ) {
      for ( int j = 1; j <= 7; j++ )
         b[j] = a[j];
      b[i] = (b[i] + 1 )%2;

      if ( check() ) {
         for ( int k = 1; k <= 7; k++ )
            printf("%d ", b[k]);
         return 0;
      }
   }
      
   return 0;
}
