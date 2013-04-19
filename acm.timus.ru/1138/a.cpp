#include <stdio.h>
#include <iostream>

#define N 10100

using namespace std;

int a[N];

int main() {
	int x, y, m = 0;
	scanf("%d%d", &y, &x);
	a[x] = 1;

	for ( int i = x; i <= y; i++ ) {
		if ( a[i] > m ) m = a[i];

		if ( a[i] > 0 )
			for ( int j = 1; j <= 100; j++ )
				if (((i*j)%100 == 0) && (i + (i*j)/100 <= y)) 
					if ( (a[i] + 1 > a[i + (i*j)/100]) ) 
						a[i + (i*j)/100] = a[i] + 1;
	}
		
	printf("%d\n", m);

	return 0;
}

