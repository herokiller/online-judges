#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int b[100100];
int n;

int main() {
	scanf("%d", &n);
	int x;
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &x);
		if ( i - x >= 0 )
			b[i-x]++;
		else 
			b[n-x+i]++;
	}


 	int ans = 0, pans = 0;
	for ( int i = 0; i < n; i++ ) 
		if ( b[i] > ans ) {
			ans = b[i];
			pans = i;
		}

	printf("%d\n", pans+1);
	return 0;
}

