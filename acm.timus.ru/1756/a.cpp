#include <iostream>
#include <cstdio>

using namespace std;

int m, d1, d2, x, y;

int main() {
//   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
   scanf("%d%d%d", &m, &d1, &d2);
   x = (m*d1)/d2;
   y = (m*d1)%d2;

   for ( int i = 1; i <= y; i++ )
      printf("%d ", x+1);

   for ( int i = 1; i <= d2 - y; i++ )
      printf("%d ", x);

   return 0;
}
