#include <iostream>
#include <stdio.h>

typedef long long ll;

using namespace std;

struct edge {
	int v, next, w;
	char t;
};

struct mass {
	ll l, p;
};

char s[1000];
mass d[10100];
edge e[10100];
int head[10100], n, m;

int main() {
	scanf("%d %d\n", &n, &m);
	for ( int i = 1; i <= m; i++ ) {
		int x;
		scanf("%d%d%d ", &x, &e[i].v, &e[i].w);
		gets(s);
		e[i].t = s[0];
		e[i].next = head[x];
		head[x] = i;
	}
	
	for ( int i = 1; i <= n; i++ ) {
		d[i].l = -1;
		d[i].p = -1;
	}

	d[1].l = 0;
	d[1].p = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = head[i]; j > 0; j = e[j].next ) {
			ll target;
			if (( e[j].t == 'L' ) || (e[j].t == 'C')) {
				target = d[e[j].v].l;
				if (( d[i].l != -1 ) && ((target == -1) || (d[i].l + (ll)e[j].w < target)))
					d[e[j].v].l = d[i].l + (ll)e[j].w;
			} 
			if (( e[j].t == 'P' ) || (e[j].t == 'C')) {
				target = d[e[j].v].p;
				if (( d[i].p != -1 ) && ((target == -1) || (d[i].p + (ll)e[j].w < target )))
					d[e[j].v].p = d[i].p + (ll)e[j].w;
			}

			if ( e[j].t == 'P' ) {
				target = d[e[j].v].p;
				if (( d[i].l != -1 ) && ((target == -1 ) || (d[i].l + (ll)e[j].w < target )))
					d[e[j].v].p = d[i].l + (ll)e[j].w;
			}
			
		}
	}

	ll ans = d[n].l;
	if ( ans == -1 ) 
		ans = d[n].p;
	else if (( d[n].p != -1 ) && (d[n].p < ans))
		ans = d[n].p;

	if ( ans == -1 ) {
		printf("Offline\n");
	} else {
		printf("Online\n");
		cout << ans << endl;
	}
	return 0;
}

