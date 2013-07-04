#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 100000;

int t[MAXN*4], n, b[MAXN];

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (int v, int tl, int tr, int pos) {
	if (tl == tr)
		t[v]++;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos);
		else
			update (v*2+1, tm+1, tr, pos);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		int x, y;		scanf("%d%d", &x, &y);

		int ans = sum(1, 0, 32767, 0, x);
		b[ans]++;
		update(1, 0, 32767, x);

	}

	for ( int i = 0; i < n; i++ )
		printf("%d\n", b[i]);
			
	return 0;
}
