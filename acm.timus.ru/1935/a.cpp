#include <stdio.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int ans = 0, m = 0, x;
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &x);
		ans += x;
		if ( x > m ) 
			m = x;
	}	

	ans += m;
	printf("%d\n", ans);

	return 0;
}
