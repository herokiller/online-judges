#include <iostream>                      
#include <string>


using namespace std;

bool b[1000000];
char s[1000000];

int main() {
   //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

   gets(s);

   memset(b,0,sizeof(b));

   for ( int i = 0; i < strlen(s); i++ ) {
      int x = 0;
      for ( int k = 1; k <= 6; k++ ) {
         x = 0;
         for ( int j = 1; j <= k; j++ ) {
            if ( i + j - 1 < strlen(s) )
               x = x*10 + int(s[i+j-1]-'0');
         }
         b[x] = true;
      }

   }

   for ( int i = 1; i <= 1000000; i++ )
      if ( b[i] == false ) {
         printf("%d\n", i);
         return 0;
      }


   return 0;
}
