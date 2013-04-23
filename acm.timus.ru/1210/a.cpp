#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int d[50][50], n, m;
bool b[50][50];

char s[100];

int main() {
	
	int ans = 1000000000;
	b[0][1] = true;

	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &m);
		for ( int j = 1; j <= m; j++ ) {
			
			int from, cost;

			while (true) {
				scanf("%d", &from);
				if (from == 0 ) break; 
				scanf("%d", &cost);

				if (((d[i-1][from] + cost < d[i][j]) || (!b[i][j])) && (b[i-1][from])) {
					d[i][j] = d[i-1][from] + cost;
					b[i][j] = true;
				}
			}

			if (( i == n ) && ( d[i][j] < ans) && (b[i][j]) )
				ans = d[i][j];
			
		}
		gets(s); gets(s);
	}
                           
    printf("%d\n", ans);
	return 0;


}
