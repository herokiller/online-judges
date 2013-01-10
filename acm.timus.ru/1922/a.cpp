#include <stdio.h>
#include <algorithm>

#define N 1050

using namespace std;

int n;
bool b[N];

struct mass {
	int val, pos;
};

mass a[N];

bool comp(mass A, mass B) {
	return (A.val < B.val);
}

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &a[i].val);
		a[i].pos = i;
	}

	sort(a+1, a+n+1, comp);

	int ans = 0;
	
	for ( int i = 1; i <= n; i++ )
		if (( a[i].val <= i ) && ((i == n) || (a[i+1].val > i+1))) {
			b[i] = true;
			ans++;			
		}
		

	printf("%d\n", ans);
	for ( int i = 1; i <= n; i++ )
		if ( b[i] ) {
			printf("%d ", i);
			for ( int j = 1; j <= i; j++ )
				printf("%d ", a[j].pos);
			printf("\n"); 
		}

	return 0;
}
