#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

char s[10000], t[10000];
int n;

bool isLetter(char ch) {
	return (( (ch >= 'a') && (ch <= 'z') ) || ((ch >= 'A') && (ch <= 'Z')));
}

int main() {
	while (gets(s)) {
		n = strlen(s);
		int k = 0;
		for ( int i = 0; i < n; i++ ) {			
			if (!isLetter(s[i])) {
				for ( int j = k-1; j >= 0; j-- )
					printf("%c", t[j]);
				k = 0;
			 	printf("%c", s[i]);
			} else {
				t[k] = s[i];
				k++;
			}
		}

		for ( int j = k-1; j >= 0; j-- )
			printf("%c", t[j]);
		printf("\n");
    }
	return 0;
}
