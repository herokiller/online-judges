#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>

#define N 60

using namespace std;

struct cell {
	int x, y;
};

cell q[N];
int b[N][N], ans, n;
bool hits;


bool hit(cell a, cell b) {
	return ((a.x == b.x) || (a.y == b.y) || (abs(a.x - b.x) == abs(a.y - b.y)));
}

bool inside(int x, int y) {
	return ( ( x >= 1 ) && ( x <= n ) && ( y >= 1 ) && ( y <= n ) ); 
}

void mark(int x, int y) {
	if (inside(x, y)) {
		if ( b[x][y] == 2 )
			hits = 1;

		b[x][y] = 1;
	}
}

void spread(int x, int y) {
	
	b[x][y] = 2;

	for ( int j = 1; j <= n+1; j++ ) {			
		mark(x + j, y);
		mark(x - j, y);
		mark(x, y + j);
		mark(x, y - j);
    			 
    	mark(x + j, y + j);
    	mark(x + j, y - j);
    	mark(x - j, y + j);
    	mark(x - j, y - j);        
    }
}


void put(cell p[], int np, int turn) {

	if ( turn == 3 ) {
		ans++;
		return;
	}

	for ( int i = 1; i <= np; i++ ) {
	
		cell pt[10]; 
		int npt = 0;

		for ( int j = i+1; j <= np; j++ )
			if ( !hit(p[i], p[j]) ) {
				npt++;
				pt[npt] = p[j];
			}
		
		put(pt, npt, turn + 1);
	}

   	return;
}


void count(int i1, int i2, int i3) {
        
	hits = 0;

    memset(b, 0, sizeof(b));
    for ( int i = 0; i < n; i++ ) 
    	if (( i != i1 ) && ( i != i2 ) && ( i != i3 )) {
    		spread(q[i].x, q[i].y);
    		if ( hits ) 
    			return;
    	}
                		
    mark(q[i1].x, q[i1].y);
    mark(q[i2].x, q[i2].y);
    mark(q[i3].x, q[i3].y);


    int np = 0;
    cell p[10];

    for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			if ( !b[i][j] ) {
				np++;
				p[np].x = i;
				p[np].y = j;
				
			}

    put(p, np, 0);    		
}



int main() {
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
		scanf("%d%d", &q[i].x, &q[i].y);

	for ( int i = 0; i < n; i++ )
		for ( int j = i+1; j < n; j++ )
			for ( int k = j+1; k < n; k++ )
				count(i, j, k);

	printf("%d\n", ans);
}
