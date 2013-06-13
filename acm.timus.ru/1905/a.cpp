#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100010

using namespace std;

struct edge {
	int x, v, t1, t2, next, prev, num;
};

struct mass {
	int v, t, prev, num;
};

bool comp(edge X, edge Y) {
	return X.t1 < Y.t1;
}

mass q[N];
int head[N], mt[N], nq, n, m;
edge a[N];

void restore(int p) {
	int ans[N], nans = 0;

	while (q[p].num > 0) {
		nans++;
		ans[nans] = q[p].num;
		p = q[p].prev;
	}

	printf("%d\n", nans);
	for ( int i = nans; i >= 1; i-- )
		printf("%d ", ans[i]);
}

int main() {
	
	scanf("%d%d", &n, &m);

	for ( int i = 1; i <= m; i++ ) {
		scanf("%d%d%d%d", &a[i].x, &a[i].v, &a[i].t1, &a[i].t2);
		a[i].num = i;
	}	

	sort(a+1, a+m+1, comp);

	for ( int i = 1; i <= m; i++ ) {

//		scanf("%d%d%d%d", &x, &a[i].v, &a[i].t1, &a[i].t2);
		a[i].next = head[a[i].x];
		a[head[a[i].x]].prev = i;
	
		head[a[i].x] = i;
	}
	
	int v1, v2, t1, t2;
	scanf("%d%d%d%d", &v1, &v2, &t1, &t2);

	nq = 1;
	q[1].v = v1;
	q[1].t = t1;
	for ( int i = 1; i <= n; i++ )
		mt[i] = -1;

	mt[v1] = t1;

	int i = 0;
	while (i < nq) {
		i++;

		if ((q[i].v == v2 ) && (q[i].t <= t2)) {
			restore(i);
			return 0;
		}

		int j = head[q[i].v];
		while ( j > 0 ) {
			if ( q[i].t > a[j].t1 ) 
				break;

		    if ((q[i].t <= a[j].t1) && ((a[j].t2 < mt[a[j].v]) || (mt[a[j].v] == -1))) {
		    	nq++;
		    	q[nq].v = a[j].v;
		    	q[nq].t = a[j].t2;
		    	q[nq].prev = i;
				q[nq].num = a[j].num;

		    	mt[a[j].v] = a[j].t2;

		    	a[a[j].prev].next = a[j].next;
		    	//remove?

		    }
			j = a[j].next;
		}
	}

	printf("Impossible");
	return 0;
}
