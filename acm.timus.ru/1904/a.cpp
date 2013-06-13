#include <stdio.h>
#include <iostream>

using namespace std;

#define N 1200

struct mass {
	int l, r;
};

int b[100000];
mass d[2][N];
int n, a[N];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);		

	int k = 1;	
	d[0][1].l = a[n] - 1;
	
	d[0][1].r = a[n] + 1;

	if ( n > 1 ) {
		if (( d[0][1].l < 0 ) && ( d[0][1].r < 0))
			k = 0;
		else if ( d[0][1].l < 0 )
			d[0][1].l = 0;
		if ( d[0][1].r < 0 )
			d[0][1].r = 0;
	}
	
	for ( int i = n-1; i >= 1; i-- ) {
		int p = 0;		
		for ( int j = 1; j <= k; j++ ) {
			p++;			
			d[1][p].l = a[i] - d[0][j].r;
			d[1][p].r = a[i] - d[0][j].l;

			if ( i > 1 ) {
				if (( d[1][p].l < 0 ) && ( d[1][p].r < 0)) 
					p--;
				else if ( d[1][p].l < 0 )
					d[1][p].l = 0;
				if ( d[1][p].r < 0 )
					d[1][p].r = 0;
			}

			p++;
			d[1][p].l = a[i] + d[0][j].l;
			d[1][p].r = a[i] + d[0][j].r;			

			if ( i > 1 ) {
				if (( d[1][p].l < 0 ) && ( d[1][p].r < 0)) 
					p--;
				else if ( d[1][p].l < 0 )
					d[1][p].l = 0;
				if ( d[1][p].r < 0 )
					d[1][p].r = 0;
			}
		}

		k = p;
		for ( int j = 1; j <= k; j++ )
			d[0][j] = d[1][j];

    }

    for ( int i = 1; i <= k; i++ ) {

    	if ( d[0][i].l == d[0][i].r ) {
    		if ( b[d[0][i].l + 20000] == 0 )
    			 b[d[0][i].l + 20000] = 1;
    		continue;
    	}

    	if (b[d[0][i].l + 20000] == 3 )
    		b[d[0][i].l + 20000] = 4;
    	else if (b[d[0][i].l + 20000] < 2) 
    		b[d[0][i].l + 20000] = 2;

		if (b[d[0][i].r + 20000] == 2 )
    		b[d[0][i].r + 20000] = 4;
    	else if ( b[d[0][i].r + 20000] < 2 )
    		b[d[0][i].r + 20000] = 3;

    	for ( int j = d[0][i].l+1; j <= d[0][i].r-1; j++ ) 
    		b[j+20000] = 4;
    }

    mass ans[10000];
    int nans = 0;

    for ( int i = 1; i <= 100000; i++ )
		if ( b[i] == 1 ) {
			nans++;
			ans[nans].l = i - 20000;
			ans[nans].r = i - 20000;
			continue;
		} else if ( b[i] > 1 ) {
			k = i+1;
			while ( b[k] == 4 )
				k++;

			nans++;
			ans[nans].l = i - 20000;
			ans[nans].r = k - 20000;
			i = k;
		}


	printf("%d\n", nans);
	for ( int i = 1; i <= nans; i++ )
		printf("%d %d\n", ans[i].l, ans[i].r);

	return 0;
}
