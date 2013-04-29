#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#define MAXN 60

using namespace std;

struct point {
	int i, j;
};

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
int turn, nc[2], n, m, a[MAXN][MAXN];
point c[2][MAXN*MAXN];
char s[10000], ch;
bool b[MAXN][MAXN];

void bfs(int x, int y) {
	int val = a[x][y];
	nc[turn]++;
	c[turn][nc[turn]].i = x;
	c[turn][nc[turn]].j = y;

	b[x][y] = 1;
	a[x][y] = turn + 100;

	point q[400];
	q[1].i = x;
	q[1].j = y;
	int i = 0, nq = 1;

	while ( i < nq ) {
		i++;
		for ( int j = 0; j < 4; j++ ) {
			int k1 = q[i].i + di[j];
			int k2 = q[i].j + dj[j];

			if ((!b[k1][k2]) && (a[k1][k2] == val)) {
				nc[turn]++;
				c[turn][nc[turn]].i = k1;
				c[turn][nc[turn]].j = k2;
				nq++;
				q[nq].i = k1;
				q[nq].j = k2;
				b[k1][k2] = 1;
				a[k1][k2] = turn + 100;
			}
		}
	}

}

int main() {
	scanf("%d%d\n", &n, &m);

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			ch = getchar();
			a[i][j] = int(ch - '0');
		}
		gets(s);			
	}					

	for ( int i = 0; i <= n+1; i++ ) {
		b[i][0] = 1;
		b[i][m+1] = 1;
	}
	for ( int j = 0; j <= m+1; j++ ) {
		b[0][j] = 1;
		b[n+1][j] = 1;
	}

	turn = 0;
	bfs(n, 1);

	turn = (turn + 1)%2;
	bfs(1, m);

	turn = (turn + 1)%2;

	int k;	
	scanf("%d", &k);	

	for ( int i = 1; i <= k; i++ ) {
		int t;
		scanf("%d", &t);

		for ( int j = 1; j <= nc[turn]; j++ )
			for ( int q = 0; q < 4; q++ ) {
				int k1 = c[turn][j].i + di[q];
				int k2 = c[turn][j].j + dj[q];

				if ((!b[k1][k2])  && (a[k1][k2] == t))
					bfs(k1, k2);
		  	}

		turn = (turn+1)%2;
	}
	
	int ans1 = 0, ans2 = 0;

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ ) {
			if ( a[i][j] == 100 ) 
				ans1++;
		   	if ( a[i][j] == 101 ) 
		   		ans2++;
		}

	printf("%d\n%d\n", ans1, ans2);

	return 0;
}
