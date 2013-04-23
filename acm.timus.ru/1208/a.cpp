#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

bool b[30][30];
char s[10000];
string names[30][5];
int a[30], n;

int main() {
	scanf("%d\n", &n);

	for ( int i = 0; i < n; i++ ) {
		gets(s);
		int m = strlen(s), k = 0;
		names[i][k] = "";
		for ( int j = 0; j < m; j++ )
			if (s[j] == ' ') {
				k++;
				names[i][k] = "";
			} else {
				names[i][k] += s[j];
			}

	}

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			for ( int ii = 0; ii < 3; ii++ )
				for ( int jj = 0; jj < 3; jj++ )
					if ( names[i][ii] == names[j][jj] ) {
						b[i][j] = true;
						break;
					}

		

	int ans = 0;
	for ( int i = 1; i < (1 << n); i++ ) {

		int k = 0;
		for ( int j = 0; j < n; j++ )
			if ( (i >> j) & 1 ) {
				k++;
				a[k] = j;
			}
		
		bool ok = true;
		for ( int j = 1; j <= k; j++ )
			for ( int q = j+1; q <= k; q++ )
				if (b[a[j]][a[q]]) {
					ok = false;
					break;	
				}

		if (( ok ) && ( k > ans))
			ans = k;
	}

	printf("%d\n", ans);
	return 0;
}
