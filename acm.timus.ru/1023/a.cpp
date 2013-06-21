#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int ans,i,n;
   
   cin >> n;

   ans = n;

   for ( i = 2; i <= int(sqrt(double(n))); i++)
      if ( n%i == 0 ) {
         if (( i < ans ) && (i != 2)) ans = i;
         if (( n/i < ans ) && (n/i != 2)) ans = n/i;
      }


   cout << ans-1;

   return 0;
}
