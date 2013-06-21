#include <iostream>

using namespace std;

int main() {
   int n, m;
   scanf("%d%d", &n, &m);
   for ( int i = 1; i <= n; i++ )
      printf("%d ", i);

   printf("\n");

   int x = n + n + 1;
   int y = x;

   for ( int i = 1; i <= m; i++ ) {
      printf("%d ", x);
      x += y;
   }   
}
