#include <iostream>

using namespace std; 

double x,y,k,m,eps = 0.00000001;
int i,p1,p2;

int main() {
   cin >> x >> y;
   for ( i = 1; i <= 100000; i++ ) {
      k = (double(i)*x)/double(100);
      m = (double(i)*y)/double(100);

      p1 = int(k);

      if(( k-int(k) < eps )
       &&( k-int(k) > -eps)) p1 = int(k);

      if ( (k-int(k)-1 < eps)
        && (k-int(k)-1 > -eps)) p1 = int(k)+1;



      p2 = int(m) + 1;

      if ( (m-int(m) < eps) && (m-int(m) > -eps)) p2 = int(m);
      if ( (m-int(m)-1 < eps) && (m-int(m)-1 > -eps)) p2 = int(m)+1;       

      
      if ( p2 - p1 >= 2) {
         cout << i;
         return 0;
      }
   }
   return 0;
}
