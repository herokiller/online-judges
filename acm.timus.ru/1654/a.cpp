#include <iostream>
#include <string>

using namespace std;

char st[201000];
string s;
int i,nst = 0;

int main() {
   gets(st);
   s = st;

   for ( i = 0; i < s.length(); i++ ) {
      if ( nst > 0 )
         if ( s[i] == st[nst] ) {
            nst--;   
            continue;
         }
      nst++;
      st[nst] = s[i];
   }

   for ( i = 1; i <= nst; i++ )
      printf("%c",st[i]);
   return 0;
}
