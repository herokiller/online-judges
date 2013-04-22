#include <iostream>
#include <stdio.h>

using namespace std;

struct mass {
	int x, val, prev, same;
};

mass d[100010];
int n, p[10100];

int main() {
	scanf("%d", &n);
	int k = 0, x;
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &x);
		d[i].x = x;
		d[i].same = p[x];
		d[i].val = d[i].val + 1;
		d[i].prev = i-1;
		p[x] = i;		
	}


	for ( int i = 2; i <= n; i++ ) {

		d[i].val = d[i-1].val + 1;
		d[i].prev = i-1;

		if ( d[i].same > 0 )	
			if ( d[d[i].same].val < d[i].val ) {
				d[i].val = d[d[i].same].val;
				d[i].prev = d[d[i].same].prev;			
			}
	}


	/*
	for ( int i = 1; i <= n; i++ )
		cout << d[i].val << ' ';
	return 0;
	*/
		
	int ans[100010], nans = 0;

	x = n;
	while ( x > 0 ) {
		nans++;
		ans[nans] = d[x].x;
		x = d[x].prev;	
	}


	for ( int i = nans; i >= 1; i-- )
		printf("%d ", ans[i]);


	return 0;
}
