#include <iostream>
#include <stdio.h>

using namespace std;

bool p[100];
int x, n, k, m;
bool a[2010][2010];

int main() {
	scanf("%d", &x);

	int k = 0;
	while (x > 0 ) {
		if ( x%2 == 1 ) {
			p[k] = 1;
			m = k;
	   	}

		x /= 2;
		k++;
	}	

	n = 2;
	k = m;

	while ( m >= 0 ) {
		if ( p[m] ) {
			if ((m > 0) && (p[m-1]) && (m < k)) {
			    for ( int i = 1; i <= m+1; i++ ) {
					n++;
					if (i == 1) {
						a[1][n] = 1;
						n++;
						a[1][n] = 1;
					} else if (i == m+1) {
						a[n-1][n] = 1;
					    a[n-2][n] = 1;
					    n++;
					    a[n-2][n] = 1;
//					    a[n-3][n] = 1;									
					} else {
					    a[n-1][n] = 1;
					    a[n-2][n] = 1;
					    n++;
					    a[n-2][n] = 1;
					    a[n-3][n] = 1;
					}
				}


				for ( int i = m+2; i <= k; i++ ) {
					n++;
					if ( i == m+2 ) {
						if ( m == 0 ) {
							a[1][n] = 1;
						} else {
							a[n-1][n] = 1;
							a[n-2][n] = 1;
						}	
					} else {
					    a[n-1][n] = 1;
					}
				}
					
				if ( m+1 == k ) {
					if ( k == 0 )
						a[1][2] = 1;
					else {
						a[n][2] = 1;
						a[n-1][2] = 1;				
					}
				} else {
					a[n][2] = 1;
				}
				m--;
			} else {

				for ( int i = 1; i <= m; i++ ) {
					n++;
					if (i == 1) {
						a[1][n] = 1;
						n++;
						a[1][n] = 1;
					} else {
					    a[n-1][n] = 1;
					    a[n-2][n] = 1;
					    n++;
					    a[n-2][n] = 1;
					    a[n-3][n] = 1;
					}
				}

				for ( int i = m+1; i <= k; i++ ) {
					n++;
					if ( i == m+1 ) {
						if ( m == 0 ) {
							a[1][n] = 1;
						} else {
							a[n-1][n] = 1;
							a[n-2][n] = 1;
						}	
					} else {
					    a[n-1][n] = 1;
					}
				}
					
				if ( m == k ) {
					if ( k == 0 )
						a[1][2] = 1;
					else {
						a[n][2] = 1;
						a[n-1][2] = 1;				
					}
				} else {
					a[n][2] = 1;
				}
			}	

		}
		m--;
	}


	printf("%d\n", n);
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			if (a[i][j])
				a[j][i] = 1;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) 
			if (a[i][j])
			    printf("Y");
			else
				printf("N");
		printf("\n");
	}

	return 0;
}
