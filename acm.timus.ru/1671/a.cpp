#include <iostream>
#include <stdio.h>

#define N 100100

using namespace std;

struct edge {
    int x, y;
};

edge a[N];
bool b[N];
int h[N], p[N], d[N], ans[N], n, m, k, t;

void update(int v, int x) {
    while (p[v] != v) {
        int c = p[v];
        p[v] = x;
        v = c;
    }
    return;
}

int getPrev(int v) {
    while (p[v] != v) {
        v = p[v];
    }
    return v;
}

void merge(int x, int y) {
    int v1 = getPrev(x);
    int v2 = getPrev(y);
    if ( v1 == v2 )
        return;
    t--;
    int vx;
    if (h[v1] >= h[v2]) {
        vx = v1;
        p[v2] = v1;
        if (h[v1] == h[v2])
            h[v1]++;
    } else if (h[v1] < h[v2]) {
        vx = v2;
        p[v1] = v2;
    }
    update(x, vx);
    update(y, vx);
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ )
        p[i] = i;
    
    for ( int i = 1; i <= m; i++ )
        scanf("%d%d", &a[i].x, &a[i].y);

    scanf("%d", &k);
    for ( int i = 1; i <= k; i++ ) {
        scanf("%d", &d[i]);
        b[d[i]] = 1;
    } 

    t = n;
    for ( int i = 1; i <= m; i++ )
        if (!b[i])
            merge(a[i].x, a[i].y);

    for ( int i = k; i >= 1; i-- ) {
        ans[i] = t;
        int x = a[d[i]].x;
        int y = a[d[i]].y;
        merge(x, y);
    }

    for ( int i = 1; i <= k; i++ )
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
