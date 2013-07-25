#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
	long long x, y, p, i;
};

point a[10];

bool comp1(point a, point b) {
	return a.x < b.x;
}

bool comp2(point a, point b) {
	return a.y < b.y;
}

int main() {
	for ( int i = 1; i <= 4; i++ ) {
		a[i].i = i;
		cin >> a[i].x >> a[i].y;
		if ( i <= 2 )
			a[i].p = 1;
		else
			a[i].p = 2;
	}	

	int dir1, dir2;
	if ( (( a[1].x - a[2].x ) * ( a[1].y - a[2].y)) >= 0)
		dir1 = 1;
	else
		dir1 = 2;

	if ( (( a[3].x - a[4].x ) * ( a[3].y - a[4].y)) >= 0)
		dir2 = 1;
	else
		dir2 = 2;

	long long d1 = -1, d2 = -1;
	sort(a+1, a+5, comp1);

	if ( a[1].p != a[2].p ) { 
		d1 = abs(a[2].x - a[3].x);
	} else if ( a[2].x == a[3].x )
		d1 = 0;

	sort(a+1, a+5, comp2);
		
	if ( a[1].p != a[2].p ) {
		d2 = abs(a[2].y - a[3].y);
	} else if ( a[2].y == a[3].y )
		d2 = 0;

	long long ans;	
	if (dir1 == dir2 ) 
		ans = d1 + d2;
	else 
		ans = max(d1, d2);

	if (( d1 == -1 ) || ( d2 == -1))		
		printf("0\n");
	else
		cout << ans<< endl;
		
   	return 0;
}
