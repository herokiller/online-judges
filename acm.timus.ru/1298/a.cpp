#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct pt{
	int i, j;
};

pt a[100000];
bool b[100][100], ok;
int di[8] = {1, 1, -1, -1, 2, -2, 2, -2}, n, 
	dj[8] = {2, -2, 2, -2, 1, 1, -1, -1};

int p[100][100], c[100][100];

bool check(int x, int y) {
	return ((x >= 1) && (y >= 1) && (x <= n) && (y <= n) && (!b[x][y]));
}

void rec(int p1, int p2, int k) {
	a[k].i = p1;
	a[k].j = p2;	

	b[p1][p2] = 1;
	for ( int i = 0; i < 8; i++ )
		if ( check(p1 + di[i], p2 + dj[i]) )
			p[p1+di[i]][p2+dj[i]]--;

	if ( k == n*n ) {
		ok = true;
		return;
	}	
                   
	bool checked[10];
	int dir = 0;
	memset(checked, 0, sizeof(checked));

	while (true) {
		int t1, t2;
		bool f = false;
		int mp = 0;

		for ( int i = 0; i < 8; i++ )
			if ( check(p1 + di[i], p2+dj[i]) ) {
				if (p[p1+di[i]][p2+dj[i]] == 0) {
					f = false;
					break;
				}
				if ((( mp == 0 ) || (p[p1+di[i]][p2+dj[i]] < mp)) && (!checked[i])) {
					t1 = p1+di[i];
					t2 = p2+dj[i];
					mp = p[p1+di[i]][p2+dj[i]];
					f = true;	
					dir = i;
				}
			}	
			
		if ( !f ) break;

		checked[dir] = true;

		rec(t1, t2, k+1);
		if (ok) return;
	}

	b[p1][p2] = 0;
}

int main() {

	scanf("%d", &n);

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			for ( int k = 0; k < 8; k++ )
				if (check(i+di[k], j+dj[k])) {
					p[i][j]++;
					c[i][j]++;
				}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			
			rec(i, j, 1);
			if (ok) break;
			for ( int k1 = 1; k1 <= n; k1++)
				for ( int k2 = 1; k2 <= n; k2++ )
					p[k1][k2] = c[k1][k2];
		}
		if (ok) break;
	}
	
	if ( ok ) {
		for ( int i = 1; i <= n*n; i++ )
			cout << char(a[i].i + 'a' - 1) << a[i].j << endl;
	} else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
