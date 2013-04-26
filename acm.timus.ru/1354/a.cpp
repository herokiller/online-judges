#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

char s[50000], s1[30000];
int n, d[50000];

int main() {
	gets(s1);
	int k = strlen(s1);

	int n = 0;
	for ( int i = k-1; i >= 0; i-- ) {
		s[n] = s1[i];
		n++;
	}

	s[n] = '#';
	n++;
	for ( int i = 0; i < k; i++ ) {
		s[n] = s1[i];
		n++;
	} 

	
	for (int i=1; i<n; ++i) {
		int j = d[i-1];
		while (j > 0 && ((s[i] != s[j]) || ((s[i] == s[j]) && (j == i - k-1))) )
			j = d[j-1];
		if ((s[i] == s[j]) && (j != i-k-1))  ++j;
		d[i] = j;
	}

	for ( int i = 0; i < k; i++ )
		printf("%c", s1[i]);

	for ( int i = d[n-1]; i < k; i++ )
		printf("%c", s[i]);

	
	return 0;
}
