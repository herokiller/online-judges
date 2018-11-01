#include <iostream>
#include <stdio.h>

#define N 1010

using namespace std;

int gcd(int x, int y) {
    if ( y == 0 )
        return x;
    else
        return gcd(y, x%y);
}

struct data {
    int v1, v2;
};

data ans[N];
bool a[N][N], b[N];
int n, val[N], x, v0;

void dfs(int v, int turn) {
    b[v] = 1;

    int v1 = v0 * val[x];
    int v2 = val[v];
    int g = gcd(v1, v2);
    ans[v].v1 = v1/=g;
    if ( turn == 1 ) 
        ans[v].v1 *= -1;
    ans[v].v2 = v2/g;

    for ( int i = 1; i <= n; i++ )
        if ( !b[i] && a[v][i] )
            dfs(i, (turn+1)%2);
        
    return;
}

int main() {
    
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        ans[i].v1 = 0;
        ans[i].v2 = 1;
        scanf("%d", &val[i]);
        x = 1;
        while (x > 0) {
            scanf("%d", &x);
            if ( x == 0 )
                break;
            else
                a[i][x] = 1;
        }

    }
    scanf("%d%d", &x, &v0);

    dfs(x, 0);
    
    for ( int i = 1; i <= n; i++ )
        printf("%d/%d\n", ans[i].v1, ans[i].v2);
    
    return 0;
}

