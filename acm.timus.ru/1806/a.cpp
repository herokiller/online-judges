#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 50010

using namespace std;

struct edge {
	int v, w, next;
};

struct mpa {
	int d, prev;
};

struct vertex {
	long long val;
	int num;
};

struct ve {
	int d, v;
};
//heap
bool b[N];
ve h[N*200]; int hn;
int dp[N];
mpa d[N];
edge e[N*200];
int cost[10], n, head[N], m, t[N], nt;
vertex v[N];

int find(long long vx) {
	int p1 = 1, p2 = n, pm;

	while ( p1 <= p2 ) {
		pm = (p1 + p2)/2;
		if ( v[pm].val > vx )
			p2 = pm-1;
		else if ( v[pm].val < vx )
			p1 = pm+1;
		else
			return pm;
	}

	return 0;
}

void add(int v1, int v2) {
	long long t = 1000000000;
	int k = 0;
	while (((v[v1].val/t)%10) == ((v[v2].val/t)%10)) {
		k++;
		t /= 10;
	}

	m++;
	e[m].v = v2;
	e[m].next = head[v1];
	e[m].w = cost[k];
	head[v1] = m;

	m++;
	e[m].v = v1;
	e[m].next = head[v2];
	e[m].w = cost[k];
	head[v2] = m;
}

bool comp(vertex a, vertex b) {
	return a.val < b.val;
}

void hup(int p) {
	int v = h[p].v;

	dp[v] = 1;
	while ( p > 1 ) {
		if ( h[p].d < h[p/2].d ) {
			dp[h[p/2].v] = p;
			int c = h[p].v;
			h[p].v = h[p/2].v;
			h[p/2].v = c;

			c = h[p].d;
			h[p].d = h[p/2].d;
			h[p/2].d = c;

		
			/*
			ve c = h[p];
			h[p] = h[p/2];
			h[p/2] = c;
			*/
			p /= 2;
			
		} else {
			dp[v] = p;
			break;
		}
	}
	return;
}

void hdown() {
	int p = 1;
	int v = h[p].v;
	//dp[v] = hn;
	while (p <= hn) {
		if ((p*2 <= hn) && (( h[p*2].d <= h[p*2+1].d ) || (p*2 == hn)) && ( h[p*2].d < h[p].d)) {
			dp[h[p*2].v] = p;
			int c = h[p].v;
			h[p].v = h[p*2].v;
			h[p*2].v = c;
			c = h[p].d;
			h[p].d = h[p*2].d;
			h[p*2].d = c;
			
			/*
			ve c = h[p];
			h[p] = h[p*2];
			h[p*2] = c;
			*/
			p = p*2;
		} else if ((p*2+1 <= hn) && (h[p*2+1].d <= h[p*2].d) && (h[p*2+1].d < h[p].d)){
			dp[h[p*2+1].v] = p;
			int c = h[p].v;
			h[p].v = h[p*2+1].v;
			h[p*2+1].v = c;
			c = h[p].d;
			h[p].d = h[p*2+1].d;
			h[p*2+1].d = c;
			/*
			ve c = h[p];
			h[p] = h[p*2+1];
			h[p*2+1] = c;
			*/
			p = p*2 + 1;
		} else {
			dp[v] = p;
			break;
		}

	}

	return;
}

int main() {
	scanf("%d", &n);
	for ( int i = 0; i <= 9; i++ )
		scanf("%d", &cost[i]);

	for ( int i = 1; i <= n; i++ ) {
		scanf("%lld", &v[i].val);
		v[i].num = i;
	}

	sort(v+1, v+n+1, comp);


	for ( int i = 1; i <= n; i++ ) {
		long long base = 1;
		for ( int j = 0; j <= 9; j++ ) {
			
			long long digit = (v[i].val/base)%10;
			
			long long base2 = 1;

			for ( int k = 0; k <= 9; k++ ) {
				long long vx;
				if ( k != digit ) {
					
					vx = v[i].val - base*digit + base*k;

					int p = find(vx);
					if ( p > 0 )
						add(p, i);

				}
		
				long long digit2 = (v[i].val/base2)%10;
				if (( k > j ) && (digit != digit2)) {
					vx = v[i].val - base*digit + base*digit2 - base2*digit2 + base2*digit ;

					int p = find(vx);
					if (p > 0) 
						add(p, i);

				}

				base2 *= 10;
			}

			base *= 10;
		}

	}

	for ( int i = 1; i <= n; i++ ) {
		d[i].d = 1000000000;
		if ( v[i].num == 1 ) {
			h[1].v = i;
			h[1].d = 0;
			d[i].d = 0;
			dp[i] = 1;
		}
	}

	hn = 1;
	for ( int k = 1; k <= n; k++ ) {
		int v = h[1].v;

		if (( v > 0 ) && (hn >= 1)) {
			int j = head[v];
			while ( j > 0 ) {
				if ( d[v].d + e[j].w < d[e[j].v].d ) {
					d[e[j].v].d = d[v].d + e[j].w;
					d[e[j].v].prev = v;
					if (dp[e[j].v] == 0 ) {
						hn++;
						h[hn].v = e[j].v;
						h[hn].d = d[e[j].v].d;
						hup(hn);
					} else {
						h[dp[e[j].v]].d = d[e[j].v].d;
						hup(dp[e[j].v]);
					}
					/*
					if ( h[dp[e[j].v]].v != e[j].v ) {
						for ( int qq = 1; qq <= 1000000000; qq++ )
							cout << "asdfasdf";
						return 0;
					}
					*/
				}
				j = e[j].next;
			}
			h[1].v = h[hn].v;
			h[1].d = h[hn].d;
			/*
			h[1] = h[hn];
			*/
			hn--;
			hdown();
		} else 
			break;
	}


	/*
	for ( int k = 1; k <= n; k++ ) {
		int m = 1000000000, mp = 0;
		for ( int i = 1; i <= n; i++ )
			if (( d[i].d < m ) && (!b[i])) {
				m = d[i].d;
				mp = i;
			}

		if ( mp > 0 ) {
			int j = head[mp];
			while ( j > 0 ) {
				if (d[mp].d + e[j].w < d[e[j].v].d) {
					d[e[j].v].d = d[mp].d + e[j].w;
					d[e[j].v].prev = mp;
				}
				j = e[j].next;
			}
			b[mp] = true;
		} else 
			break;
	}
	*/	

	int p = 0;
	for ( int i = 1; i <= n; i++ )
		if ( v[i].num == n ) {
			p = i;
			break;
		}

	int ans = -1;
	nt = 0;
	if ( d[p].d != 1000000000 ) {
		ans = d[p].d;
		int j = p;
		while (j > 0 ) {
			nt++;
			t[nt] = v[j].num;
			j = d[j].prev;
		}
	}

	printf("%d\n", ans);
	if ( ans != -1 ) {
		printf("%d\n", nt);
		for ( int i = nt; i >= 1; i-- )
			printf("%d ", t[i]);
	}
	return 0;
}

