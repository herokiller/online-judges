#include <iostream>
#include <stdio.h>

#define MAXN 500

using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], d[MAXN][MAXN][MAXN], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n-1; i++ )
		for ( int j = i+1; j <= n; j++ )
			scanf("%d", &a[i][j]);



	for ( int i = 1; i <= n-1; i++ ) {
		int cur = 0;
		for ( int j = n; j >= i+1; j-- ) {
			cur += a[i][j];
			b[i][j] = cur;
		}
	}


	for ( int j = 2; j <= n; j++ ) {
		int cur = 0;
		for ( int i = j-1; i >= 1; i-- ) {
			cur += b[i][j];
			c[i][j] = cur;
		}
   	}

   	for ( int i = 1; i <= n; i++ )
   		for ( int j = i+1; j <= n; j++ )
   			cout << i << " -> " << j << ": " << c[i][j] << endl;


				
	for ( int i = 2; i <= n; i++ )
		for ( int j = 1; j <= i; j++ )
			for ( int k = 1; k <= i; k++ ) {
				d[i][j][k] = d[i-1][j][k];
				for ( int q = 1; q <= i-1; q++ ) {
					int x = d[i-1][j-1][q] + c[q][i];
					if ( x > d[i][j][k] )
						d[i][j][k] = q;
				}
					
			}

	for ( int i = 2; i <= n; i++ )
		cout << d[n][m][i] << ' ';

	return 0;
}
