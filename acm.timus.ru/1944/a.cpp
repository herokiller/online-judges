#include <iostream>
#include <stdio.h>

struct point {
	int x, y;
};

point a[300];
int n;
	
int main() {
	scanf("%d", &n);
	int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d%d", &a[i].x, &a[i].y);
		if ( a[i].x < xmin ) 
			xmin = a[i].x;
		if ( a[i].x > xmax )
			xmax = a[i].x;
		if ( a[i].y < ymin )
			ymin = a[i].y;
		if ( a[i].y > ymax )
			ymax = a[i].y;
   	}


   	for ( int i = ymax; i >= ymin; i-- ) {
   		for ( int j = xmin; j <= xmax; j++ ) {
   			bool ok = false;

   			for ( int k = 1; k <= n; k++ )
   				if (( a[k].x == j ) && (a[k].y == i)) {
   				 	printf("*");
   				 	ok = true;
   				 	break;
   				}

   			if ( !ok ) {
   				if (( i == 0 ) && ( j == 0 ))
   					printf("+");
   				else if ( i == 0 )
   					printf("-");
   				else if ( j == 0 ) 
   					printf("|");
   				else 
   					printf(".");
   			}
   			
		}
		printf("\n");
	}	

	return 0;
}
