#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

string s[1010];
char temp[100];
int n;
string lang;
string langs[1010];
int nlangs;

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
			nlangs = 0;

			for ( int j = 0; j < n; j++ ) {
				
				if ( j%(n/i) == 0 ) {
					lang = "";
				}

				if ( s[j] != "unknown" ) {
					if (( s[j] != lang ) && (lang == "")) {
						lang = s[j];
						for ( int k = 0; k < nlangs; k++ ) {
							if ( lang == langs[k] ) {
								ok = false;
								break;
							}
						}

						if ( !ok ) break;
						langs[nlangs] = lang;
						nlangs++;
					} else if (s[j] != lang) {
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

