#include <iostream>

using namespace std;

int n,m,a[100][100],i,j,k;
bool b[1000];

int main() {
   
   a[1][1] = 0;
   scanf("%d%d", &n, &m);

   for ( i = 1; i <= n; i++ )
      for ( j = 1; j <= m; j++ ) {
         if ( (i == 1) && ( j == 1 )) 
            continue;

         memset(b,0,sizeof(b));

         for ( k = 1; k <= i-1; k++ ) 
            b[a[k][j] ^ a[i-k][j]] = 1;

         for ( k = 1; k <= j-1; k++ )
            b[a[i][k] ^ a[i][j-k]] = 1; 

         for ( k = 0; k <= n*n; k++ )
            if ( b[k] == 0 ) {
               a[i][j] = k;
               break;
            }
      }


   if ( a[n][m] == 0 ) printf("[second]=:]"); else printf("[:=[first]");
   
   return 0;
}
