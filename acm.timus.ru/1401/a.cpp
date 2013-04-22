#include <stdio.h>
#include <iostream>

using namespace std;

int a[1050][1050], b[1050][1050], n, k, p;

void complement(int m) {
	
	for ( int i = 1; i <= m; i++ )
		for (int j = 1; j <= m; j++ ) {
			a[m-j+1][i+m] = a[i][j] + k;
			a[m+j][m-i+1] = a[i][j] + 2*k;
			a[m+i][m+j] = a[i][j] + 3*k;
		}

	k = k*4 + 1;
	a[m][m+1] = k;
	a[m+1][m] = k;
	a[m+1][m+1] = k;

}

int main() {
	scanf("%d", &n);
		
	a[1][1] = 0;
	a[1][2] = 1;
	a[2][1] = 1;
	a[2][2] = 1;

	p = 1;
	k = 1;

	for ( int i = 1; i < n; i++ ) {
		p *= 2;
		complement(p);
	}

	p *= 2;
	int pp = p;

    int x, y, i1 = 1, i2 = p, j1 = 1, j2 = p;

	scanf("%d%d", &x, &y);


	while ( p >= 2 ) {

		//cout << i1 << '-' << i2 << ',' << j1 << '-' << j2 << ' ' << p << endl;
		
		if (( x <= ((i1+i2)/2) ) && (y <= ((j1+j2)/2))) {
			for ( int i = 1; i <= p; i++ )
				for ( int j = 1; j <= p; j++ )
					if (!((i <= p/2) && (j <= p/2)))
						b[i1-1+i][j1-1+j] = a[i][j];				

			i2 = (i1+i2)/2;
			j2 = (j1+j2)/2;
		} else
		if (( x > ((i1+i2)/2) ) && (y <= ((j1+j2)/2))) {
			for ( int i = 1; i <= p; i++ )
				for ( int j = 1; j <= p; j++ )
					if (!((i <= p/2) && (j <= p/2)))
						b[i1-1+p-j+1][j1-1+i] = a[i][j];

			i1 = (i1+i2)/2 +1;
			j2 = (j1+j2)/2;

		} else
		if (( x <= ((i1+i2)/2) ) && (y > ((j1+j2)/2))) {
			for ( int i = 1; i <= p; i++ )
				for ( int j = 1; j <= p; j++ )
					if (!((i <= p/2) && (j <= p/2)))
						b[i1-1+j][j1-1+p-i+1] = a[i][j];

		   	i2 = (i1+i2)/2;
		   	j1 = (j1+j2)/2 + 1;

		} else 
		if (( x > ((i1+i2)/2) ) && (y > ((j1+j2)/2))) {
			for ( int i = 1; i <= p; i++ )
				for ( int j = 1; j <= p; j++ )
					if (!((i <= p/2) && (j <= p/2)))
						b[i1-1+p-j+1][j1-1+p-i+1] = a[i][j];

		   	i1 = (i1+i2)/2 + 1;
		   	j1 = (j1+j2)/2 + 1;
		}

		p /= 2;

	}

	for ( int i = 1; i <= pp; i++ ) {
		for ( int j = 1; j <= pp; j++ )
			printf("%d ", b[i][j]);
		printf("\n");
	}

	return 0;
}
