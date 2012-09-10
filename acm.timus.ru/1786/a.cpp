#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

using namespace std;

char s[1000];

int main() {
	int x = abs(int('A' - 'a'));

	gets(s);
	int n = strlen(s), ans = 1000, t;

	string name = "Sandro";
	for ( int i = 0; i < n - 5; i++ ) {
		t = 0;
		for ( int j = 0; j < 6; j++ )
			if ( s[i+j] != name[j] )
				if ( abs(int(s[i+j] - name[j])) == x )
					t += 5;
				else if ( (((s[i+j] >= 'A') && (s[i+j] <= 'Z')) && ((name[j] >= 'A') && (name[j] <= 'Z'))) 
				       || (((s[i+j] >= 'a') && (s[i+j] <= 'z')) && ((name[j] >= 'a') && (name[j] <= 'z'))) )
					t += 5;
				else 
					t += 10;

		if ( t < ans ) ans = t;
	}
	printf("%d\n", ans);

	return 0;

}

