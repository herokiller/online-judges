#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

const long long M = 1000000007;

bool b[1000];
int a[1000], n, k[50100];
long long c[20000][510];

int main() {
	int mk = 0;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &a[i]);

		for ( int j = 2; j <= 40000; j++ ) 
			while (a[i]%j == 0 ) {
				a[i] /= j;
				k[j]++;
				if (k[j] > mk )
					mk = k[j];
			}	
	}	

	c[0][0] = 1;
	for ( int i = 1; i <= n+mk-1 + 505; i++ ) {
		c[i][0] = 1;
		for ( int j = 1; j <= n-1; j++ )
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%M;
	}


	long long ans = 1;
	for ( int i = 2; i <= 50000; i++ )
		if ( k[i] > 0 ) 
			ans = (ans*c[n+k[i]-1][n-1])%M;

	for ( int i = 1; i <= n; i++ )
		if (( a[i] > 1 ) && (!b[i])) {
			b[i] = 1;
			mk = 1;
			for ( int j = i+1; j <= n; j++ )
				if ( a[j] == a[i] ) {
					mk++;
					b[j] = 1;
				}	
			ans = (ans*c[n+mk-1][n-1])%M;
		}

	printf("%I64d\n", ans);
	return 0;
}
