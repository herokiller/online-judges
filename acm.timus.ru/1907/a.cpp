#include <iostream>
#include <cmath>

using namespace std;

long long a, b, c, d[20], nd = 0;

int main() {
	cin >> a >> b;

	c = a;

	int x = (long long)(sqrt(c));

	long long i = 1;

	while (i <= x) {
		i++;
		if ( c%i == 0 ) {
			nd++;
			d[nd] = i;
			while ( c%i == 0 ) 
				c /= i;
		}	
	}

	if ( c > 1 ) {
		nd++;
		d[nd] = c;
	}

	long long ans = 0;

	if ( a%2 == 0 ) {
		for ( int i = 1; i <= (1 << nd)-1; i++ ) {
			int k = 0;
			long long x = 1;

			for ( int j = 0; j < nd; j++ )
				if ((i >> j) & 1) {
					k++;
					x *= d[j+1];
				}	
			
			if (k%2 == 0 ) 
				ans -= b/x;
			else
				ans += b/x;			
		}
	} else {
		ans = b/2;
		if ( b%2 == 1 ) 
			ans++;

		for ( int i = 1; i <= (1 << nd)-1; i++ ) {
			int k = 0;
			long long x = 1;

			for ( int j = 0; j < nd; j++ )
				if ((i >> j) & 1) {
					k++;
					x *= d[j+1];
				}	
			
			if (k%2 == 0 ) 
				ans -= (b/x)/2;
			else
				ans += (b/x)/2;			
		}		
	}

	cout << ans << endl;
	return 0;
}
