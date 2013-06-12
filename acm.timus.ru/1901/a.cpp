#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXN 100100

using namespace std;


int a[MAXN], n, k;

int main() {
    scanf("%d%d", &n, &k);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);


	sort(a+1, a+n+1);

	for ( int i = 1; i <= n; i++ ) {
		int x1 = i, x2 = n;
		while ((a[x1] + a[x2] > k) && (x1 < x2)) {
			x1++;
			x2--;
		}

		if (x2 <= x1) {
			int ans = ((i-1)/2) + (n-i+1);
			printf("%d\n", ans);
			x1 = i, x2 = n;
			while (x1 < x2) {
				printf("%d %d ", a[x1], a[x2]);
				x1++;
				x2--;
			}
			if ( x1 == x2 )
				printf("%d ", a[x1]);

			for ( int j = 1; j <= i-1; j++ )
				printf("%d ", a[j]);

			return 0;
		}
	}

	return 0;
}
