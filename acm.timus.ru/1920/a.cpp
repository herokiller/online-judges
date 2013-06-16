#include <iostream>
#include <stdio.h>

#define N 110

using namespace std;

struct point {
	int i, j, next;
};

point ans[N*N];
int nans, n, k, head = 0, d[N], r[N], nd, nr;

int main() {
	scanf("%d%d", &n, &k);
	if (( k%2 == 1 ) || ( k <= 3) || (k > n*n - (n%2))) {
		printf("Unsuitable device\n");
	} else {
		int p = n;
		if ( k <= n*2 )
			p = k/2;
		
		for ( int i = 1; i <= p; i++ ) {
			nans++;
			ans[nans].i = 1;
			ans[nans].j = i;
			ans[nans].next = head;
			head = nans;
		}

		for ( int i = p; i >= 1; i-- ) {
			nans++;
			ans[nans].i = 2;
			ans[nans].j = i;
			ans[nans].next = head;
			head = nans;
			if (( i%2 == 1 ) && (i != p)) {
				nd++;
				d[nd] = head;
			}
		}			
		
		p = n*2;
		int i = 1, j = 1;
		while ( p < k ) {
			while ((i <= nd) && ( ans[d[i]].i == n ))
				i++;
			
			if ( i <= nd ) {
				int k1 = d[i];
				int k2 = ans[k1].next;

				nans++;
				ans[nans].i = ans[k1].i+1;
				ans[nans].j = ans[k1].j+1;
				ans[nans].next = k2;

				nans++;
				ans[nans].i = ans[k1].i+1;
				ans[nans].j = ans[k1].j;
				ans[nans].next = nans-1;

				ans[k1].next = nans;

				d[i] = nans;

				if (( ans[nans-1].j == n-1) && (ans[nans-1].i %2 == 0)) {
					nr++;
					r[nr] = nans-1;
				}
				p+=2;
			} else {
				
				while ((j <= nr ) && ( ans[r[j]].j == n)) 
					j++;
				
				if ( j <= nr ) {
					int k1 = r[j];
					int k2 = ans[k1].next;

					nans++;
					ans[nans].i = ans[k1].i-1;
					ans[nans].j = ans[k1].j+1;
					ans[nans].next = k2;

					nans++;
					ans[nans].i = ans[k1].i;
					ans[nans].j = ans[k1].j+1;
					ans[nans].next = nans-1;
					
					ans[k1].next = nans;

					r[j] = nans;
					p+=2;
				}
			}
		}

		printf("Overwhelming power of magic\n");
		i = head;
		while (i > 0) {
			printf("%d %d\n", ans[i].i, ans[i].j);
			i = ans[i].next;
		}
	}

	
	return 0;
}

