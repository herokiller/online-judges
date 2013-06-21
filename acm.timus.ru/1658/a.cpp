#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


struct mass {
   short i, j, k;
   bool b;
};

struct mass2 {
   short i, j;
};

mass a[1020][10250];
mass2 q[10111100];

int c[1010];

int main() {
   
   int nq = 1, i = 0;
   q[1].i = 0;
   q[1].j = 0;
   a[0][0].b = true;


   while ( i < nq ) {
      i++;
      for ( int j = 1; j <= 9; j++ ) {
         short k1 = q[i].i + j;
         short k2 = q[i].j + j*j;

         if ( ( k1 < 1000 ) && ( k2 <= 10010 ) && (a[q[i].i][q[i].j].k < 100)) {
            if (( a[q[i].i][q[i].j].k + 1 < a[k1][k2].k ) || (a[k1][k2].b == false) ) {
               a[k1][k2].k = a[q[i].i][q[i].j].k + 1;
               a[k1][k2].i = q[i].i;
               a[k1][k2].j = q[i].j;
               a[k1][k2].b = true;

               nq++;
               q[nq].i = k1;
               q[nq].j = k2;
            }
         }
      }
   }
   

   int x, y, nt;
   scanf("%d", &nt);
   for ( int i = 1; i <= nt; i++ ) {
      scanf("%d%d", &x, &y);
      if ( x >= 1000 ) {
         printf("No solution\n");
      } else 
      if (( a[x][y].b == false ) ||  (a[x][y].k > 100)) {
         printf("No solution\n");
      } else {
         int n = 0;
         short k1, k2;

         while ( x > 0 ) {
            n++;
            k1 = a[x][y].i;
            k2 = a[x][y].j;

            c[n] = x - k1;
            x = k1; 
            y = k2;
         }

         sort(c+1, c+n+1);

         for ( int j = 1; j <= n; j++ )
            printf("%d", c[j]);
         printf("\n");
      }
   }

   return 0;
}

