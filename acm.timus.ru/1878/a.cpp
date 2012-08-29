#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int a[5][5];
int d[5];

int main() {
	for ( int i = 0; i < 4; i++ ) 
		for ( int j = 0; j < 4; j++ )	
			scanf("%d", &a[i][j]);

	d[0] = a[0][0];
	d[1] = a[0][1];
	d[2] = a[1][0];
	d[3] = a[1][1];

	int ans = -1;
	for ( int i = 1; i <= 4; i++ ) {
		int temp = 0;
		for ( int j = 0; j < 4; j++ ) 
			temp += min(abs(d[j] - i), 4 - abs(d[j] - i));

		if (( temp < ans ) || ( ans == -1 )) 
			ans = temp;
	}

	printf("%d\n", ans);
			
	return 0;
}

