#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define N 30100

using namespace std;

struct point {
    int i, j;
};

point q[30*100];
int n, m, k, nq, ans;
bool b[N];

bool inside(int i, int j) {
    return ((i >= 1) && (i <= n) && (j >= 1) && (j <= m));
}

bool comp(point a, point b) {
    return ((a.i < b.i) || ((a.i == b.i) && (a.j < b.j)));
}

bool comp2(point a, point b) {
    return ((a.j < b.j) || ((a.j == b.j) && (a.i < b.i)));
}

int main() {
    scanf("%d%d%d\n", &n, &m, &k);
    for ( int t = 1; t <= k; t++ ) {
        int x, y, l;
        char ch;
        scanf("%d%d%d %c\n", &y, &x, &l, &ch);
        if ( ch == 'V' ) {
            for ( int i = x-1; i <= x+l; i++ ) 
                for ( int j = y - 1; j <= y + 1; j++ )
                    if ( inside(i, j) ) {
                        nq++;
                        q[nq].i = i;
                        q[nq].j = j;
                    }
            
        }
        if ( ch == 'H' ) {
            for ( int j = y-1; j <= y+l; j++ )
                for ( int i = x-1; i <= x+1; i++ )
                    if ( inside(i, j) ) {
                        nq++;
                        q[nq].i = i;
                        q[nq].j = j;
                    }
        }
    }
    
    
    scanf("%d", &k);
    
    if ( m >= k )
        ans += (m-k+1)*n;
    if ( n >= k )
        ans += (n-k+1)*m;

    sort(q+1, q+nq+1, comp);
    int i0 = 0;
    bool ok;

    
    for ( int i = 1; i <= nq+1; i++ ) {
        if (( q[i].i > i0 ) || (i == nq+1)) {
            for ( int j = 1; j <= m-k+1; j++ ) {
                ok = 1;
                for ( int t = 0; t < k; t++ )
                    if ( b[j+t] )
                        ok = 0;
                
                if ( !ok ) 
                    ans--;
            }
            memset(b, 0, sizeof(b));
            i0 = q[i].i;
        }
        b[q[i].j] = 1;
    }

    sort(q+1, q+nq+1, comp2);

    int j0 = 0;
    memset(b, 0, sizeof(b));
    for ( int i = 1; i <= nq+1; i++ ) {
        if (( q[i].j > j0 ) || ( i == nq+1)) {
            for ( int j = 1; j <= n-k+1; j++ ) {
                ok = 1;
                for ( int t = 0; t < k; t++ )
                    if ( b[j+t])
                        ok = 0;

                if ( !ok )
                    ans--;
            }
            memset(b, 0, sizeof(b));
            j0 = q[i].j;
        }
        b[q[i].i] = 1;
    }
    
    if ( k == 1 )
        ans /= 2;
    printf("%d\n", ans);
    return 0;
}

