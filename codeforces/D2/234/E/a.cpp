#include <iostream>
#include <stdio.h>

#define MAXN 100100
#define M 1000000007

typedef long long ll;

using namespace std;

bool a[MAXN][50];
int b1[MAXN][50], b2[MAXN][50], n, m;

int main() {
	scanf("%d%d", &n, &m);
	long long ans = 0;

	for ( int i = 1; i <= n+m; i++ ) {
		int x, y;
		long long d = 1;

		if ( i <= n) {
			scanf("%d", &y);
			x = i;
		} else {
			scanf("%d%d", &x, &y);
		}
					
		
		for ( int j = 0; j <= 30; j++ ) {
			if ((!a[x][j]) && ((y >> j)&1)) {
				if ((b2[x-1][j] > 0) && (b1[x+1][j] > 0)) {
					int p1 = b2[x-1][j], p2 = x-1, p3 = x+1, p4 = b1[x+1][j];
					b1[p1][j] = p4; b2[p4][j] = p1; b2[p2][j] = 0; b1[p3][j] = 0;

					long long add = ((p2-p1+p4-p3+3)*(p2-p1+p4-p3+4)/2)%M;
					long long dec = ((p2-p1+1)*(p2-p1+2)/2 + (p4-p3+1)*(p4-p3+2)/2)%M;

					ans = (ans + add - dec)%M;
					if ( ans < 0 )
						ans += M;

                } else if (b2[x-1][j] > 0) {
                	int p1 = b2[x-1][j], p2 = x-1;

                	b1[p1][j] = x;
                	b2[x][j] = p1;
                	b2[p2][j] = 0;

                	long long add = p2 - p1 + 1;
                	ans = (ans + add)%M;
                } else if (b1[x+1][j] > 0) {
                   	int p3 = x+1;
                   	int p4 = b1[x+1][j];

                   	b1[x][j] = p4;
                   	b1[x+1][j] = 0;
                   	b2[p4][j] = x;

                   	long long add = p4 - p3 + 1;
                   	ans = (ans + add)%M;
                } else {
                	b1[x][j] = x;
                	b2[x][j] = x;

                	ans = (ans+1)%M;
                }
			} else if ((a[x][j]) && (!((y >> j)&1))) {
				if ((b2[x-1][j] > 0) && (b1[x+1][j] > 0)) {
				   	int p1 = b2[x-1][j], p2 = x-1, p3 = x+1, p4 = b1[x+1][j];
					b1[p1][j] = p2; b2[p2][j] = p1; b1[p3][j] = p4; b2[p4][j] = p3;

					long long add = ((p2-p1+1)*(p2-p1+2)/2 + (p4-p3+1)*(p4-p3+2)/2)%M;
					long long dec = ((p2-p1+p4-p3+3)*(p2-p1+p4-p3+4)/2)%M;

					ans = (ans + add - dec)%M;
					if ( ans < 0 )
						ans += M;
					
				} else if (b2[x-1] > 0) {
                	int p1 = b2[x-1][j], p2 = x-1;

                	b1[p1][j] = p2;
                	b2[p2][j] = p1;
                	b2[x][j] = 0;

                	long long dec = p2 - p1 + 1;
                	ans = (ans - dec)%M;
                	if ( ans < 0)
                		ans += M;

				} else if (b1[x+1] > 0) {
                   	int p3 = x+1, p4 = b1[x+1][j];

                   	b1[p3][j] = p4;
                   	b2[p4][j] = x;
                   	b1[x][j] = 0;
                   	
                   	long long dec = p4 - p3 + 1;
                   	ans = (ans - dec)%M;
                   	if ( ans < 0 )
                   		ans += M;
	
				} else {
					b1[x][j] = 0;
					b2[x][j] = 0;

					ans = (ans-1)%M;
					if ( ans < 0 )
						ans += M;
				}
			}

			d = (d*10)%M;
		}

//		if ( ans > n ) 
			printf("ans: %I64d\n", ans);
	}

}
