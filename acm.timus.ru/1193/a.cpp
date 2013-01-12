#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100

using namespace std;

struct mass {
	int t1, t2, t3, t4;
};

mass a[N];
int n;

bool comp(mass A, mass B) {
	return (A.t1 < B.t1);
}

int main() {
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
		scanf("%d%d%d", &a[i].t1, &a[i].t2, &a[i].t3);

	sort(a, a+n, comp);
	
	int t = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( a[i].t1 > t ) 
			t = a[i].t1;

		t += a[i].t2;
		a[i].t4 = t - a[i].t3;
	}

	int ans = 0;
	for ( int i = 0; i < n; i++ )
		if ( a[i].t4 > ans ) 
			ans = a[i].t4;

	printf("%d\n", ans);
	return 0;
}

