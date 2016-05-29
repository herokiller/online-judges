#include <iostream>
#include <stdio.h>

using namespace std;

int n, k;

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		int x;
		scanf("%d", &x);
		k += x/2;
	}

	if ( k%2 == 0 )
		printf("Stannis\n");
	else
		printf("Daenerys\n");
	return 0;
}
