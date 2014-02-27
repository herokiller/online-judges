#include <iostream>
#include <stdio.h>

using namespace std;

int n, k, a[200];

int main() {
	scanf("%d%d", &n, &k);
	int d = n/k;
	if ( n%k != 0 )
		d++;

    for ( int i = 1; i <= n; i++ )
    	scanf("%d", &a[i]);

    for ( int i = 1; i <= d; i++ ) {
    	int x = i;

    	while ( x <= n ) {
    		int sp;
    		if ( a[x] >= 1000 )
    			sp = 0;
    		else if ( a[x] >= 100 )
    			sp = 1;
    		else if ( a[x] >= 10 )
    			sp = 2;
    		else 
    			sp = 3;

    		for ( int j = 1; j <= sp; j++ )
    			printf(" ");
    	   	printf("%d", a[x]);
    		x += d;
    	}
    	printf("\n");
    }
    		
	return 0;
}
