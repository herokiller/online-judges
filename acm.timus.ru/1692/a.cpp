#include <iostream>

using namespace std;

int a[500][500],n,kol,x,i,j;

int main() {
   cin >> n;

   x = 3; kol = 3;

   a[1][2] = 1; a[1][3] = 2; a[2][3] = 3;
   a[2][1] = 1; a[3][1] = 2; a[3][2] = 3;

   while (true) {
      if (x + kol > n) {
         cout << kol << endl;

         for ( i = 1; i <= kol; i++ ) {
            cout << kol-1 << ' '; 
            for ( j = 1; j <= kol; j++ )
               if ( i != j ) cout << a[i][j] << ' ';
            cout << endl;
         }
         return 0;
      } else {
         kol++;
         for ( i = 1; i <= kol-1; i++ ) {
            x++;
            a[i][kol] = x;
            a[kol][i] = x;
         } 
      }
   }
   return 0;
}
