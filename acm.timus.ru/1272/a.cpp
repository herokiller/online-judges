#include <iostream>
#include <stdio.h>

using namespace std;

int head[10100], q[10100];
bool b[10100];

struct mass {
	int val, next;
};
mass e[40000];
int ne, n, m, k;

void bfs(int v) {
	int i = 0, nq = 1;	
	q[1] = v;

	while ( i < nq ) {
		i++;
		int x = head[q[i]];
		while ( x > 0 ) {
			if ( !b[e[x].val] ) {
				nq++;
				q[nq] = e[x].val;
				b[e[x].val] = true;
			}
			x = e[x].next;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	for ( int i = 1; i <= m; i++ ) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		ne++;
		e[ne].val = v2;
		e[ne].next = head[v1];
		head[v1] = ne;

		ne++;
		e[ne].val = v1;
		e[ne].next = head[v2];
		head[v2] = ne;		
	}

	int ans = 0;
	for ( int i = 1; i <= n; i++ )
		if ( !b[i] ) {
			ans++;
			bfs(i);
		}

	printf("%d\n", ans-1);
	return 0;
}
