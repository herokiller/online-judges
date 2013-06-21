#include <iostream>

using namespace std;

int n,k,x,m1,m2,i;

int main() {
   cin >> n >> k;

   m1 = -10000; m2 = 10000;

   for ( i = 1; i <= n; i++ ) {
      cin >> x;
      if ( ( x < 0 ) && ( x > m1 ) ) m1 = x;
      if ( ( x > 0 ) && ( x < m2 ) ) m2 = x;
   }

   if (( ( k > 0 ) && ( k > m2 ) ) || ((k < 0) && (k < m1)))
      cout << "Impossible"; else {
         if ( k > 0 ) 
            cout << k << ' ' << abs(m1)*2 + k;
         else cout << m2*2 + abs(k) << ' ' << abs(k);
      }

   return 0;
}
