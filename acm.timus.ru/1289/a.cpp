#include <iostream>
#include <stdio.h>

using namespace std;

int d[2][10], ans, n;

int main() {
	scanf("%d", &n);
	n /= 2;

	if ( n == 1 ) {
		printf("10\n");
		return 0;
	}
	for ( int i = 1; i <= n-1; i++ )
		printf("1");
	printf("0");
	for ( int i = 1; i <= n-2; i++ )
		printf("8");
	printf("90\n");
	

	/*
	d[0][0] = 1;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j <= 9; j++ )
			for ( int k = 0; k <= 9; k++ ) {				
				int x = (k+j)/10 + (k+j)%10;						
				d[1][x] += d[0][j];
			}

		for ( int j = 0; j <= 9; j++ ) {
			d[0][j] = d[1][j];
			d[1][j] = 0;
		}
	}

	for ( int i = 0; i <= 9; i++ )
		ans += d[0][i]*d[0][i];

         
	for ( int i = 0; i <= 9; i++ )
		cout << d[0][i] << endl;
	cout << ans << endl;
	*/
	return 0;
}

