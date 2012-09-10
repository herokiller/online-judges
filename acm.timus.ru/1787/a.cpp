#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int n, k, ans = 0, x;
	scanf("%d%d", &k, &n);
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &x);
		ans += x;
		ans -= k;
		if ( ans < 0 ) ans = 0;
	}

	printf("%d\n", ans);
	return 0;
}

