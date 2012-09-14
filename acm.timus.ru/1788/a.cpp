#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool comp(int x, int y) {
	return x > y;
}

int a[200], b[200], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for ( int i = 0; i < n; i++ )
		scanf("%d", &a[i]);
	
	for ( int j = 0; j < m; j++ )
		scanf("%d", &b[j]);

	sort(a, a+n, comp);
	sort(b, b+m, comp);

	int ans = -1;

	for ( int j = 0; j <= n; j++ ) {
		int tans = 0;
		int k = j;
		for ( int i = j; i < m; i++ )
			tans += b[i]*k;

		for ( int i = min(m,j); i < n; i++ )
			tans += a[i];

		if ((tans < ans) || (ans == -1)) 
			ans = tans;
	}
		
	printf("%d\n", ans);
	return 0;
}

