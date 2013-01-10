#include <stdio.h>

using namespace std;

int n;

int main() {
	int ansp = 1, ansc = 0, v = 0, p = 0, c = 0, x;

    scanf("%d", &n);
    
    for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &x);
		if ( p == 0 ) {
			p = i;			
			v = x;
		} else {
			c++;
			if ( v > x ) {
			    if ( c > ansc ) {
			    	ansc = c;
			    	ansp = p;
			    }
			    v = x;
				p = i;
				c = 1;
			}
		}
    }

    if ( c > ansc ) {
     	ansp = p;
    }

    printf("%d\n", ansp);

	return 0;
}
