#include <iostream>
#include <cstdio>

using namespace std;

int n, k, ans;

int main() {

   scanf("%d%d", &n, &k);

   if ( n == 2 ) { printf("0"); return 0; }

   if ( k > n/2 ) k = n - k + 1;

   ans = n - k - 2;

   printf("%d", ans);
   return 0;
}
