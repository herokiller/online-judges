#include <iostream>
#include <stdio.h>

using namespace std;

int n, a[100100];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &a[i]);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	int ans1 = 0, ans2 = 0;

	if ( x < y ) {
		for ( int i = 1; i <= (x+y)/2; i++ )
			ans1 += a[i];
		for ( int i = (x+y)/2 + 1; i <= n; i++ )
			ans2 += a[i];
	} else if ( x > y ) {
		for ( int i = 1; i < (x+y)/2 + (x+y)%2; i++ )
			ans2 += a[i];
		for ( int i = (x+y)/2 + (x+y)%2; i <= n; i++ )
			ans1 += a[i];
	} else {
		for ( int i = 1; i < x; i++ )
			ans1 += a[i];
		for ( int i = x+1; i <= n; i++ )
			ans2 += a[i];

		if ( ans2 > ans1 ) {
			int c = ans1;
			ans1 = ans2;
			ans2 = c;
		}
		ans1 += a[x];
			
	}

	printf("%d %d\n", ans1, ans2);
	return 0;
}
