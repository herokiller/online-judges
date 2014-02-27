#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

bool isPrime(int x) {
	int y = (int)(sqrt(x));

	for ( int i = 2; i <= y; i++ )
		if ( x%i == 0 ) 
			return false;
	return true;
}

int main() {
	int nt, p1, p2;
	scanf("%d", &nt);
	for ( int t = 1; t <= nt; t++ ) {
		int x;
		scanf("%d", &x);

		for ( int i = x; (i >= x-1000) && (i >= 2); i-- )
			if ( isPrime(i) ) {
				p1 = i;
				break;	
		    }

		for ( int i = x+1; i <= x+1000; i++ )
			if ( isPrime(i) ) {
				p2 = i;
				break;	
		    }

		long long ans1, ans2;
		if ( p2 == x+1 ) {
			ans1 = p2 - 2;
			ans2 = 2*p2;
		} else {
		    int k = 2*(x-p1+1);
		    ans1 = ((long long)(p1)*(long long)(p2)) - 2*(long long)(p2) + (long long)(k);
		    ans2 = 2*(long long)(p1)*(long long)(p2);
		}

		printf("%I64d/%I64d\n", ans1, ans2);
		
	}
	return 0;
}
