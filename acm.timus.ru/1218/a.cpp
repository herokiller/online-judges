#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 222

using namespace std;

struct data {
    char name[50];
    int x, y, z;
};

data d[N];
bool a[N][N], b[N];
int n, marked;

void dfs(int v) {
    b[v] = 1;
    marked++;
    for ( int i = 1; i <= n; i++ )
        if (( i != v ) && ( a[v][i] ) && (!b[i]))
            dfs(i);

    return;
}

void dfsrev(int v) {
    b[v] = 1;
    for ( int i = 1; i <= n; i++ )
        if ((i != v) && (!a[v][i]) && (!b[i]))
            dfsrev(i);

    return;
}

int main() {
    scanf("%d\n", &n);
    for ( int i = 1; i <= n; i++ ) 
        scanf("%s %d%d%d", d[i].name, &d[i].x, &d[i].y, &d[i].z);        
    

    for ( int i = 1; i <= n; i++ )
        for ( int j = i+1; j <= n; j++ ) {
            int k = 0;
            if ( d[i].x > d[j].x )
                k++;
            if ( d[i].y > d[j].y )
                k++;
            if ( d[i].z > d[j].z ) 
                k++;
            if ( k >= 2 )
                a[i][j] = 1;
            else
                a[j][i] = 1;
        }
    
    int w = 1;
    for ( int i = 1; i <= n; i++ ) {
        if (!b[i])
            dfs(i);
        if (marked == n) {
            w = i;
            break;
        }
    }
    memset(b, 0, sizeof(b));
    dfsrev(w);
    
    for ( int i = 1; i <= n; i++ )
        if (b[i])
            printf("%s\n", d[i].name);

    return 0;
}

