#include <iostream>
#include <stdio.h>

using namespace std;

int n;
string s[10];

int main() {
	scanf("%d", &n);
	if ( n*6 > 100000 ) {
		printf("TOO LONG\n");
		return 0;
	}
	s[1] = "abc";
	s[2] = "acb";
	s[3] = "bac";
	s[4] = "bca";
	s[5] = "cab";
	s[6] = "cba";
	int c = 1;
	if ( n == 1 ) 
		c = 2;
	for ( int i = 1; i <= 6; i=i+c ) {
		int k = 0;
		for ( int j = 1; j <= n; j++ ) {
			printf("%c", s[i][k]);
			k = (k+1)%3;
		}
		printf("\n");
	}
	return 0;
}

