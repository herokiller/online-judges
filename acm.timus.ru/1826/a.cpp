#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int d[1010], a[1010], n;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);

	sort(a+1, a+n+1, compare);

	int ans = 0;
	for ( int i = 1; i <= n-2; i++ ) {
		d[i] = d[i-1] + a[i] + a[n];
		if ( i-2 >= 0 ) {
			if ( d[i-2] + a[i-1] + a[n] + 2*a[n-1] < d[i] )
				d[i] = d[i-2] + a[i-1] + a[n] + 2*a[n-1];
		}
	}

	ans = d[n-2] + a[n-1];

	printf("%d\n", ans);

	return 0;
}

