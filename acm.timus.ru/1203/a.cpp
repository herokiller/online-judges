#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100

struct mass {
   int t1, t2;
};

mass a[MAXN];
 
int n, mt = 0, head[MAXN], d[MAXN];

bool ok(mass x, mass y) {
   return x.t2 < y.t2;
}

int main() {
   scanf("%d", &n);

   for ( int i = 1; i <= n; i++ )
      scanf("%d%d", &a[i].t1, &a[i].t2);

   sort(a+1, a+n+1, ok);

   for ( int i = 1; i <= n; i++ ) {
      if ( head[a[i].t2] == 0 ) 
         head[a[i].t2] = i;
      if ( a[i].t2 > mt ) 
         mt = a[i].t2;
   }

   for ( int i = 1; i <= mt; i++ ) {
      d[i] = d[i-1];

      if ( head[i] != 0 )
         for ( int j = head[i]; j <= n; j++ ) {
            if ( a[j].t2 > i) 
               break;

            if ( d[a[j].t1 - 1] + 1 > d[i] ) 
               d[i] = d[a[j].t1 - 1] + 1;
         }
   }

   printf("%d\n", d[mt]);

   return 0;
}
