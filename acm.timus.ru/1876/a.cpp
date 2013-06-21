#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	int ans = 40+2*b;
	if ( 2*a + 39> ans ) ans = 2*a + 39;
	
	printf("%d\n", ans);
	return 0;
}

