#include <iostream>

using namespace std;

char s[1000];
int a[500];


int main() {
   scanf("%s", s);

   memset(a,0,sizeof(0));

   for ( int i = 0; i < strlen(s); i++ ) 
      a[int(s[i])]++;

   int m = a[0], p = 0;

   for ( int i = 0; i < 500; i++ )
      if ( a[i] > m ) {
         m = a[i];
         p = i;
      }

   printf("%c", char(p));
}
