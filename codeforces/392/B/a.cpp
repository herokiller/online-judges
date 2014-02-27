#include <iostream>
#include <stdio.h>

using namespace std;

struct move {
 	long long fx, fr;
};

move d[50][5][5];
long long c[5][5];
int n;

int main() {
	for ( int i = 1; i <= 3; i++ )
		for ( int j = 1; j <= 3; j++ )
			scanf("%I64d", &c[i][j]);

	scanf("%d", &n);
	
	d[1][1][3].fr = 1;

	for ( int i	= 2; i <= n; i++ ) {
		d[i][1][3].fx = d[i-1][1][2].fx; 
		d[i][1][3].fr = d[i-1][1][2].fr; 

		d[i][1][2].fx = d[i-1][1][3].fx;
		d[i][1][2].fr = d[i-1][1][3].fr;

		d[i][3][1].fx = d[i-1][2][1].fx;
		d[i][3][1].fr = d[i-1][2][1].fr;

		d[i][2][1].fx = d[i-1][3][1].fx;
		d[i][2][1].fr = d[i-1][3][1].fr;

		d[i][2][3].fx = d[i-1][3][2].fx;
		d[i][2][3].fr = d[i-1][3][2].fr;

		d[i][3][2].fx = d[i-1][2][3].fx;
		d[i][3][2].fr = d[i-1][2][3].fr;


		d[i][1][3].fx++;

		d[i][2][3].fx += d[i-1][1][3].fx;
		d[i][2][3].fr += d[i-1][1][3].fr;

		d[i][2][1].fx += d[i-1][1][2].fx;
		d[i][2][1].fr += d[i-1][1][2].fr;

		d[i][1][3].fx += d[i-1][2][3].fx;
		d[i][1][3].fr += d[i-1][2][3].fr;

		d[i][3][1].fx += d[i-1][3][2].fx;
		d[i][3][1].fr += d[i-1][3][2].fr;

		d[i][1][2].fx += d[i-1][2][1].fx;
		d[i][1][2].fr += d[i-1][2][1].fr;

		d[i][3][2].fx += d[i-1][3][1].fx;
		d[i][3][2].fr += d[i-1][3][1].fr;

	}

	if ( n%2 == 0 ) {
		move t;
		t = d[n][1][2];
		d[n][1][2] = d[n][1][3];
		d[n][1][3] = t;

		t = d[n][2][1];
		d[n][2][1] = d[n][3][1];
		d[n][3][1] = t;

		t = d[n][2][3];
		d[n][2][3] = d[n][3][2];
		d[n][3][2] = t;
	}	

	long long ans = 0;
	for ( int i = 1; i <= 3; i++ )
		for ( int j = 1; j <= 3; j++ ) {
			ans += d[n][i][j].fx * c[i][j];
			if ( c[i][j] > c[i][6-i-j] + c[6-i-j][j] )
				ans += d[n][i][j].fr * (c[i][6-i-j] + c[6-i-j][j]);
			else
				ans += d[n][i][j].fr * c[i][j];
		}


		printf("%I64d", ans);	
	return 0;
}
