#include <iostream>

using namespace std;

long long x, y;

int main() {

   scanf("%I64d%I64d", &x, &y);

   if ( x > y ) {
      long long c = x;
      x = y;
      y = c;
   }

   long long ans = 0, i = 2, step = 1;
   while ( i <= y ) {
      i *= 2;
//      step++;

      long long k1 = y - x + 1;
      long long k2 = (i - (x%i))%i;
      k1 -= k2;

      long long k3 = k1/i;

      ans += step*k3*2;

      if ( x%i == 0 ) ans -= step;

      if ( k1%i == 1 ) ans += step; else
      if ( k1%i > 1 ) ans += step*2;

   }

   printf("%I64d\n", ans);
   return 0;
}
