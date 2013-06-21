#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int i,n,j,last;
long long ans = 0,p1,p2;
char a[150][150];
char ch;
bool b[150];

void dfs( int v ) {
   b[v] = true;

   for ( int i = 1; i <= n; i++ )
      if ((b[i] == false) && (a[v][i] == '1')) {
         a[v][i] = '0'; a[i][v] = '0';
         dfs(i);
      }
}

int main() {
   memset(b,0,sizeof(b));
   scanf("%d\n", &n);
   cin >> p1 >> p2; getline(cin,s);

   for ( i = 1; i <= n; i++ ) {
      for ( j = 1; j <= n; j++ ) 
         scanf("%c", &a[i][j]);
      scanf("\n");
   }

   last = 0; ans = 0;

   for ( i = 1; i <= n; i++ )
      if ( b[i] == false ) {
         if ( last == 0 ) {
            last = i;
         } else {
            a[last][i] = 'a';
            a[i][last] = 'a';
            ans += p2;
            last = i;
         }
         dfs(i);
      }


   for ( i = 1; i <= n; i++ ) 
      for ( j = 1; j <= n; j++ ) 
         if ( a[i][j] == '1' ) {
            a[i][j] = 'd';
            a[j][i] = 'd';
            ans += p1;
         }

   
   cout << ans << endl;
   for ( i = 1; i <= n; i++ ) {
      for ( j = 1; j <= n; j++ )
         printf("%c", a[i][j]);
      printf("\n");
   }
            
   return 0;
}
