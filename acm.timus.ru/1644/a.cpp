#include <iostream>
#include <string>

using namespace std;

string s;
int n,x,i,m1,m2;


int main() {
   cin >> n; getline(cin,s);

   m1 = 2; m2 = 10;
   for ( i = 1; i <= n; i++ ) {
      cin >> x; getline(cin,s);
      if (s[1] == 'h')
         if (x > m1) m1 = x;
      if (s[1] == 's')
         if (x < m2) m2 = x;
   }

   if ( m1 >= m2 ) cout << "Inconsistent"; else cout << m2;
   return 0;
}
