#include <iostream>
#include <stdio.h>

#define N 101000

using namespace std;

struct edge {
	int v, next;
};

edge e[2*N];
int n, head[N], ans1, ans2, c[N], cx, l[N];
bool b[N], in[N];

void dfs(int v, int level) {
	
	b[v] = 1;
	l[v] = level;
	c[v] = cx;
	ans2++;

	for ( int i = head[v]; i > 0; i = e[i].next ) {
		int to = e[i].v;
		if ((b[to])&&(c[to] == c[v]))
			ans2 = ans2 - l[v] + l[to];

		if (!b[to])
			dfs(to, level+1);
	}

	return;	
}

int main() {
	scanf("%d", &n);
	int k = 0;
	for ( int i = 1; i <= n; i++ ) {
		int x;
		scanf("%d", &x);
		if ( i != x ) {
			k++;
			e[k].next = head[i];
			e[k].v = x;
			head[i] = k;
			in[x] = 1;			
		}
	}	
	
	for ( int i = 1; i <= n; i++ )
		if (!in[i]) {
			ans1++;
			cx++;
			dfs(i, 1);
		}

	for ( int i = 1; i <= n; i++ )
		if (!b[i]) {
			ans1++;
			cx++;
			dfs(i, 1);
		}

	printf("%d %d\n", ans1, ans2);
	return 0;
}
