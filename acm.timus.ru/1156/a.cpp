#include <iostream>
#include <stdio.h>

using namespace std;

bool b[200], a[200][200], ok;
int q[200], c[200], nq, k, n, m, step;

struct mass {
	bool v;
	int c, prev;
};

mass d[100][100];

void bfs(int v) {
	int k1 = 0, k2 = 0;

	int i = 0;
	nq = 1; q[1] = v;
	b[v] = 1;
	c[v] = k;
	k1++;

	while (i < nq ) {
		i++;
		for ( int j = 1; j <= n*2; j++ ) {
			if ((a[q[i]][j]) && (b[j]) && (c[j] == c[q[i]])) {				
				ok = false;
				return;			
			}

			if (( !b[j] ) && (a[q[i]][j])) {
			 	nq++;
			 	q[nq] = j;
			 	b[j] = 1;
			 	int t = c[q[i]];
			 	if ( t%2 == 1 ) {
			 		t++;
			 		k2++;
			 	} else { 
			 		t--;
			 		k1++;
			 	}

			 	c[j] = t;
			}
		}						
	}	

	for ( int i = n; i >= 0; i-- )
		if ( d[step][i].v ) {
			d[step+1][i + k1].v = 1;
			d[step+1][i + k1].c = k;
			d[step+1][i + k1].prev = i;

			d[step+1][i + k2].v = 1;
			d[step+1][i + k2].c = k+1;
			d[step+1][i + k2].prev = i;		
		}

   	step++;
}


int main() {
	scanf("%d%d", &n, &m);
	ok = true;

	
	for ( int i = 1; i <= m; i++ ) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}

	k = 1; step = 1;
	d[1][0].v = 1;
	for ( int i = 1; i <= n*2; i++ ) {
		if (!b[i]) {
			bfs(i);
			if (!ok) {
				printf("IMPOSSIBLE\n");
				return 0;
			}
			k += 2;
		}
	}


	int ans1[200], ans2[200], nans1 = 0, nans2 = 0;

	if ( d[step][n].v ) {
		int i = n;
		while (i > 0) {
			int k = d[step][i].c;

			for (int j = 1; j <= n*2; j++ )
				if ( c[j] == k ) {
					nans1++;
					ans1[nans1] = j;
					c[j] = 0;
				}	

			i = d[step][i].prev;
			step--;
		}

		for (int j = 1; j <= n*2; j++ )
			if ( c[j] != 0 ) {
				nans2++;
				ans2[nans2] = j;
			}	


		for ( int i = 1; i <= nans1; i++ )
			printf("%d ", ans1[i]);
		printf("\n");
		for ( int i = 1; i <= nans2; i++ )
			printf("%d ", ans2[i]);
		printf("\n");	
	} else {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	return 0;
}
