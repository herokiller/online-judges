#include <iostream>
#include <stdio.h>

typedef long long ll;

#define N 300010

using namespace std;

const long long M = 1000000007;
struct edge {
	int v, next;
};

edge e[N*2];
int t1[N*4], t2[N*4], h[N], c[N], rb[N], l[N], n, color;

void add(int* t, int v, int tl, int tr, int l, int r, int k) {
	if ( l > r )
		return;
	if ( l == tl && r == tr ) {
		t[v] = (t[v]+k)%M;
	} else {
		int tm = (tl + tr) / 2;

		add(t, v*2, tl, tm, l, min(r, tm), k);
		add(t, v*2+1, tm+1, tr, max(l, tm+1), r, k);
	}
}


int get(int* t, int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return (t[v] + get(t, v*2, tl, tm, pos))%M;
	else
		return (t[v] + get(t, v*2+1, tm+1, tr, pos))%M;
}


void dfs(int v, int lvl) {
	l[v] = lvl;
	c[v] = color;

	for ( int j = h[v]; j > 0; j = e[j].next ) {
		int vto = e[j].v;
		if ( c[vto] == 0 ) {
			color++;
			dfs(vto, lvl+1);
		}
	}

	rb[v] = color;
}

int main() {
	scanf("%d", &n);
	int m = 0;
	for ( int i = 2; i <= n; i++ ) {
		int x;
		scanf("%d", &x);		
		m++;
		e[m].v = i;
		e[m].next = h[x];
		h[x] = m;
		m++;
		e[m].v = x;
		e[m].next = h[i];
		h[i] = m;
	}
	
	color = 1;
	dfs(1, 1);

   	int nq;
	scanf("%d", &nq);
	for ( int q = 1; q <= nq; q++ ) {
		int t, v, x, k;
		scanf("%d", &t);
		if ( t == 1 ) {
			scanf("%d%d%d", &v, &x, &k);

			add(t1, 1, 1, n, c[v], rb[v], ((ll)x+(ll)l[v]*(ll)k)%M);
			add(t2, 1, 1, n, c[v], rb[v], k);
		} else {
			scanf("%d", &v);
			int k1 = get(t1, 1, 1, n, c[v]);
			int k2 = get(t2, 1, 1, n, c[v]);
			long long ans = ((ll)k1 - (ll)k2*(ll)l[v])%M;
			if ( ans < 0 ) 
				ans += M;

			printf("%I64d\n", ans);
			
		}
	}	

	return 0;
}
