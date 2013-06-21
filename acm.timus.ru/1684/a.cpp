#include <iostream>
#include <string>

using namespace std;

char ch[80000];
string ans[80000],s1,s2;
int n, p[200000]; 
bool ok;

void kmp(string s) {
   int x = 0, i, j, nans = 0; p[0] = 0;

   for ( i = 1; i < s.length(); i++ ) {
      while( (x > 0) && (s[x] != s[i]) ) x = p[x - 1];
      if ( s[x] == s[i] ) x++;
      p[i] = x;
   }

   x = s.length() - 1; ok = 1;

   while (x >= n+1) {
      if (p[x] == 0) {
         ok = 0; break; 
      } else {
         nans++; ans[nans] = "";

         for ( i = x - p[x] + 1; i <= x; i++ )
            ans[nans] += s[i];
         x -= p[x];
      }
   }

   if ( ok == 0 )
      printf("Yes");
   else {
      printf("No\n");
      for ( i = nans; i >= 1; i-- ) {
         for ( j = 0; j < ans[i].length(); j++ )
            printf("%c",ans[i][j]);
         printf(" ");
      }
   }
   printf("\n");
}


int main() {
   scanf("%s\n",ch); s1 = ch; scanf("%s",ch); s2 = ch;

   n = s1.length(); s1 = s1 + '#' + s2;

   kmp(s1);

   return 0;
}
