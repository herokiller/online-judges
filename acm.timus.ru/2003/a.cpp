#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int b[10000005], n;

int main() {
	scanf("%d", &n);
	int ans = 0;
	for ( int i = 1; i <= n; i++ ) {
		int x, y;
		scanf("%d", &x);
		y = (int)(sqrt(x));

		for ( int j = 2; j <= y; j++ ) {
			int k = 0;
			while (x%j == 0) {								
				if ( k == 0 ) {
					if ( b[j] >= 2 ) {
						printf("infinity\n");	
						return 0;
					} else {
						b[j]++;
						if (b[j] == 2 )
							ans = 2;
						if (ans == 0)
							ans = 1;
					}
				}			
				k++;
				x /= j;	
			}
		}

		if ( x > 1 ) {
			if (b[x] >= 2 ) {
				printf("infinity\n");
				return 0;
			} else {
				b[x]++;
				if ( b[x] == 2 )
					ans = 2;
				if ( ans==0)
					ans = 1;
			}
		}
    }

    printf("%d\n", ans);
         	
	return 0;
}
