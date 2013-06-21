#include <iostream>

using namespace std;

int n;

int main() {
//   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

   scanf("%d", &n);

   int ans = ( (n%2) + n )*(n/2)/2;

   printf("%d\n", ans);

   for ( int i = 1; i <= n/2; i++ ) 
      for ( int j = i+1; j <= n-i+1; j++ )
         printf("%d %d\n", i, j);


   return 0;
}
