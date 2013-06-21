#include <iostream>
#include <cmath>

using namespace std;

int nt,x,y,k,t;

int main() {
   cin >> nt;
   for ( int t = 1; t <= nt; t++ ) {
      cin >> x;
      y = 0;
      while ( x%2 == 0 ) {
         y++;
         x /= 2;
      }

      if ( x == 1 ) k = 0; else k = 1;

      for ( int i = 3; i <= int(sqrt(double(x))); i++ )
         if ( x%i == 0 ) {
            k = 2;
            break;
         }

      if ( (k == 2) || ((y+k) % 2 == 1) ) cout << "YES"; else cout << "NO";
      cout << endl;
   }

   return 0;
}
