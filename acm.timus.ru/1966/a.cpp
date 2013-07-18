#include <iostream>
#include <stdio.h>

using namespace std;

struct pt {
	long long x, y;
};

struct sgm {
	long long p1, p2;
};

pt a[300];
bool b[300];
sgm s[300];
int n, m, d[300][300];
long long q[300];

long long area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

int main() {
	scanf("%d%d", &n, &m);

	for ( int i = 1; i <= n; i++ ) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].x = (long long)x;
		a[i].y = (long long)y;
	}

	for ( int i = 1; i <= m; i++ ) {
		int p1, p2;
		scanf("%d%d", &p1, &p2);	
		s[i].p1 = (long long)p1;
		s[i].p2 = (long long)p2;
		d[s[i].p1][s[i].p2] = i;
		d[s[i].p2][s[i].p1] = i;
	}

	int nq = 1, i = 0;
	q[1] = 1;
	b[1] = 1;

	while (i < nq) {
		i++;
		for ( int j = 1; j <= n; j++ ) {
			if (( d[q[i]][j] > 0 ) && (!b[j])) {
				nq++;
				q[nq] = j;
				b[j] = 1;
			}
			
			int p = d[q[i]][j];

			if ( d[q[i]][j] > 0 ) {
				for ( int k = 1; k <= n; k++ )					
					if ((!b[k]) && ( intersect(a[s[p].p1], a[s[p].p2], a[k], a[k]) )){
						nq++;
						q[nq] = k;
						b[k] = 1;
					}

				for ( int k = 1; k <= m; k++ )
					if ( intersect(a[s[p].p1], a[s[p].p2], a[s[k].p1], a[s[k].p2]) ) {
						if (!b[s[k].p1]) {
							nq++;
							q[nq] = s[k].p1;
							b[s[k].p1] = 1;	
						}

						if (!b[s[k].p2]) {
							nq++;
							q[nq] = s[k].p2;
							b[s[k].p2] = 1;
						}
				   	}
		
			}			
		}	   	
	}

	if (nq == n )
		printf("YES\n");
	else 
		printf("NO\n");

	return 0;
}
