#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 50010

using namespace std;

struct mass {
	int num, v;
};

mass ans[N];
int c[1000100];

bool comp(mass a, mass b) {
	return ((a.v < b.v ) || ((a.v == b.v) && ( a.num < b.num)));
}


int a[3][N], n, k;

int main() {

	scanf("%d%d", &k, &n);
	int k1 = 1, d = 6;
	for ( int i = 1; i <= d; i++ )
		k1 *= k;
	a[0][0] = 1;
	a[1][0] = 1;

	ans[1].num = 1;
	ans[1].v = 1;
	ans[2].num = 2;
	ans[2].v = 1;

	for ( int i = 0; i <= k1-1; i++ ) {
		int x = k, t = i;
		for ( int j = 1; j <= d, t > 0; j++ ) {
			c[i] += t%x;
			t /= x;
		}
	}

	int mk = 0;

	for ( int i = 3; i <= n; i++ ) {
		ans[i].num = i;
		ans[i].v = 0;

		for ( int j = 0; j <= mk; j++ )
			a[2][j] = a[0][j] + a[1][j];

		for ( int j = 0; j <= mk; j++ ) {
			a[2][j+1] += (a[2][j]/k1);
			a[2][j] %= k1;
			ans[i].v += c[a[2][j]];
		}

		if (a[2][mk+1] > 0 ) {
			mk++;
			ans[i].v += c[a[2][mk]];
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
