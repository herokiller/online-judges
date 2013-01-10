#include <stdio.h>

using namespace std;

int n, m, p;

int main() {
    scanf("%d%d", &n, &m);
    int x;
    bool ok = false;
    for ( int i = 0; i < m; i++ ) {
    	scanf("%d", &x);
    	if ( x == 1 ) {
    		ok = true;
    		break;
    	}
    }

    int ans = 0;

    if ( ok ) {
    	p = n-m;
    	
    	if ( (n-3)/3 == m - 1)
    		ans += (p*(p-1))/2;
    	else if ( (n-3)/3 == m - 2)
    		ans += p*(m-1) + (p*(p-1))/2;    		 
    	else
    		ans += ((n-1)*(n-2)) / 2;

    } else {
    	p = n-m-1;
    	
    	ans += p*m;

    	if ( m - 1 > (n-3)/3)
    		ans += (m*(m-1))/2;    	
    }

    if ( (n/3) > m ) 
    	ans = 0;


    printf("%d\n", ans);

	return 0;
}
