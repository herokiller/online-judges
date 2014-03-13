#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 105

using namespace std;

struct edge {
	int x, y, v;
};

edge e[N*N];


bool comp(edge A, edge B) {
	return A.v < B.v;
}

bool b[N];
int n, k, m, p[N], d[N], ne, c[N];

int main() {
	scanf("%d%d", &n, &k);
	for ( int i = 1; i <= k; i++ ) {
		int x;
		scanf("%d", &x);
		b[x] = 1;
	}

	for ( int i = 1; i <= n; i++ )
		if ( !b[i] ) {
			m++;
			p[i] = m;
		}
	m++;


	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			int x;
			scanf("%d", &x);
			if ( i < j ) {
				if ((b[i]) && (!b[j])) {
					if ( (d[j] == 0) || (x < d[j]) )
						d[j] = x;
				} else if (( !b[i]) && (b[j])) {
					if ( (d[i] == 0) || (x < d[i]))
						d[i] = x;
				} else if ( !b[i] && !b[j] ) {
					ne++;
					e[ne].x = p[i];
					e[ne].y = p[j];
					e[ne].v = x;
				}
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
		if ( d[i] > 0 ) {
			ne++;
			e[ne].x = p[i];
			e[ne].y = m;
			e[ne].v = d[i];
		}


	sort(e+1, e+ne+1, comp);

	for ( int i = 1; i <= m; i++ )
		c[i] = i;

	int ans = 0;
	for ( int i = 1; i <= ne; i++ ) {
		if (c[e[i].x] != c[e[i].y] ) {
			int nc = min(c[e[i].x], c[e[i].y]);
			int rc = max(c[e[i].x], c[e[i].y]);

			for( int j = 1; j <= m; j++ )
				if ( c[j] == rc ) 
					c[j] = nc;

			ans += e[i].v;
		}
	}

	printf("%d\n", ans);

	return 0;
}
