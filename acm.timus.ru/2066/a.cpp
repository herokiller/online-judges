#include <iostream>
#include <stdio.h>

using namespace std;

int a[5];

int main() {
	for ( int i = 0; i < 3; i++ )
		scanf("%d", &a[i]);

	int ans = a[0] - a[1] - a[2];
	if ( a[0] - a[1]*a[2]  < ans ) 
		ans = a[0] - a[1]*a[2];

	printf("%d\n", ans);
	return 0;
}
