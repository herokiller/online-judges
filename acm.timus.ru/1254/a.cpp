#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 80

using namespace std;

struct point {
    int i, j;
};

point q[N*N*N];
int n, m, nt, nq, i0, j0;
int di[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1};
double v, ans, d[N][N];
char a[N][N];

bool inside(int i, int j) {
    return ((i >= 1) && (i <= n) && (j >= 1) && (j <= m));
}


int main() {
    scanf("%d%d%d%lf\n", &m, &n, &nt, &v);
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) 
            scanf("%c", &a[i][j]);
        scanf("\n");
    }
    double dv[8] = {1.0, 1.0, 1.0, 1.0, 1.414213562, 1.414213562, 1.414213562, 1.414213562};
    scanf("%d%d", &j0, &i0);
    for ( int t = 1; t <= nt; t++ ) {
        int x, y;
        scanf("%d%d", &y, &x);
        if (( x == i0 ) && ( y == j0 ))
            continue;
        memset(d, 0, sizeof(d));
        int i = 0;
        nq = 1;
        q[1].i = i0;
        q[1].j = j0;
        
        bool ok = 0;
        while ( i < nq ) {
            i++;
            
            for ( int j = 0; j < 8; j++ ) {
                int i2 = q[i].i + di[j];
                int j2 = q[i].j + dj[j];

                if ((i2 == i0) && (j2 == j0))
                    continue;

                if ((inside(i2, j2)) && ( a[i2][j2] == '.' ) && 
                    (( d[q[i].i][q[i].j] + dv[j] < d[i2][j2] ) || d[i2][j2] == 0)) {
                    nq++;
                    q[nq].i = i2;
                    q[nq].j = j2;
                    d[i2][j2] = d[q[i].i][q[i].j] + dv[j];
                }
            }
        }
        

        if ( d[x][y] == 0 ) {
            continue;
        } else {
            ans += d[x][y]/v;
            i0 = x;
            j0 = y;
        }
        //printf("%.5lf\n", ans);
    }

    printf("%.5lf\n", ans);
    return 0;
}

