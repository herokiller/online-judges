#include <iostream>
#include <stdio.h>

using namespace std;

int a[100100], l, n, k, k1, k2, k3, k4;

int main() {
	scanf("%d%d", &l, &n);
	for ( int i = 0; i < n; i++ )
		scanf("%d", &a[i]);

	int ans = a[0] + l - a[n-1];

	for ( int i = 1; i < n; i++ ) {
		k1 = k2 = k3 = k4 = 0;
		if ( a[0] > a[i-1] - a[0] ) 
			k1 = min(a[0] - a[i-1] + a[0], a[i] - a[i-1]);

		if ( a[i] - a[i-1] > a[i-1] )
			k2 = a[i] - a[i-1] - a[i-1];

		if ( l - a[n-1] > a[n-1] - a[i] ) 
			k3 = min(l - a[n-1] - a[n-1] + a[i], a[i] - a[i-1]);

		if ( a[i] - a[i-1] > l - a[i] ) 
			k4 = a[i] - a[i-1] - l + a[i];

		k = max(k1, k4) + max(k2, k3);
		k = min(k, a[i] - a[i-1]);

		ans += k;
	}

	printf("%d\n", ans);
	return 0;
}

