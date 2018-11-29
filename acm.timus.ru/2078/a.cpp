#include <iostream>
#include <stdio.h>

using namespace std;

int ans1, ans2, a[20];

int main() {
    for ( int i = 1; i <= 10; i++ ) {
        scanf("%d", &a[i]);
        ans1 += a[i];
        ans2 += a[i];
        if (( i - 1 >= 1 ) && ( a[i-1] == 10 )) {
            if ( i == 10 )
                if ( a[i] > 20 )
                    ans1 += 10;

            ans2 += min(a[i], 20);
        }

        if (( i - 2 >= 1 ) && ( a[i-2] == 10 ) && (a[i-1] == 10))
            ans2 += min(10, a[i]);
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}

