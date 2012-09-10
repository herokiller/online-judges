#include <iostream>
#include <stdio.h>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if ( n >= 1000 ) 
		printf("legion\n");
	else if ( n >= 500 )
		printf("zounds\n");
	else if ( n >= 250 )
		printf("swarm\n");
	else if ( n >= 100 )
		printf("throng\n");
	else if ( n >= 50 )
		printf("horde\n");
	else if ( n >= 20 )
		printf("lots\n");
	else if ( n >= 10 )
		printf("pack\n");
	else if ( n >= 5 )
		printf("several\n");
	else
		printf("few\n");

	return 0;
}

