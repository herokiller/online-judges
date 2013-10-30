#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int N = 500;
const int INF = 1000*1000*1000;

int c[N][N], f[N][N], e[N], h[N], maxh[N];

int n, s, t, m;

int main() {
	scanf("%d", &m);

	n = 2*m+2;
	s = 0;
	t = n-1;
	                                     
	for ( int i = 1; i <= m; i++ ) {
		int x;
	 	scanf("%d", &x);
	 	c[s][i] = x;
	 	c[i+m][t] = 3*(m-1) - x;        
	}

	for ( int i = 1; i <= m; i++ )
		for ( int j = m+1; j < n-1; j++ )
			if ( i+m != j )
				c[i][j] = 3;

	h[s] = n;

	for (int i=0; i<n; ++i) {
		f[s][i] = c[s][i];
		f[i][s] = -f[s][i];
		e[i] = c[s][i];
	}

	int sz = 0;
	while (true) {
		if (sz == 0)
			for (int i = 0; i < n; ++i)
				if ((i != s) && (i != t) && (e[i] > 0)) {
					if ((sz > 0) && (h[i] > h[maxh[0]]))
						sz = 0;
					if ((sz == 0) || (h[i] == h[maxh[0]])) {						
						maxh[sz] = i;
						sz++;
					}
				}

		if (sz == 0)  
			break;

		while (sz > 0) {
			int i = maxh[sz-1];
			bool pushed = false;
			for (int j=0; (j < n) && (e[i] > 0); ++j)
				if ((c[i][j] - f[i][j] > 0) && (h[i] == h[j]+1)) {
					pushed = true;
					int addf = min(c[i][j] - f[i][j], e[i]);
					f[i][j] += addf;
					f[j][i] -= addf;
					e[i] -= addf;
					e[j] += addf;
					if (e[i] == 0)  
						--sz;
				}

			if (!pushed) {
				h[i] = INF;
				for (int j=0; j < n; ++j)
					if ((c[i][j] - f[i][j] > 0) && (h[j]+1 < h[i]))
						h[i] = h[j]+1;

				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}

	int ans = e[n-1];
	if (ans != m*(m-1)*3/2 ) {
		printf("INCORRECT\n");
	} else {
		printf("CORRECT\n");
		for ( int i = 1; i <= m; i++ )
			for ( int j = m+1; j < n-1; j++ )
				if (i+m < j)
					if ( f[i][j] == 3 )
						printf("%d > %d\n", i, j-m);
					else if ( f[i][j] == 2 )
						printf("%d >= %d\n", i, j-m);
					else if ( f[i][j] == 1 ) 
						printf("%d <= %d\n", i, j-m);
					else
						printf("%d < %d\n", i, j-m);							
	}

	return 0;
}
