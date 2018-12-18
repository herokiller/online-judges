#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100100

using namespace std;

struct data {
    int v, p;
};

data a[N];
int n;

bool comp(data a, data b) {
    return ((a.v < b.v) || ((a.v == b.v) && (a.p < b.p)));
}

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &a[i].v);
        a[i].p = i;
    }

    sort(a+1, a+n+1, comp);
    
    long long vl = 0, vr = 0;
    int l = 1, r = 1, v = 0;

    for ( int i = 1; i <= n; i++ ) {
        int l1, r1;
        long long vl1, vr1;
        if ( a[i].v > v ) {
            v = a[i].v;
            l1 = a[i].p;

            for ( int j = i; j <= n; j++ ) {
                if ( a[j].v != v ) {
                    i = j-1;
                    break;
                } else {
                    r1 = a[j].p;
                }
            }
            
            //
            vl1 = min(vl + (long long)abs(l - r1) + (long long)abs(r1 - l1), vr + (long long)abs(r - r1) + (long long)abs(r1 - l1));
            vr1 = min(vl + (long long)abs(l - l1) + (long long)abs(r1 - l1), vr + (long long)abs(r - l1) + (long long)abs(r1 - l1));
            l = l1;
            r = r1;
            vl = vl1;
            vr = vr1;
        }
    }

    if ( vl < vr )
        printf("%I64d\n", vl + (long long)n);
    else
        printf("%I64d\n", vr + (long long)n);

    return 0;
}

