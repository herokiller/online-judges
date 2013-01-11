#include <stdio.h>
#include <iostream>


#define N 10000

using namespace std;

struct btree {
	int val, l, r;
};

btree t[N];
int a[N], n, ans[N], nans;


void find(int p, int pos) {
	if ( t[pos].val > t[p].val ) 
		if ( t[p].r > 0 ) 
			find(t[p].r, pos);
		else 
			t[p].r = pos; 
	else 
	   	if ( t[p].l > 0 ) 
	   		find(t[p].l, pos);
	   	else
	   		t[p].l = pos;
}

void dfs(int p) {
	ans[nans] = t[p].val;
	nans++;

	if (t[p].l > 0)
		dfs(t[p].l);

	if (t[p].r > 0)
		dfs(t[p].r);
}

int main() {
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    	scanf("%d", &a[i]);
	
	for ( int i = n-1; i >= 0; i-- ) {
		if ( i == n-1 ) {
			t[n-i-1].val = a[i];
		} else {
			t[n-i-1].val = a[i];
		    find(0, n-i-1);
		}
	}

	dfs(0);

	for ( int i = nans - 1; i >= 0; i-- ) 
		printf("%d ", ans[i]);

}
