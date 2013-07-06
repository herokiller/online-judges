#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

struct help {
	int v, p;
	char pos;
};

help h[10010];

bool comp(help x, help y) {
	return x.v < y.v;
}

struct mass {
	int l, r, p, pos;
};

struct dset {
	int c, h, next, nextp;
};

mass a[5010];
dset d[10010];
int n, k;
char s[100];

int getParent(int x) {
	while ( d[x].next > 0 )
		x = d[x].next;

	return x;
}

int getParentp(int x) {
	int k = 0;
	while ( d[x].next > 0 ) {
		k = (k + d[x].nextp)%2;
		x = d[x].next;
	}

	return k;
}

void update(int from, int to) {

	int k = 0, x = from;
	while ( d[x].next > 0 ) {
		k = (k + d[x].nextp)%2;
		x = d[x].next;
	} 

	x = from;
	while ( d[x].next > 0) {
		int y = d[x].next;
		int k1 = d[x].nextp;
		d[x].next = to;
		d[x].nextp = k;
		x = y;
		k = (k + k1)%2;
	}
}

int main() {

	while (true) {
		scanf("%d", &k);
		if ( k == -1 ) 
			return 0;
		
		scanf("%d", &n);

		
		if ( n == 3 ) n++;
		
		int nh = 0;

		for ( int i = 1; i <= n; i++ ) {
			a[i].pos = i;
			scanf("%d %d ", &a[i].l, &a[i].r);
			a[i].r++;

			nh++;
			h[nh].v = a[i].l;
			h[nh].p = i;
			h[nh].pos = 'l';

			nh++;
			h[nh].v = a[i].r;
			h[nh].p = i;
			h[nh].pos = 'r';

			gets(s);
			if ( s[0] == 'o' )
				a[i].p = 1;
			else
				a[i].p = 0;
		}

		sort(h+1, h+nh+1, comp);
		
		int t = 0;
		for ( int i = 1; i <= nh; i++ ) {
			if ( h[i].v != h[i-1].v )
				t++;

           	if ( h[i].pos == 'l' )
           		a[h[i].p].l = t;
           	else 
           		a[h[i].p].r = t;
		}	

		

		bool ok = false;
		int color = 0;

		memset(d, 0, sizeof(d));

		for ( int i = 1; i <= n; i++ ) {
			int l = a[i].l, r = a[i].r;
			int lp = getParent(l), rp = getParent(r);
			int p1, p2;

			if ((d[lp].c == 0) && (d[rp].c == 0)) {
				color++;
				d[lp].c = color;
				d[rp].nextp = a[i].p;

				d[rp].next = lp;
				d[lp].h = 1;
				continue;
			}

			if ((d[lp].c != 0) && (d[rp].c == 0)) {
				p1 = getParentp(l);
				d[rp].next = lp;
				d[rp].nextp = (p1 + a[i].p)%2;
				continue;
			}

			if ((d[lp].c == 0) && (d[rp].c != 0)) {
				p2 = getParentp(r);
				d[lp].next = rp;
				d[lp].nextp = (p2 + a[i].p)%2;
				continue;
			}

			if  ((d[lp].c != 0) && (d[rp].c != 0) &&  (d[lp].c == d[rp].c)) {

				p1 = getParentp(l);
				p2 = getParentp(r);

				if (((p1 + p2)%2) == a[i].p)
					continue;
				else {
					ok = true;
					printf("%d\n", i-1);
					break;
				}
			}

			if ((d[lp].c != 0) && (d[rp].c != 0) && (d[lp].c != d[rp].c)) {
				p1 = getParentp(l);
				p2 = getParentp(r);
				

				if ( d[lp].h < d[rp].h ) {
					d[lp].next = rp;
					d[lp].nextp = (p1 + p2 + a[i].p)%2;

					update(l, rp);
					update(r, rp);

				} else {
					d[rp].next = lp;
					d[rp].nextp = (p1 + p2 + a[i].p)%2;
					if ( d[lp].h == d[rp].h )											
						d[rp].h++;

					update(l, lp);
					update(r, lp);
				}		        
			}
					
		}

		if ( !ok ) 
			printf("%d\n", n);
	}

	return 0;
}
