#include <stdio.h>
#include <algorithm>
#include <iostream>

#define N 1010

using namespace std;

int a[N], n, v;

int main() {
    scanf("%d%d", &n, &v);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &a[i]);

    sort(a, a+n);

    int ans = 0, strikes = 0;
    
    for ( int i = 0; i < n;) {
        int curp = a[i], curk = 0;
        
        int k = 0;
        while (i+k <= n-1) {

            int p = a[i + k];

            for ( int j = i + k; j < n; j++ )
                if ( a[j] != p )
                    break;
                else 
                    k++;

            if (p*k > v) 
                break;
            else {
                curp = p;
                curk = k;
            }

            if ( i + k == n ) break;
        }
        if ( curk == 0 ) 
            break;
        else {
            ans += curk;
            strikes++;
            i += curk;
        }
    }

    printf("%d %d\n", ans, strikes);
        
    return 0;
}

