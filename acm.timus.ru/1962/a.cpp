#include <iostream>
#include <stdio.h>

#define MOD 1000000007

using namespace std;

int a[200], d[200], b[200][200], n, m, x;

int main() {
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ )	
		a[i] = i;
    
    for ( int i = 1; i <= m; i++ ) {
		scanf("%d", &x);
		
		int c1, c2;
		if ( a[x] < a[i] ) {
			c1 = a[x];
			c2 = a[i];
		} else {
			c1 = a[i];
			c2 = a[x];
		}
				
		bool ok = true;

		int t1 = 0, t2 = 0;
		for( int j = 1; j <= n; j++ ) {
			if (b[j][x] == 1 )
				t1++;
			else if ( b[x][j] == 1 )
				t1++;

		   	if (b[j][i] == 1 )
		   		t2++;
		   	else if ( b[i][j] == 1 )
		   		t2++;
		}

		if (( t1 >= 2 ) || (t2 >= 2))
			ok = false;				
			
		if ( c1 == c2 ) {
			bool f = true;
			for ( int j = 1; j <= n; j++ )
				if ( a[j] != c1 ) {
					f = false;
					break;
				}
		   	if (!f)
		   		ok = false;
		}
		        					
		if (b[x][i] == 1)
			ok = true;

		if (!ok) {
			printf("0\n");
			return 0;
		}

		for ( int j = 1; j <= n; j++ )
			if ( a[j] == c2 ) 
				a[j] = c1;

		b[i][x] = 1; 
	}

	for ( int i = 1; i <= n; i++ )
		d[a[i]]++;
		
	long long ans = 1, k = 0;

	for ( int i = 1; i <= n; i++) {
		if ( d[i] > 0 ) {
			if ( k > 0 )
				ans = (ans*k)%(long long)MOD;
			k++;
		}

		if ( d[i] > 1 ) 
			ans = (ans*(long long)2)%(long long)MOD;
	}
	if (( n == 2 ) && ( ans > 1 )) 
		ans = 1;

	cout << ans << endl;
	return 0;
}
