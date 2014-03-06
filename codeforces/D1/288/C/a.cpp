#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[200], b[200], ans1, ans2, n, t;

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &t);
		for ( int j = 1; j <= t; j++ ) {
			int x;
			scanf("%d", &x);
			if ( j <= t/2 )
				ans1 += x;
			else if (( j == t/2 + 1 ) && (t%2 == 1)) 
				a[i] = x;
			else
				ans2 += x;
		}	
	}

	sort(a+1, a+n+1);
	for ( int i = n; i >= 1; i-- )
		if ( (n-i+1)%2 == 1 ) 
			ans1 += a[i];
		else 
			ans2 += a[i];

	printf("%d %d\n", ans1, ans2);
	return 0;
}
