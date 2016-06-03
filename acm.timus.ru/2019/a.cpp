#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct st {
    int pos, k;
};

char a[10000];
int n, ans[10000], nans, ns;

st s[10000];

bool low(char ch) {
    return ((int(ch - 'a') >= 0) && (int('z' - ch) >= 0));
}

bool up(char ch) {
    return ((int(ch - 'A') >= 0) && (int('Z' - ch) >= 0));
}

bool match(char ch1, char ch2) {
    return (abs(int(ch1 - ch2)) == 32);
}

int main() {
    scanf("%d\n", &n);
    n *= 2;
    for ( int i = 1; i <= n; i++ )
        scanf("%c", &a[i]);

    ns = 0;
    int k1 = 0, k2 = 0;
    for ( int i = 1; i <= n; i++ ) {
        if (low(a[i])) {
            k1++;
            if (( ns > 0 ) && (match(a[i], a[s[ns].pos]))) {
                ans[s[ns].k] = k1;
                ns--;
            } else {
                ns++;
                s[ns].pos = i;
                s[ns].k = k1;
            }
        } else {
            k2++;
            if (( ns > 0 ) && (match(a[i], a[s[ns].pos]))) {
                ans[k2] = s[ns].k;
                ns--;
            } else {
                ns++;
                s[ns].pos = i;
                s[ns].k = k2;
            }
        }
    }

    if ( ns == 0 ) {
        for ( int i = 1; i <= n/2; i++ )
            printf("%d ", ans[i]);
    } else {
        printf("Impossible\n");
    }
    return 0;
}

