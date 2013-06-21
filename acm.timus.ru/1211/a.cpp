#include <iostream>

using namespace std;

int nt,i,j,x,k,self,n,a[30000], b[30000];
bool chain;

int main() {
   scanf("%d", &nt);
   for ( i = 1; i <= nt; i++ ) {
      scanf("%d", &n);

      for ( j = 1; j <= n; j++ ) 
         scanf("%d", &a[j]);

      memset(b,0,sizeof(b)); k = 0; chain = 0; self = 0;


      for ( j = 1; j <= n; j++ ) 
         if ( b[j] == 0 ) {
            k++;  x = j;

            while (true) {
               if ( b[x] == k ) {
                  chain = 1; break;
               }
               if ( b[x] != 0 ) 
                  break;

               b[x] = k; x = a[x];
               if ( x == 0 ) {
                  self++;
                  b[x] = k;
                  break;
               }
            }
         }
      
      if (( self == 1 ) && (chain == 0)) 
         printf("YES\n"); else printf("NO\n");

   }
   return 0;
}
