#include <iostream>

#include <stdio.h>

using namespace std;

struct segment {
  	int p1, p2;
};

struct mass {
	int index, number;
};

segment a[110];
mass d[3000];
int n;

int main() {
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
    	scanf("%d%d", &a[i].p1, &a[i].p2);
    	if ( a[i].p1 > a[i].p2 ) {
    		int c = a[i].p1;
    		a[i].p1 = a[i].p2;
    		a[i].p2 = c;
    	}	
    }

    for ( int i = 1; i <= 2050; i++ ) {
    	d[i].number = d[i-1].number;
    	d[i].index = d[i-1].index;

    	for ( int j = 0; j < n; j++ )
    		if (a[j].p2 == i - 1000 ) {
    			if ( d[a[j].p1 + 1000].number + 1 > d[i].number ) {
    				d[i].number = d[a[j].p1 + 1000].number + 1;
    				d[i].index = j;
    			}
    		}
   	}
    	
   	printf("%d\n", d[2000].number);

   	segment ans[110];
   	int nans = 0;

    int i = 2000;
    while ( d[i].number > 0 ) {
    	ans[nans] = a[d[i].index];
    	nans++;
		i = a[d[i].index].p1 + 1000;
    }

    for ( int i = nans-1; i >= 0; i-- )
    	printf("%d %d\n", ans[i].p1, ans[i].p2);
    
	return 0;
}
