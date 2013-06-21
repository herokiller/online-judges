#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool ok;
long long a[1000000], m, ans;
int n = 3;

int main() {
   //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);


   for ( int i = 1; i <= 3; i++ )
      scanf("%I64d", &a[i]);


   sort(a+1, a+n+1);


   if (( a[1] == a[2] ) || (a[2] == a[3])) {
      printf("1");
      return 0;
   }


   m = a[2] - a[1];
   if ( a[3] - a[2] < m ) 
      m = a[3] - a[2];

   
   n++; a[n] = m; ans = 1;
   ok = false;

   while ( true ) {
      ans++;

      for ( int i = 1; i <= n-1; i++ ) {
         if ( a[i] == a[n] ) ok = true;

         long long x = a[i] - a[n];
         if ( x < 0 ) x = -x;
         if ( x < m ) m = x;


      }

      if ( ok ) break;

      n++;
      a[n] = m;
   }


   printf("%d", ans);
   return 0;
}
