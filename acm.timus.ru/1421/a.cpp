#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 210;
const int INF = 1000*1000*1000;

int c[N][N], f[N][N], e[N], h[N], maxh[N];

int main() {

	int n, s, t, m, x, t1 = 0, t2 = 0;

	scanf("%d", &m);
	n = 2*m+2;
	s = 0;
	t = n-1;

	for ( int i = 1; i <= m; i++ ) {	
		scanf("%d", &x);
		c[0][i] = x;
		c[i][0] = x;
		t1 += x;
	}

	for ( int i = 1; i <= m; i++ ) {
		scanf("%d", &x);
		c[i+m][t] = x;
		c[t][i+m] = x;
		t2 += x;
	}

	for ( int i = 1; i <= m; i++ )
		for ( int j = m+1; j < n-1; j++ ) {
			c[i][j] = 100;
		}
                         
	h[s] = n;
	
	for (int i=0; i<n; ++i) {
		f[s][i] = c[s][i];
		f[i][s] = -f[s][i];
		e[i] = c[s][i];
	}

	int sz = 0;
	for (;;) {
		if (sz == 0)
			for (int i=0; i<n; ++i)
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
			for (int j=0; (j<n) && (e[i] > 0); ++j)
				if ((c[i][j]-f[i][j] > 0) && (h[i] == h[j]+1)) {
					pushed = true;
					int addf = min (c[i][j] - f[i][j], e[i]);
					f[i][j] += addf;
				    f[j][i] -= addf;
					e[i] -= addf;
					e[j] += addf;

					if (e[i] == 0)  
						--sz;
				}

			if (!pushed) {
				h[i] = INF;

				for (int j=0; j<n; ++j)
					if ((c[i][j] - f[i][j] > 0) && (h[j]+1 < h[i]))
						h[i] = h[j]+1;

				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}
	if (( t1 == t2 ) && (t1 == e[n-1])) {
		printf("YES\n");
		for ( int i = 1; i <= m; i++ ) {
			for ( int j = m+1; j < n-1; j++ )
				printf("%d ", f[i][j]);
			printf("\n");
		}
	} else {
		printf("NO\n");
	}
	//printf("%d\n", e[n-1]);



}