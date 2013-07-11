#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, x[100100], y[100100];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
		scanf("%d%d", &x[i], &y[i]);

	long long ans = 0;
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);

	for ( int i = 1; i < n; i++ ) {
		ans += (long long)(x[i+1] - x[i])*(long long)i*(long long)(n-i);
		ans += (long long)(y[i+1] - y[i])*(long long)i*(long long)(n-i);
	}
	ans *= 2;

	ans /= (long long)n*(long long)(n-1);
	cout << ans << endl;
	return 0;
}

