#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[30][50000], s[30], c[50000], n;

int main() {
	scanf("%d", &n);

	s[1] = 1;
	a[1][1] = 2;

	for ( int i = 2; i <= n; i++ ) {
		a[i][1] = 1;
		s[i] = 1;

		for ( int j = 1; j <= i-1; j++ ) {
			memset(c, 0, sizeof(c));

			for ( int k1 = 1; k1 <= s[i]; k1++ )
				for ( int k2 = 1; k2 <= s[j]; k2++ )
					c[k1+k2-1] += a[i][k1]*a[j][k2];

			if ( j == i -1 )
				c[1]++;

			for (int k1 = 1; k1 <= s[i]+s[j]-1; k1++) {
				c[k1+1] +=c[k1]/10;
				c[k1] %= 10;
			}

			s[i] = s[i]+s[j]-1;
			if ( c[s[i]+1] > 0 )
				s[i]++;

			for ( int k1 = 1; k1 <= s[i]; k1++)
				a[i][k1] = c[k1];
				
		}
	}

	for ( int i = 1; i <= n; i++ ) {
//		cout << s[i]<< endl;

		for ( int j = s[i]; j >= 1; j-- )
			printf("%d", a[i][j]);
		printf("\n");
	}					
					
								

}
