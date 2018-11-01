#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 111

using namespace std;

struct data {
    int l, r;
};

data a[N];
int d[N], n;

bool comp(data x, data y) {
    return (x.l < y.l );
}


int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
        scanf("%d%d", &a[i].l, &a[i].r);

    sort(a+1, a+n+1, comp);

    int ans = n;

    for ( int i = 1; i <= n; i++ ) {
        d[i] = 1;
        for ( int j = i-1; j >= 1; j-- ) 
            if (( a[j].l < a[i].l ) && ( a[j].r < a[i].r ) && (d[j] + 1 > d[i]))
                d[i] = d[j] + 1;
        if ( n - d[i] < ans )
            ans = n - d[i];
    }

    printf("%d\n", ans);
    return 0;
}

