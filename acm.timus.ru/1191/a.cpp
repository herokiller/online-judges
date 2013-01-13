#include <iostream>
#include <stdio.h>

#define N 200

using namespace std;

int n, t;

int main() {
	scanf("%d%d", &t, &n);

	int x;

	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &x);
		if ( t < x ) {
			printf("YES\n");
			return 0;
		}

		t -= (t%x);
	}	
	printf("NO\n");
	return 0;
}

