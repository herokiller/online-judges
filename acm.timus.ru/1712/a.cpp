#include <iostream>
#include <cstdio>

using namespace std;

char a[5][5], b[5][5], c[5][5];

int main() {

   for ( int i = 0; i < 4; i++ ) {
      for ( int j = 0; j < 4; j++ )
         scanf("%c", &a[i][j]);
      scanf("\n");
   }

   for ( int i = 0; i < 4; i++ ) {
      for ( int j = 0; j < 4; j++ ) 
         scanf("%c", &c[i][j]);
      scanf("\n");
   }

   for ( int k = 0; k < 4; k++ ) {
      for ( int i = 0; i < 4; i++ )
         for ( int j = 0; j < 4; j++ ) 
            if (a[i][j] == 'X') 
               printf("%c", c[i][j]);

      for ( int i = 0; i < 4; i++ ) 
         for ( int j = 0; j < 4; j++ )
            b[j][3-i] = a[i][j];

      for ( int i = 0; i < 4; i++ ) 
         for ( int j = 0; j < 4; j++ )
            a[i][j] = b[i][j];

   }

   return 0;
}
