#include <iostream>

using namespace std;

int x,nans,ans[1000],i;

int main() {
   cin >> x;
   nans = 0;

   while (x > 1) {
      nans++;
      ans[nans] = x/2;
      x = (x/2)+(x%2);      
   }

   cout << nans << endl;
   for ( i = 1; i <= nans; i++ )
      cout << ans[i] << ' ';

   return 0;
}
