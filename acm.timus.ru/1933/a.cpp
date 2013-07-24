#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int a[500][500], n, m;

int main() {
	scanf("%d", &n);

	m = 2*n+1;
	
	for ( int i = 1; i <= m; i++ )
		for ( int j = 1; j <= m; j++ ) {
			if ( i == j ) 
				continue;
			if ( i + j <= m + 1 ) {
				a[i][j] = abs(i+j)-2;
			} else {
				if ( abs(i+j) == m + 2 )
					a[i][j] = m;
				else 
					a[i][j] = abs(i+j) - m - 2;
			}
		}


	for ( int i = 1; i <= m; i++ ) {
		for ( int j = 1; j <= m; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}
		
	return 0;
}
