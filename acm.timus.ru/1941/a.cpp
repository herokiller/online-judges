#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

char s[3000020];
int t[4000000], n, a[2000000];

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)		
		t[v] += new_val;		
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);

		t[v] = abs(t[v*2]) + abs(t[v*2+1]);
	}
}

int main() {
	gets(s);

	n = strlen(s);
	int k = 0;
	for ( int i = 0; i < n; i += 4, k++ ) {		
		int c = (s[i]-33) + 100*(s[i+1]-33) + 10000*(s[i+2]-33);
		update(1, 0, 1000000, c, 1);
	}

	gets(s);
	n = strlen(s);
	int ans = 0, j = 0;

	for ( int i = 0; i < n; i += 4, j++ ) {
		a[j] = (s[i]-33) + 100*(s[i+1]-33) + 10000*(s[i+2]-33);
				
		update(1, 0, 1000000, a[j], -1);

		if ( j - k >= 0 )
			update(1, 0, 1000000, a[j-k], 1);

		if ( t[1] == 0 )  
			ans++; 
	}

	printf("%d\n", ans);

	return 0;
}
