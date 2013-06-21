#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char s[20000];
	int h, w, n;

	scanf("%d%d%d\n", &h, &w, &n);

	int page = 1, hcur = 1, wcur = 0;

	for ( int i = 0; i < n; i++ ) {
		gets(s);
		int k = strlen(s);
		if ( wcur == 0 ) {
			wcur = k;
		} else {
			if ( k + 1 <= w - wcur ) {
				wcur += k + 1;
			} else {
				if ( hcur < h ) {
					hcur++;
					wcur = k;
				} else {
					page++;
					hcur = 1;
					wcur = k;
				}
			}
		}
	}

	printf("%d\n", page);
	return 0;
}

