#include <iostream>

using namespace std;

#define MAXN 6005

struct mass {
   int val, next;
};

int n, d[MAXN][2], p[MAXN], r[MAXN], head[MAXN];
bool b[MAXN];
mass a[MAXN*2];


void dfs(int ver) { 
   b[ver] = 1;

   int x = head[ver];

   while (x > 0) {
      int i = a[x].val;
      if (!b[i]) {
         p[i] = ver;
         dfs(i);
      }

      x = a[x].next;
   }


   
   d[ver][1] = r[ver];

   x = head[ver];
   while (x > 0) {
      int i = a[x].val;
      if ( p[ver] != i)
         d[ver][1] += d[i][0];

      x = a[x].next;
   }

   

   x = head[ver];
   while (x > 0) {
      int i = a[x].val;
      if ( p[ver] != i) 
         if ( d[i][0] > d[i][1] ) 
            d[ver][0] += d[i][0];
         else 
            d[ver][0] += d[i][1];

      x = a[x].next;
   }

}


int main() {
   scanf("%d", &n);
   for ( int i = 1; i <= n; i++ ) 
      scanf("%d", &r[i]);

   int k = 0;
   for ( int i = 1; i < n; i++ ) {
      int x, y;
      scanf("%d%d", &x, &y);
      k++;
      a[k].next = head[x];
      a[k].val = y;
      head[x] = k;

      k++;
      a[k].next = head[y];
      a[k].val = x;
      head[y] = k;
      
   }

   dfs(1);

   int ans = d[1][1];
   if ( d[1][0] > ans ) ans = d[1][0];

   printf("%d\n", ans);

   return 0;
}
