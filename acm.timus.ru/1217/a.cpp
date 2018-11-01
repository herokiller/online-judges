#include <iostream>
#include <stdio.h>

#define N 12

using namespace std;

long long ans;
int d[N][N*9][N*9], n;

int main() {
    scanf("%d", &n);
    d[0][0][0] = 1;
    for ( int i = 1; i <= n/2; i++ )
        for ( int j = 0; j <= i*9; j++ )
            for ( int k = 0; k <= ((i/2)+1)*9; k++ ) 
                for ( int l = 0; l <= 9; l++ ) {
                    if ((i%2 == 0) && (j-l >= 0))
                        d[i][j][k] += d[i-1][j-l][k];
                    
                    if ((i%2 == 1) && (j-l >= 0) && (k-l >= 0)) 
                        d[i][j][k] += d[i-1][j-l][k-l];
                }

    for ( int i = 0; i <= (n/2)*9; i++ )
        for ( int j = 0; j <= (n/2)*9; j++ )
            ans += ((long long)d[n/2][i][j] * (long long)d[n/2][i][j]);
    
    cout << ans << endl;

    return 0;
}

