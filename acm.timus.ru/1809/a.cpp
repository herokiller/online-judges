#include <iostream>
#include <stdio.h>

using namespace std;

struct point {
	int x, y;
};

point a[10], b[10];
int k;
bool ok;

bool check() {

	for ( int i = 1; i <= 4; i++ ) {
		int t = 0;
		for ( int j = 1; j <= 4; j++ ) 
			if ((i != j) && ((b[i].x == b[j].x) ^ ( b[i].y == b[j].y)))
				t++;

		if ( t != 1 )
			return false;
	}

	return true;
}

void rec(int p) {
	if ( p == k+1 ) {
		if ( check() )
			ok = true;
		return;
	}

	for ( int q = p; q <= 4; q++ )
		for ( int i = 1; i <= 20; i++ )
			for ( int j = 1; j <= 20; j++ ) {
				if ( (a[q].x != i) || (a[q].y != j) ) {
					b[q].x = i;
					b[q].y = j;
					rec(p+1);
					if ( ok ) 
						return;
					b[q] = a[q];
				}
			}
}

int main() {
	for ( int i = 1; i <= 4; i++ ) {
		scanf("%d%d", &a[i].x, &a[i].y);
		b[i] = a[i];
	}


	ok = false;

	for ( int i = 0; i <= 2; i++ ) {
		k = i;
		rec(1);
		if (ok) {
			for ( int j = 1; j <= 4; j++ ) 
				printf("%d %d\n", b[j].x, b[j].y);
			
			return 0;
		}
	}

	return 0;
}
