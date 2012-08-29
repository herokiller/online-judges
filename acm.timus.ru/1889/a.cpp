#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string s[1010];
char temp[100];
int n;
string lang;

int main() {
	scanf("%d\n", &n);
	for ( int i = 0; i < n; i++ ) {
		gets(temp);
		s[i] = "";
		for ( int j = 0; j < strlen(temp); j++ )
			s[i] += temp[j];
	}

	bool found = false;

	for ( int i = 1; i <= n; i++ ) {
		if ( n%i == 0 ) {
			bool ok = true;
			for ( int j = 0; j < n; j++ ) {
				
				if ( j%(n/i) == 0 ) {
					lang = "";
				}

				if ( s[j] != "unknown" ) {
					if (( s[j] != lang ) && (lang == ""))
						lang = s[j];
					else if (s[j] != lang) {
						ok = false;
						break;
					}
				}
			}

			if ( ok ) {
				found = true;
				printf("%d ", i);
			}
		}
	}

	if ( !found ) 
		printf("Igor is wrong.\n");

	return 0;
}

