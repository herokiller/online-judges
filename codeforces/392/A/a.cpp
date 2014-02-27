#include <iostream>
#include <stdio.h>

using namespace std;

long long n;

bool check(long long x, long long y) {
	return (x*x + y*y <= n*n);
}

int main() {
	scanf("%I64d", &n);

	long long x = 0, y = n;
	int k = 0;

	while ((x <= n) && (y >= 0)) {
		k++;

		if (check(x+1, y)) {
			x++;
		} else if ( check(x+1, y-1)) {	
			x++;
			y--;
		} else if ( check(x, y-1)) {
			y--;
		} else {
		 	break;
		}
	}
	
	int ans = 4*k - 4;
	if (n == 0)
		ans = 1;
	printf("%d\n", ans);

	return 0;
}
