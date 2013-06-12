#include <iostream>
#include <stdio.h>
#include <string.h>

#define M 1000000007
#define MAXN 5010

using namespace std;

int a[MAXN], n, m, d[2][MAXN], q[3][MAXN];

int main() {

	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &a[i]);

	int x, p;
	scanf("%d%d", &x, &p);

	int p1 = 0, p2 = -1, p3 = 0;

	for ( int i = 1; i <= n; i++ )
		if ( a[i] < a[x] )
			p1++;
		else if ( a[i] == a[x] )
			p2++;
		else
			p3++;	

		    
    d[0][0] = 1;
    q[0][0] = 1;
    q[1][0] = 1;
    q[2][0] = 1;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j <= i; j++ )
			if ( j == 0 ) 
				d[1][j] = 1;
			else
				d[1][j] = (d[0][j-1] + d[0][j])%M;

	 	if ( i == p1 )
			for ( int j = 0; j <= i; j++ )
		 		q[0][j] = d[1][j];	 	                      	

	 	if ( i == p2 )
			for ( int j = 0; j <= i; j++ )
		 		q[1][j] = d[1][j];	 	                      	 

	 	if ( i == p3 )
			for ( int j = 0; j <= i; j++ )
		 		q[2][j] = d[1][j];	 	                      	

	 	for ( int j = 0; j <= i; j++ )
	 		d[0][j] = d[1][j];
	}
      
   	long long ans = 0;
    for ( int i = 0; i <= p2; i++ )
    	for ( int j = 0; j <= p2-i; j++ )
    		if (( p-1-i >= 0 ) && (m-p-j >= 0)) {
    			long long t = (long long)(q[1][i+j])*(long long)(q[0][p-1-i])%M;
    			t = (t*(long long)(q[2][m-p-j]))%M;

	   			ans = (ans + t)%M;
	   		}

	cout << ans << endl;
	return 0;
}
