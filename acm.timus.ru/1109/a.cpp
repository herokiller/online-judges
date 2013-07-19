#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m, k, mt[1100];
bool b[1100], a[1100][1100];
 
bool rec(int v) {
	if (b[v])  
		return false;

	b[v] = true;
	for (int i=1; i <= m; i++)
		if ( a[v][i] )
			if (mt[i] == 0 || rec(mt[i])) {
				mt[i] = v;
				return true;
			}

	return false;
}
 
int main() {
	scanf("%d%d%d", &n, &m, &k);

	for ( int i = 1; i <= k; i++ ) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}

	for (int i = 1; i <= n; i++ ) {
		memset(b, 0, sizeof(b));
		rec(i);
	}
 
    int ans = n + m;

	for (int i = 1; i <= m; i++ )
		if ( mt[i] > 0 )
			ans--;

	printf("%d\n", ans);
}