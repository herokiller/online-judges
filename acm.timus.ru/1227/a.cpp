#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 111

using namespace std;

struct edge {
    int v, next, w, num;
};

edge e[N*N*2];

struct data {
    int v, w;
};
data q[N];

int n, m, s, h[N], ne;
bool b[N], cycle;

void addEdge(int v1, int v2, int w) {
    ne++;
    e[ne].v = v2;
    e[ne].w = w;
    e[ne].num = ne;
    e[ne].next = h[v1];
    h[v1] = ne;

    ne++;
    e[ne].v = v1;
    e[ne].w = w;
    e[ne].num = ne-1;
    e[ne].next = h[v2];
    h[v2] = ne;

    return;
}

void dfs(int v, int num) {
    b[v] = 1;    
    int i = h[v];

    while ( i > 0 ) {
        int vto = e[i].v;
        if ((b[vto]) && (num != e[i].num)) {
            cycle = 1;
            return;
        }

        if ((!b[vto]) && (num != e[i].num)) 
            dfs(vto, e[i].num);
        
        i = e[i].next;
    }
    
    return;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for ( int i = 1; i <= m; i++ ) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        addEdge(x, y, w);
    }


    for ( int i = 1; i <= n; i++ )
        if (!b[i]) 
            dfs(i, 0);


    if (cycle) {
        printf("YES\n");
        return 0;
    }

    int m = 0;
    for ( int i = 1; i <= n; i++ ) {
        memset(b, 0, sizeof(b));
        int nq = 1, j = 0;
        q[1].v = i;
        q[1].w = 0;
        b[i] = 1;

        while ( j < nq ) {
            j++;
            int k = h[q[j].v];
            while ( k > 0 ) {
                int vto = e[k].v;
                if ( !b[vto] ) {
                    b[vto] = 1;
                    nq++;
                    q[nq].v = vto;
                    q[nq].w = q[j].w + e[k].w;
                    if ( q[nq].w > m )
                        m = q[nq].w;
                }

                k = e[k].next;
            }
        
        }

    }
    
    if ( m >= s ) 
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

