#include <iostream>
#include <cstdio>

using namespace std;


int a[7] = {0, 10, 50, 100, 500, 1000, 5000};
int main() {
   int s = 0, m = 0, x;

   for ( int i = 1; i <= 6; i++ ) {
      scanf("%d", &x);
      if ((m == 0 ) && (x != 0))
         m = a[i];

      s += x*a[i];
   }


   int c;
   scanf("%d", &c);
   int n1 = ((s-m)/c) + 1;
   int n2 = s/c;

   int n = n2 - n1 + 1;

   printf("%d\n", n);

   for ( int i = n1; i <= n2; i++ )
      printf("%d ", i);
      
   return 0;
}
