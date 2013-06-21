#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 50010

using namespace std;

struct mass {
	int num, v;
};

mass ans[N];

bool comp(mass a, mass b) {
	return ((a.v < b.v ) || ((a.v == b.v) && ( a.num < b.num)));
}


int a[3][N], n, k;

int main() {

	scanf("%d%d", &k, &n);

	a[0][0] = 1;
	a[1][0] = 1;

	ans[1].num = 1;
	ans[1].v = 1;
	ans[2].num = 2;
	ans[2].v = 1;


	int mk = 0;

	for ( int i = 3; i <= n; i++ ) {
		ans[i].num = i;
		ans[i].v = 0;

		for ( int j = 0; j <= mk; j++ )
			a[2][j] = a[0][j] + a[1][j];

		for ( int j = 0; j <= mk; j++ ) {
			a[2][j+1] += (a[2][j]/k);
			a[2][j] %= k;
			ans[i].v += a[2][j];
		}

		if (a[2][mk+1] > 0 ) {
			mk++;
			ans[i].v += a[2][mk];
		}

		for ( int j = 0; j <= mk; j++ ) {
			a[0][j] = a[1][j];
			a[1][j] = a[2][j];
		}
			
	}

	sort(ans+1, ans+n+1, comp);

	for ( int i = 1; i <= n; i++ )
		printf("%d ", ans[i].num);
	return 0;
}
