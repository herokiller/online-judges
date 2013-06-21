#include <iostream>
#include <string>

using namespace std;

bool ok; char a[6][6]; int n;
char s[1001];

void rec ( int i0, int j0, int p, bool b[6][6]) {
   
   if ( ok == 1 ) return;

   if ( a[i0][j0] != s[p] ) return;

   if ( p == strlen(s)-1 ) {
      ok = 1; return;   
   }

   bool c[6][6]; 
   for ( int i = 0; i < 6; i++ )
      for ( int j = 0; j < 6; j++ )
         c[i][j] = b[i][j];
   c[i0][j0] = 1;


   if ( c[i0 + 1][j0] == 0 ) rec(i0 + 1, j0, p + 1, c);
   if ( c[i0 - 1][j0] == 0 ) rec(i0 - 1, j0, p + 1, c);
   if ( c[i0][j0 + 1] == 0 ) rec(i0, j0 + 1, p + 1, c);
   if ( c[i0][j0 - 1] == 0 ) rec(i0, j0 - 1, p + 1, c);
}

bool check() {
   bool b[6][6];
   
   for ( int i = 1; i <= 4; i++ ) 
      for ( int j = 1; j <= 4; j++ ) {
         memset(b,0,sizeof(b)); ok = false;
         for ( int k = 0; k <= 5; k++ ) {
            b[0][k] = 1; b[5][k] = 1; b[k][0] = 1; b[k][5] = 1;
         }

         rec(i,j,0,b);

         if ( ok == 1 ) return ok;
      }

   return ok;
}

int main() {

   for ( int i = 1; i <= 4; i++ ) {
      for ( int j = 1; j <= 4; j++ ) {
         scanf("%c", &a[i][j]);
      }
      scanf("\n");
   }

   scanf("%d\n", &n);
   for ( int i = 1; i <= n; i++ ) {
      scanf("%s", s);

      printf("%s: ", s); 

      if ( check() == 1 ) cout << "YES"; else cout << "NO";

      printf("\n");
   }
   return 0;
}
