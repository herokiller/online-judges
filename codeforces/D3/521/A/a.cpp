#include <iostream>
#include <stdio.h>

using namespace std;

int nt;

int main() {
    scanf("%d", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        long long a, b, k;
        cin >> a >> b >> k;
        long long ans = (a-b)*(k/2);
        if ( k%2 == 1 )
            ans += a;
        cout << ans << endl;
    }
    return 0;
}

