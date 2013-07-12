#include <iostream>
#include <stdio.h>

using namespace std;

int n, a[200][200];

bool inside(int x, int y) {
	return ((x >= 1) && (x <= n) && (y >= 1) && (y <= n));
}

int main() {
	scanf("%d", &n);

	int xs = 1, ys = 1, xc = 1, yc = 1, k = n*n;

	while (true) {
		
		if ( inside(xc, yc) ){
			
			a[xc][yc] = k;
			xc--;
			yc++;
			k--;
		} else {
			xs += 2;
			if ( !inside(xs, ys) ) {
				xs--;
				ys++;
				if ( !inside(xs, ys) ) {
					xs--;
					ys++;
					if (!inside(xs, ys) )
						break;
				}
					
			}
			xc = xs;
			yc = ys;
		}		   			
	}
	
	xs = n-1; 
	ys = n; 
	xc = xs;
	yc = ys;

	while (true) {
		
		if ( inside(xc, yc) ){			
			a[xc][yc] = k;
			xc++;
			yc--;
			k--;
		} else {
			xs -= 2;
			if ( !inside(xs, ys) ) {
				xs++;
				ys--;
				if ( !inside(xs, ys) ) {
					xs++;
					ys--;
					if (!inside(xs, ys) )
						break;
				}
					
			}
			xc = xs;
			yc = ys;
		}		   			
	}

	int di[4] = {0, 0, 1, -1};
	int dj[4] = {1, -1, 0, 0};
	int ans = 0;
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			for ( int k = 0; k < 4; k++ )
				if ( inside(i+di[k], j+dj[k] ) )
					if ( a[i][j] + a[i+di[k]][j+dj[k]] > ans )
						ans = a[i][j] + a[i+di[k]][j+dj[k]];
	
	printf("%d\n", ans);
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			printf("%d ", a[i][j]);
		printf("\n");
	}								
	return 0;
}
