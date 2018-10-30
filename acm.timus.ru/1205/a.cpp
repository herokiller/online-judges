#include <iostream>
#include <stdio.h>
#include <cmath>

#define N 222

using namespace std;

struct point {
    double x, y;
};

point p[N], A, B;
bool b[N];
int n, pre[N];
double vslow, vfast, a[N][N], d[N];

double dist(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    scanf("%lf%lf", &vslow, &vfast);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) 
        scanf("%lf%lf", &p[i].x, &p[i].y);
    
    for ( int i = 0; i <= n+1; i++ )
        for ( int j = 0; j <= n+1; j++ )
            a[i][j] = -1;

    int x = 1, y = 1;
    while ((x != 0) || (y != 0)) {
        scanf("%d%d", &x, &y);
        if (( x == 0 ) && ( y == 0 ))
            break;
        a[x][y] = dist(p[x], p[y])/vfast;
        a[y][x] = dist(p[x], p[y])/vfast;
    }
    
    scanf("%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y);
    p[0] = A;
    p[n+1] = B;
    
    for ( int i = 0; i <= n+1; i++ ) {
        for ( int j = 0; j <= n+1; j++ ) {
            if ( i != j )
                if ( a[i][j] == -1 ) {
                    a[i][j] = dist(p[i], p[j])/vslow;
                }
        }
    }
   /* 
    for ( int i = 0; i <= n+1; i++ ) {
        for ( int j = 0; j <= n+1; j++ )
            cout << a[i][j] << ' ';
        cout << endl;
    }
*/
    for ( int i = 0; i <= n+1; i++ )
        d[i] = -1;
    d[0] = 0;

    int mp = 0, m = d[0];

    while (mp != -1) {
        b[mp] = 1;

        for ( int i = 0; i <= n+1; i++ ) {
            if (a[mp][i] != -1 )
                if ((d[mp] + a[mp][i] < d[i] ) || (d[i] == -1)) {
                    d[i] = d[mp] + a[mp][i];
                    pre[i] = mp;
                }
        }

        mp = -1;
        for ( int i = 0; i <= n+1; i++ ) {
            if ((!b[i]) && (d[i] != -1))
                if ((d[i] < m ) || (mp == -1)) {
                    m = d[i];
                    mp = i;
                }
        }

    }

    int path[N], np = 0, k = n+1;
    
    while (k != 0) {
        np++;
        path[np] = k;
        k = pre[k];
    }
    
    printf("%.15lf\n", d[n+1]);

    printf("%d ", np-1);
    for ( int i = np; i >= 2; i-- ) 
        printf("%d ", path[i]);

    return 0;
}

