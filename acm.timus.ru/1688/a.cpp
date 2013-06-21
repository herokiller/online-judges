#include <iostream>

using namespace std;

long long n,sum,s,x,i;

int main() {
   cin >> sum >> n;
   sum *= 3;
   for ( i = 1; i <= n; i++ ) {
      cin >> x;
      s += x;
      if ( s > sum ) {
         cout << "Free after " << i << " times." << endl;
         return 0;
      }
   }

   cout << "Team.GOV!";
   return 0;
}
