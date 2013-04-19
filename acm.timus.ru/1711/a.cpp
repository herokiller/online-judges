#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

char s[10000];
string names[1000][3];
int n;

int main() {
	scanf("%d\n", &n);
	for ( int i = 1; i <= n; i++ ) {
		gets(s);
		int l = strlen(s);
		int p = 0;
		string t = "";
		for ( int j = 0; j <= l; j++ )
			if ((s[j] == ' ') || (j == l)) {
				names[i][p] = t;
				t = "";
				p++;
			} else
				t += s[j];	

		
	}


	int x;
	string last = "", cur;

	string ans[1000];
	int nans=0;

	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &x);

		cur = "";

		for ( int j = 0; j < 3; j++ )
			if (( names[x][j] > last ) && ((names[x][j] < cur) || (cur == "")))
				cur = names[x][j];

		if ( cur < last ) {
			printf("IMPOSSIBLE\n");
			return 0;
		}

		ans[nans] = cur;
		nans++;
		last = cur;
   	}

   	for ( int i = 0; i < nans; i++ )
   		cout << ans[i] << endl;
	return 0;
}
