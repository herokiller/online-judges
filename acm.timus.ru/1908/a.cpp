#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 100050

using namespace std;

struct edge {
	int v, next;
	char m;
};

edge a[N];
int head[N], d[N][2], n, m, ne, curv, t[N];
char s[N];


void dfs(int v) {

	int i = head[v], k = 0;

	while ( i > 0 ) {
		k++;
		dfs(a[i].v);
		i = a[i].next;
	}

	i = head[v];
	int sum = 0;
	while ( i > 0 ) {
		sum += d[a[i].v][0];	           	
		i = a[i].next;
	}


	if ( k == 0 ) {
		d[v][1] = 0;
		d[v][0] = 0;		
	} else {
		i = head[v];

		while ( i > 0 ) {
		    if ((sum - d[a[i].v][0] + d[a[i].v][1] < d[v][1]) || (d[v][1] == 0)) 
		    	d[v][0] = sum - d[a[i].v][0] + d[a[i].v][1];

			i = a[i].next;
		}
	}
}

int main() {

	scanf("%d\n", &m);

	n = 1, ne = 0, curv;	

	for ( int i = 1; i <= m; i++ ) {
		gets(s);
		int l = strlen(s);

		bool follow = true;
		bool found;

		curv = 1;

		for ( int j = 0; j < l; j++ ) {
			
			if ( follow ) {
				found = false;
				int k = head[curv];
		
				while ( k > 0 ) {
					if ( a[k].m == s[j] ) {
						curv = a[k].v;
						found = true;
						break;
					}

					k = a[k].next;
				}

				if ( !found )
					follow = false;
			}
			
			
			if ( !follow ) {
				n++;
				ne++;
				a[ne].v = n;
				a[ne].next = head[curv];
				head[curv] = ne;
				a[ne].m = s[j];
				curv = n;
			}
		}
	}

	/*
	for ( int i = 1; i <= n; i++ ) {
		int j = head[i];

		while ( j > 0 ) {
			cout << a[j].v << '-' << a[j].m << ", ";
			j = a[j].next;
		}
		cout << endl;
	}
	*/


	dfs(1);
	cout << d[1][0] << endl;
	return 0;
}
