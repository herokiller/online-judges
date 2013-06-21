#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 120

struct mass {
   int ch1, ch2, n;
   int num[MAXN];
};

int a[MAXN][MAXN], n, k;
bool b[MAXN];
mass d[MAXN];

void dfs(int ver) {

   int ch1, ch2;
   b[ver] = true;

   for ( int i = 1; i <= n; i++ )
      if (( a[ver][i] != 0 ) && ( !b[i] )) {
         if (d[ver].ch1 == 0 )
            d[ver].ch1 = i; else d[ver].ch2 = i;

         dfs(i);
      }

   ch1 = d[ver].ch1;
   ch2 = d[ver].ch2;
   
   if ( d[ver].ch1 != 0 ) {
      d[ver].num[2] = a[ver][ch1] + a[ver][ch2];
      d[ver].n = 2;
      d[ver].num[1] = a[ver][ch1];
      if ( a[ver][ch2] > d[ver].num[1] ) d[ver].num[1] = a[ver][ch2];
   }

   d[ver].n += d[ch1].n + d[ch2].n;

   for ( int i = 1; i <= d[ch1].n; i++ )
      if ( d[ch1].num[i] + a[ver][ch1] > d[ver].num[i+1] )
         d[ver].num[i+1] = d[ch1].num[i] + a[ver][ch1];

   for ( int i = 1; i <= d[ch2].n; i++ )
      if ( d[ch2].num[i] + a[ver][ch2] > d[ver].num[i+1] )
         d[ver].num[i+1] = d[ch2].num[i] + a[ver][ch2];

   for ( int i = 0; i <= d[ch1].n; i++ )
      for ( int j = 0; j <= d[ch2].n; j++ )
         if ( d[ch1].num[i] + d[ch2].num[j] + a[ver][ch1] + a[ver][ch2] > d[ver].num[i+j+2] ) 
            d[ver].num[i+j+2] = d[ch1].num[i] + d[ch2].num[j] + a[ver][ch1] + a[ver][ch2];
    
}

int main() {
   scanf("%d%d", &n, &k);

   int x, y, w;
   for ( int i = 1; i < n; i++ ) {
      scanf("%d%d%d", &x, &y, &w);
      a[x][y] = w; a[y][x] = w;
   }

   dfs(1);

   int ans = d[1].num[k];

   printf("%d\n", ans);
   return 0;
}
