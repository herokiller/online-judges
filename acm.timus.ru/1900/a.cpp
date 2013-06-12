#include <iostream>
#include <stdio.h>

#define MAXN 520

using namespace std;

struct mass {
	int val, prev;
};

mass d[MAXN][MAXN];

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n-1; i++ )
		for ( int j = i+1; j <= n; j++ )
			scanf("%d", &a[i][j]);



	for ( int i = 1; i <= n-1; i++ ) {
		int cur = 0;
		for ( int j = n; j >= i+1; j-- ) {
			cur += a[i][j];
			b[i][j] = cur;
		}
	}


	for ( int j = 2; j <= n; j++ ) {
		int cur = 0;
		for ( int i = j-1; i >= 1; i-- ) {
			cur += b[i][j];
			c[i][j] = cur;
		}
   	}
				
	for ( int i = 2; i <= n; i++ )
		for ( int j = 1; j <= i; j++ )
			for ( int k = 1; k <= i-1; k++ )
				if ( d[k][j-1].val + c[k][i] >= d[i][j].val ) {
					d[i][j].val = d[k][j-1].val + c[k][i];
					d[i][j].prev = k;
				}			

	int ans = 0, p = 0;
	for ( int i = 2; i <= n; i++ )
		if ( d[i][m].val >= ans ) {
			ans = d[i][m].val;
			p = i;
		}

	int path[MAXN], np = m;
	while ( np > 0 ) {
		path[np] = p-1;
		p = d[p][np].prev;
		np--;	
	}


	printf("%d\n", ans);
	for ( int i = 1; i <= m; i++ )
		printf("%d ", path[i]);

	return 0;
}
