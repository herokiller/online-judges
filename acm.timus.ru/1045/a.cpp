#include <iostream>
#include <stdio.h>

using namespace std;

struct edge {
	int v, next;
};

edge e[2000];
int n, s, head[2000], k;
bool b[2000], d[2000];

void dfs(int v) {
	b[v] = 1;

	bool win = 0;
	
	for ( int i = head[v]; i > 0; i = e[i].next ) {
		if ( !b[e[i].v] ) {
			dfs(e[i].v);
			if ( d[e[i].v] == 0 ) 
				win = 1;
		}	
	}

	d[v] = win;
}

int main() {
	scanf("%d%d", &n, &s);
	for ( int i = 1; i <= n-1; i++ ) {
		int x, y;
		scanf("%d%d", &x, &y);
		k++;
		e[k].v = y;
		e[k].next = head[x];
		head[x] = k;

		k++;
		e[k].v = x;
		e[k].next = head[y];
		head[y] = k;
	}
	
	dfs(s);

	if ( !d[s] ) {
		printf("First player loses");
	} else {
		int x = 0;
		for ( int i = head[s]; i > 0; i = e[i].next ) 
			if (( !d[e[i].v] ) && ((x == 0) || ( e[i].v < x)) ) 
				x = e[i].v;                                 

		printf("First player wins flying to airport %d", x);
	}


	return 0;
}
