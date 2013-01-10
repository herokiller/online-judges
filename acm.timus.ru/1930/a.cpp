#include <stdio.h>
#include <iostream>

#define N 10010
#define M 100010

using namespace std;

int n, m;

struct edge {
	int v, val, next;
};

edge e[2*M];
int head[N];
int d[N][2];

void addEdge(int v1, int v2, int val, int p) {
	e[p].v = v2;
	e[p].val = val;
	e[p].next = head[v1];
	head[v1] = p;
}

int bfs(int v1, int v2) {

	for ( int i = 1; i <= n; i++ ) {
		d[i][0] = -1;
		d[i][1] = -1;
	}
	
	struct vertex {
		int v, val;
	};

	vertex q[N*10];
	q[0].v = v1;
	q[0].val = 0;
	q[1].v = v1;
	q[1].val = 1;
	d[v1][0] = 0;
	d[v1][1] = 0;

	int qn = 2, i = 0;

	while ( i < qn ) {

		int j = head[q[i].v];

		while (j > 0) {
			int k = 0;
			
			if ( e[j].val == q[i].val)
				k = 0;
			else 
				k = 1;

			if ((d[q[i].v][q[i].val] + k < d[e[j].v][e[j].val]) || (d[e[j].v][e[j].val] == -1))  {
				
				q[qn].v = e[j].v;
				q[qn].val = e[j].val;
				d[e[j].v][e[j].val] = d[q[i].v][q[i].val] + k;
				qn++;
			}

			j = e[j].next;
		}

		i++;
	}
	
	int ans = d[v2][0];

	if ((ans == -1) || ((d[v2][1] < ans) && (d[v2][1] != -1))) 
		ans = d[v2][1];
	
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);

	for ( int i = 0; i < m; i++ ) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		addEdge(v1, v2, 0, i*2+1);
		addEdge(v2, v1, 1, i*2+2);
	}
	
	int v1, v2;
	scanf("%d%d", &v1, &v2);

	int ans = bfs(v1, v2);
	printf("%d\n", ans);

	return 0;
}

