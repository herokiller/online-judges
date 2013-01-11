#include <iostream>
#include <stdio.h>

using namespace std;

int n, a[1050], d[30];

void mult(int x) {
	for ( int i = 1; i <= x; i++ )
		d[i] = i+n;
	
	bool ok = false;

	for ( int i = x; i >= 2; i-- ) {
		int p = i;
		for ( int j = x; j >= 1; j-- )
			for ( int k = 2; k <= p; k++ )
				if ((p%k == 0) && ( d[j]%k == 0 )) {
					d[j] /= k;
					p /= k;
					k--;
					continue;
				}
	}

	for ( int i = 1; i <= x; i++ ) {
		for ( int j = 1; j <= 1000; j++ )
			a[j] *= d[i];

		for ( int j = 1; j <= 1000; j++ ) {
			a[j+1] += a[j]/10;
			a[j] %= 10;
		}
	}

	return;
}
int main() {
	int x, y;
	scanf("%d%d%d", &n, &x, &y);
	
	a[1] = 1;
	mult(x);
	mult(y);

	for ( int i = 1000; i >= 1; i-- ) 
		if ( a[i] > 0 ) {
			for ( int j = i; j >= 1; j-- )
				printf("%d", a[j]);
			printf("\n");
			break;
		}

	return 0;
}

