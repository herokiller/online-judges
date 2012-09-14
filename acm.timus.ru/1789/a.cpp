#include <iostream>
#include <stdio.h>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	
	if (n == 2) {
		printf("%d\n", n);
		printf("2 2");
		return 0;
	}

	int ans;

	if ( n%2 == 0 ) 
		ans = (n-2)*2 + 1;
	else 
		ans = (n-1)*2;

	printf("%d\n", ans);
	
	if ( n%2 == 0 ) {
		for ( int i = 2; i <= n; i++ )
			printf("%d ", i);
		for ( int i = 2; i <= n-1; i++)
			printf("%d ", i);
	} else {
		for ( int i = 2; i <= n; i++ )
			printf("%d ", i);
		for ( int i = 1; i <= n-1; i++ )
			printf("%d ", i);

	}

}

