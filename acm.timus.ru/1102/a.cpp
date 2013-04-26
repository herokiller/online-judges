#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int k, n;
char s[10000010];

int findNext(int i) {

	
	if (( i + 2 < k) && (s[i] =='o') && (s[i+1]=='n') && (s[i+2] == 'e'))
		return i+3;

	if (( i + 1 < k) && (s[i] =='i') && (s[i+1]=='n') && ((i+2 == k) || ((i+2 < k) && (s[i+2] != 'p')) || (((i+6 < k) 
	&& (s[i+2] == 'p') && (s[i+3] == 'u') && (s[i+4] == 't') && (s[i+5] == 'o') && (s[i+6] == 'n')) && ((i+7 == k ) || (s[i+7] != 'e')))))
		return i+2;

	if (( i + 4 < k ) && (s[i] == 'i') && (s[i+1] == 'n') && (s[i+2] == 'p') && (s[i+3] == 'u') && (s[i+4] == 't'))
		return i+5;

	if (( i + 2 < k) && (s[i] == 'o') && (s[i+1] == 'u') && (s[i+2] == 't') 
	&& ((i+3 == k) || ((i+3 < k) && (s[i+3] != 'p')) || 
	(((i+7 < k) && (s[i+3] == 'p') && (s[i+4] == 'u') && (s[i+5] == 't') && (s[i+6] == 'o') && (s[i+7] == 'n')) && 
	((i+8 == k ) || (s[i+8] != 'e')))))
		return i+3;
			
	if (( i + 5 < k) && (s[i] == 'o') && (s[i+1] == 'u') && (s[i+2] == 't') && (s[i+3] == 'p') && (s[i+4] == 'u') 
	&& (s[i+5] == 't'))
		return i+6;
		
	if (( i+4 < k) && (s[i] == 'p') && (s[i+1] == 'u') && (s[i+2] == 't') && (s[i+3] == 'o') && (s[i+4] == 'n'))
		return i+5;

	return 0;
}
int main() {
	scanf("%d\n", &n);
	for ( int i = 0; i < n; i++ ) {
		gets(s);
		k = strlen(s);
		int j = 0;		
		bool ok = true;

		while ( j < k ) {
			j = findNext(j);	
			if ( j == 0 ) {
				ok = false;
				break;
			}
		}

		if ( ok )
			printf("YES\n");
		else 
			printf("NO\n");

	}
	return 0;
}
