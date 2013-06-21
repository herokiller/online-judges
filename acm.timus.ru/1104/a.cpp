#include <iostream>
#include <string>

using namespace std;

char s[1000100];
int a[1000100], i,x,y,j, n;
bool ok;

int main() {
   scanf("%s", s);


   n = strlen(s);
   for ( j = 0; j < n; j++ ) 
      if (( int(s[j]) >= int('A') ) && ( int(s[j]) <= int('Z')) ) 
         a[j] = int(s[j] - 'A' + 10); else a[j] = int(s[j] - '0');
             
             

   for ( i = 2; i <= 36; i++ ) {
      y = 0;
      ok = 0;

      for ( j = 0; j < n; j++ ) {
         if ( a[j] >= i ) {
            ok = 1;
            break;
         }

         y = (y*i + a[j])%(i-1);
      }

      if ( ( ok == 0 ) && ( y == 0 ) ) {
         printf("%d", i);
         return 0;
      }
   }

   printf("No solution.");
   
   return 0;
}
