#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100100

using namespace std;

int a[N], f[N], t[N], n, m, k, ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for ( int i = 1; i <= n; i++ ) 
        scanf("%d", &a[i]);
    
    int sum = 0, p = n;
    f[0] = 1;
    for ( int i = n; i >= 1; i-- ) {
        sum += a[i];
        while ((( sum > k ) || ( i == 1 )) && (p > 0)) {
            f[p] = i;
            sum -= a[p];
            p--;
        }
    }
/*
    for ( int i = 1; i <= n; i++ )
        cout << f[i] << ' ';
    cout << endl;
*/
    for ( int i = 1; i <= m; i++ )
        scanf("%d", &t[i]);
    sort(t+1, t+m+1);

    int ti = 1;
    p = 0;

    while (( ans + n - p >= t[ti] ) && ( ti <= m )) {
        p = p + t[ti] - ans - 1;
        p = f[p] - 1;
        ans = t[ti];
        ti++;
    }

    ans += n - p;

    printf("%d\n", ans);
    return 0;
}

