#include <stdio.h>

using namespace std;

int a[111][111], n, m, ans, ii, jj;

int main() {
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            scanf("%d", &a[i][j]);

    ans = n;
    ii = 1; 
    jj = 2;
    for ( int i = 1; i <= m; i++ ) 
        for ( int j = i+1; j <= m; j++ ) {
            int p1 = 0, p2 = 0, p3 = 0, p4 = 0, m = 0;

            for ( int k = 1; k <= n; k++ ) {
                if ((a[k][i] == 1) && (a[k][j] == 1))
                    p1++;
                else if ((a[k][i] == 1) && (a[k][j] != 1))
                    p2++;
                else if ((a[k][i] != 1) && (a[k][j] == 1)) 
                    p3++;
                else
                    p4++;
            }

            if (p1 > m) 
                m = p1;
            if (p2 > m)
                m = p2;
            if (p3 > m)
                m = p3;
            if (p4 > m)
                m = p4;

            if ( m < ans ) {
                ans = m;
                ii = i;
                jj = j;
            }

        }

    printf("%d\n%d %d\n", ans, ii, jj);

    return 0;
}

