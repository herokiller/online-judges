#include <iostream>
#include <stdio.h>

#define MAXK 310

using namespace std;

int d[3][2][MAXK], s[3][2], n, k1, k2;


int main() {
    scanf("%d%d%d", &n, &k1, &k2);

    d[1][0][0] = 1;
    d[1][1][0] = 1;
    int M = 1000*1000*1000+7;
    for ( int i = 1; i <= n; i++ ) {
        s[2][0] = 0;
        s[2][1] = 0;
        
        for ( int j = 1; j <= k1; j++ ) {
            d[2][0][j] = d[1][0][j-1];
            if ( j == 1 )
                d[2][0][j] = (d[2][0][j] + s[1][1])%M;

            s[2][0] = (s[2][0] + d[2][0][j])%M;
        }

        for ( int j = 1; j <= k2; j++ ) {
            d[2][1][j] = d[1][1][j-1];
            if( j == 1 ) 
                d[2][1][j] = (d[2][1][j] + s[1][0])%M; 
            
            s[2][1] = (s[2][1] + d[2][1][j])%M;
        }

        
        for ( int j = 0; j <= k1; j++ )
            d[1][0][j] = d[2][0][j];

        for ( int j = 0; j <= k2; j++ ) 
            d[1][1][j] = d[2][1][j];


        s[1][0] = s[2][0];
        s[1][1] = s[2][1];
    }
    
    cout << (s[2][0] + s[2][1])%M << endl;
    return 0;
}

