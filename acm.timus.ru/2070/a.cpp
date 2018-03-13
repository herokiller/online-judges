#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

long long l, r;

bool prime(int k) {
    for ( int i = 2; i <= (int)(sqrt(k)); i++ )
        if ( k%i == 0 ) 
            return false;
    return true;
}

int main() {
    scanf("%lld%lld", &l, &r);

    long long ans = r - l + 1;

    for (int i = 2; i <= (int)(sqrt(r)); i++ ) {
        if (prime(i)) {
            long long x = (long long)(i);
            int k = 1;
            while ( x <= r ) {
                x = x*(long long)(i);
                k++;
                if ( prime(k+1) && (l <= x) && (x <= r )) {
                    ans--;
//                    cout << i << ' ' << k << endl;
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}

