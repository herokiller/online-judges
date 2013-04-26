#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

char a[30000], b[30000];
int n;

void restore(int i, int j, int i1, int j1) {
	if ( i + 1 >= j ) {
		b[i] = a[i1];
		b[j] = a[j1]; 
		return;	
	}

	b[(i+j)/2] = a[i1];
	restore(i, (i+j)/2 - 1, i1+1, (i1+j1)/2);
	restore((i+j)/2 + 1, j, (i1+j1)/2 + 1, j1);
}
int main() {
	gets(a);
	n = strlen(a);

	restore(0, n-1, 0, n-1);
	for ( int i = 0; i < n; i++ )
		printf("%c", b[i]);
		 
	return 0;
}
