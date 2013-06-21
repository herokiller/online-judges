#include <iostream>
#include <cmath>

using namespace std;

double m,x2,y2;

int n,x,y,i;


int main() {
   cin >> n;

   for ( i = 1; i <= n; i++ ) {
      cin >> x >> y;
      x2 = double(x) - double(1005);
      y2 = double(y) - double(1005);

      if ( sqrt(x2*x2 + y2*y2) > m )
         m = sqrt(x2*x2 + y2*y2);
   }
   cout << 1005 << ' ' << 1005 << ' ';
   printf("%.10f",m);

   return 0;
}
