#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int n, k;

	scanf("%d%d", &n, &k);
	int ans = n;
	for ( int i = 1; i <= k; i++ ) {
		int x;
		scanf("%d", &x);
		ans = ans+x-n;
		if ( ans <= 0 ) {
			ans = 0;
			break;
		}
	}

	printf("%d", ans);
	return 0;
}
