#include <iostream>
#include <string>

using namespace std;

string b[500],s,s1;
bool ok;
int x,k,n,q,i,j;

int main() {
   cin >> x >> n >> q; getline(cin,s);

   k = 0;

   for ( i = 1; i <= n; i++ ) {
      getline(cin,s); s1 = "";
    
      for ( j = 0; j < s.length(); j++ )
         if ( s[j] == '#' ) break; else s1 += s[j];

      ok = 0;
      for ( j = 1; j <= k; j++ )
         if ( b[j] == s1 ) {
            ok = 1;
            break;
         }

      if ( ok == 0 ) {
         q--;
         if ( q == -1 ) {
            cout << s << endl;

            return 0;
         }
         k++;
         b[k] = s1;
      }
   }

   return 0;
}
