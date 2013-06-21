#include <stdio.h>

using namespace std;

int n, t, s, x;

int main() {
    scanf("%d%d%d", &n, &t, &s);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &x);
        double y = (t+s+x)/(double)2;
        printf("%.6lf\n", y);
    }
    return 0;
}

