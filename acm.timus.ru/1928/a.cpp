#include <iostream>
#include <stdio.h>

using namespace std;

struct mass {
	int p1, p2;
};

mass d[10100];
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);

	d[0].p1 = 0;
	d[0].p2 = 0;

	for ( int i = 1; i <= n; i++ ) {
		if ( i < k ) {
			d[i].p1 = m;
			d[i].p2 = 0;
		}

		for ( int j = i-1; j >= max(0, i-k); j-- )
			if (( d[j].p2 + i - j > d[i].p1 ) || (( d[j].p2 + i - j == d[i].p1 ) && ( d[j].p1 < d[i].p2 ))) {
				d[i].p1 = d[j].p2 + i - j;
				d[i].p2 = d[j].p1;
			}
	}

	printf("%d %d\n", d[n].p1, d[n].p2);

	return 0;
}
