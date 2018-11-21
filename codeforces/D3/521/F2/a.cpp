#include <iostream>
#include <stdio.h>
#include <cmath>
//#include <math.h>
//#include <algorithm>

#define N 5005

using namespace std;

struct data {
    long long v, m;
};

data st1[N], st2[N];
long long a[N], d[N][N], mk[N];
int n, k, x;

void build2(long long a[]) {
    int n1 = 0, n2 = 0;
    for ( int i = 1; i <= n; i++ ) {
        long long m = 0;
        if ( n1 + n2 >= k ) {
            if ( n2 == 0 ) {
                for ( int j = n1; j >= 1; j-- ) {
                    n2++;
                    st2[n2].v = st1[j].v;
                    st2[n2].m = max(st2[n2].v, st2[n2-1].m);
                }
                n1 = 0;
            } 
            n2--;
        }
            
        n1++;
        st1[n1].v = a[i];
        st1[n1].m = max(a[i], st1[n1-1].m);
                    
        mk[i] = max(st1[n1].m, st2[n2].m);
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &x);

    for ( int i = 1; i <= n; i++ )
        scanf("%I64d", &a[i]);

    for ( int j = 1; j <= k; j++ )
        d[1][j] = a[j];
    
    build2(d[1]);

    for ( int i = 2; i <= x; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            long long m = mk[j-1];
            if (( m > 0 ) && (a[j] + m > d[i][j]))
                d[i][j] = a[j] + m;
        }
        
        build2(d[i]);
    }

    long long ans = -1;
    for ( int j = 1; j <= n; j++ )
        if (( d[x][j] > 0 ) && ( d[x][j] > ans ) && (n-j < k))
            ans = d[x][j];

    printf("%I64d\n", ans);
    return 0;
}

