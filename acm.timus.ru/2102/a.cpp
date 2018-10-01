#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

long long n;
int ans;

int main() {
    cin >> n;
    long long k = 10000000;
    if ( n < k )
        k = n;

    for ( int i = 2; i <= k; i++ ) {
        while ( n%i == 0 ) {
            ans++;
            n /= i;
        }
    }

    if ( n > 1 ) {
        long long x = (long long)(sqrt(n));
        if (((x*x == n) && (ans == 18)) || (ans == 19))
            printf("Yes\n");
        else 
            printf("No\n");
    } else if (ans == 20) 
        printf("Yes\n");
    else 
        printf("No\n");

    return 0;
}

