#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct unit {
	int val, member;
};

bool comp(unit a, unit b) {
	return ( a.val < b.val ) || ((a.val == b.val) && (a.member < b.member));
}

int min3(int k1, int k2, int k3) {
	if ((k1 <= k2) && (k1 <= k3)) return k1;
	if ((k2 <= k1) && (k2 <= k3)) return k2;
	return k3;
}
unit a[20000];

int main() {
	int n = 0, k;

	for ( int i = 1; i <= 3; i++ ) {
		scanf("%d", &k);
		for ( int j = 0; j < k; j++ ) {
			scanf("%d", &a[n].val);
			a[n].member = i;
			n++;
		}
	}

	sort(a, a+n, comp);
	
	int ans = 0, k1 = 0, k2 = 0, k3 = 0, last = 0;

	for ( int i = 0; i < n; i++ ) {
		if ( a[i].val > last ) {
			last = a[i].val;
			ans += min3(k1, k2, k3); 
			k1 = k2 = k3 = 0;
		}

		if (a[i].member == 1 ) k1++;
		if (a[i].member == 2 ) k2++;
		if (a[i].member == 3 ) k3++;

	}
	ans += min3(k1, k2, k3);

	printf("%d\n", ans);
	return 0;
}

