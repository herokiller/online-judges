#include	 <iostream>
#include <stdio.h>

using namespace std;

struct dice {
	int v[6];
};

struct l {
	int v, next;
};

dice a[100100];

l d[100100];
int head[1000010], n, k, ans[10000], nans, t[100010], nt;

void turnUpLeft(dice &x) {

	int c = x.v[0];
	x.v[0] = x.v[2];
	x.v[2] = x.v[1];
	x.v[1] = x.v[4];
	x.v[4] = c;
}

void turnForwardUp(dice &x) {
	int c = x.v[3];
	x.v[3] = x.v[4];
	x.v[4] = x.v[5];
	x.v[5] = x.v[2];
	x.v[2] = c;
}

void reduce(dice &x) {

	dice y = x;

	for (int i = 1; i <= 4; i++ ) {
		turnUpLeft(y);
		if ( y.v[0] < x.v[0] ) 
			x = y;
	}

	turnForwardUp(y);

	for (int i = 1; i <= 4; i++ ) {
		turnUpLeft(y);
		if ( y.v[0] < x.v[0] ) 
			x = y;
	}

	y = x;
	for ( int i = 1; i <= 4; i++ ) {
		turnForwardUp(y);
		if  ( y.v[2] < x.v[2] )
			x = y;	
	}
}

int toInt(dice x){
	int y = 0;
	for ( int i = 0; i < 6; i++ )	
		y = y*10 + x.v[i];

	return y;
}


int main() {
	scanf("%d", &n);

	k = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j < 6; j++ )
			scanf("%d", &a[i].v[j]);

		reduce(a[i]);

		int x = toInt(a[i]);
		if ( head[x] == 0 ) {
			nans++;
			ans[nans] = x;
		}

		k++;
		d[k].v = i;
		d[k].next = head[x];
		head[x] = k;		
	}


	printf("%d\n", nans);

	for ( int i = 1; i <= nans; i++ ) {
		nt = 0;
		for ( int j = head[ans[i]]; j > 0; j = d[j].next ) {
			nt++;
			t[nt] = d[j].v;
		}

		for ( int j = nt; j >= 1; j-- )
			printf("%d ", t[j]);
		printf("\n");
	}

	return 0;
}
