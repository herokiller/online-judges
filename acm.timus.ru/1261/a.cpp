#include <iostream>
#include <stdio.h>

using namespace std;

long long a[2000000], n;
int k;

bool exists(long long x) {

	int x1 = 1;
	int x2 = k;

	while (x1 + 1 < x2) {
		int x3 = (x1+x2)/2;
		if ( a[x3] > x ) {
			x2 = x3;
		} else {
			x1 = x3;
		}
	}

	return (( a[x1] == x ) || (a[x2] == x ));

}

int main() {
	scanf("%d", &n);

	long long x = 1;
	a[1] = 1;
	k = 1;

	while (x < 1000000000 ) {
		x *= 3;
		
		k++;
		a[k] = x;
		int p = k;

		for ( int i = 1; i <= k-1; i++ ) {
			p++;
			a[p] = a[i] + x;
		}	
		k = p;	
	}	

	/*
	cout << k << ' ' << a[k] << endl;
	*/

	for ( int i = 1; i <= k; i++ ) {
		if ( exists(a[i] + n)) {
			cout << a[i]+n << ' ' << a[i] << endl;
			return 0;
		}
	}	

	printf("0\n");
		
	return 0;
}
