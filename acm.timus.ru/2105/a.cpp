#include <iostream>
#include <stdio.h>

using namespace std;

int l, t, v1, v2, n, ans, curt1, curt2;
long long d;

int main() {
    scanf("%d%d%d%d%d", &l, &t, &v1, &v2, &n);


    for ( int i = 1; i <= n; i++ ) {
        int x, ti, di;
        scanf("%d%d%d", &x, &ti, &di);
        if ( x == 1 ) {
            d += v1*(ti - curt1);
            curt1 = ti + di;
        } else {
            d += v2*(ti - curt2);
            curt2 = ti + di;
        }

        ans += d/l;
        d %= l;
    }

    d += v1 * (t - curt1) + v2 * (t - curt2);
    ans += d/l;

    printf("%d\n", ans);

    return 0;
}

