#include <iostream>
#include <stdio.h>

using namespace std;

const long long M = 1000000007;

int n;
long long ans, d[2][5000], s[2][5000];

int main() {
	scanf("%d", &n);
	
	for ( int i = 1; i <= n; i++ ) {
		
		for ( int j = 1; j <= n; j++ ) {
			if ( i == 1 ) 
				d[1][j] = 1;
			else if (i > j) { 
				d[1][j] = (d[0][j]*(long long)n)%M;
			} else {
				d[1][j] = (d[0][j]*(long long)j)%M;
				if ( i < j ) {
					d[1][j] = (d[1][j] + s[0][j-1])%M;
					d[1][j] = d[1][j] - s[0][i-1];
					if ( d[1][j] < 0 ) 
						d[1][j] += M;
				}
			}

			s[1][j] = (s[1][j-1] + d[1][j])%M;
		}

		for ( int j = 1; j <= n; j++ ) {
			d[0][j] = d[1][j];
			s[0][j] = s[1][j];
		}
	}

	cout << d[1][n] << endl;
	return 0;
}
