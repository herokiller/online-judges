#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAXN 105

using namespace std;

int a[MAXN], d[MAXN][MAXN], n;
bool b[MAXN];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);

	sort(a+1, a+n+1);

	int k = 0;
	for ( int i = n; i >= 1; i-- ) {
		for ( int j = 1; j <= k; j++ )
			d[k+1][j] = d[k][j];

		for ( int j = 1; j <= k; j++ ) {
			int m = 0, mp = 0;
			bool ok = 0;
			if (!b[j]) {
				
				for ( int q = k-j+1; q >= 1; q-- )
					if ( d[j][q] > m ) {
						m = d[j][q];
						mp = q;
						ok = 1;
						
					}
			}		

			if (!ok)
				b[j] = 1;
			else {
				d[j][mp] = min(m-1, a[i]);
			}
				
		}
		k++;
		d[k][k] = a[i];

	}	

	for ( int i = 1; i <= n; i++ )
		if ( !b[i] ) {
			printf("%d\n", i);
			break;
		}
	return 0;
}
