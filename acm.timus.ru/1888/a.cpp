#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 100

using namespace std;

int a[N][N], n, m, mdiff = 0, ans[N];
int dist[N];
bool b[N];

bool sample_bfs(int v) {
	bool bb[N];
	memset(bb,0,sizeof(b));
	bb[v] = true;
	b[v] = true;
	dist[v] = 50;
	
	int q[N], nq = 1, i = 0;
	q[0] = v;

	while ( i < nq ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( (a[q[i]][j] != 0 ) && !b[j] ) {
				q[nq] = j;
				nq++;
				b[j] = true;
				bb[j] = true;
				dist[j] = dist[q[i]] - 1;
			}
		}
		i++;
	}

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			if (( a[i][j] != 0) && (bb[i]) && (bb[j]) && (dist[i] == dist[j]))
				return false;
	
	return true;
}

bool bfs(int v) {
	memset(b,0,sizeof(b));
	b[v] = true;
	memset(dist,0,sizeof(dist));

	for ( int i = 1; i <= n; i++ )
		dist[i] = 50;
	dist[v] = 1;

	int q[N], nq = 1, i = 0;
	q[0] = v;

	while (i < nq) {
		for ( int j = 1; j <= n; j++ ) {
			if ( (a[q[i]][j] != 0) && (!b[j]) ) {
				q[nq] = j;
				nq++;
				b[j] = true;
				dist[j] = dist[q[i]] + 1;
			}
		}
		i++;
	} 
	

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			if (( a[i][j] != 0 ) && (dist[i] == dist[j]) && (b[i]) && (b[j]))
				return false;

	for ( int i = 1; i <= n; i++ )
		if ( !b[i] ) {
			
			for ( int j = i; j <= n; j++ )
				if (!b[j]) 
					if ( !sample_bfs(j) ) 
						return false;

			break;
		}

    int	diff = 0;
	for ( int i = 1; i <= n; i++ )
		if (dist[i] - 1 > diff ) 
			diff = dist[i] - 1;
	
	if ( diff > mdiff ) {
		mdiff = diff;
		for ( int i = 1; i <= n; i++ )
			ans[i] = dist[i];
	}

	return true;
}

int main() {
	scanf("%d%d", &m, &n);
	for ( int i = 0; i < m; i++ ) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}


	for ( int i = 1; i <= n; i++ ) {
		bfs(i);
		if (mdiff == 49 ) {
			break;
		}
	}

	if ( mdiff == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", mdiff);
		for ( int i = 1; i <= n; i++ )
			printf("%d ", ans[i]);
	}
	return 0;
}

