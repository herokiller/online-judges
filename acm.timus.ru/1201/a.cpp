#include <iostream>
#include <stdio.h>

using namespace std;

int d, m, y, wd, i0, j0;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[7][10], t;
string dnames[7] = {"mon", "tue", "wed", "thu", "fri", "sat", "sun"};

bool leapYear(int y) {
    return ((y%400 == 0) || ((y%100 != 0) && (y%4 ==0)));
}

int main() {
    scanf("%d%d%d", &d, &m, &y);

    int d0 = 1, m0 = 1, y0 = 1599, w0 = 4;

    while (y0 <= y) {
        d0++;
        w0 = (w0 + 1)%7;

        int md = days[m0];
        if ( leapYear(y0) && (m0 == 2))
            md++;

        if ( d0 > md ) {
            d0 = 1;
            m0++;
            if ( m0 > 12 ) {
                m0 = 1;
                y0++;
            }
        }

        if ( ( m0 == m ) && ( y0 == y) ) {
            if ( d0 == d ) {
                i0 = w0;
                j0 = t;
            }
            ans[w0][t] = d0;
            if (( w0 == 6 ) && ( d0 < md)) {
                t++;
            }
        }
    }

    for ( int i = 0; i < 7; i++ ) {
        cout << dnames[i];
        
        for ( int j = 0; j <= t; j++ ) {
            if (( i == i0 ) && ( j == j0)) {
                if ( j > 0 )
                    printf(" ");
                printf(" [");
                if ( ans[i][j] < 10 )
                    printf(" ");
                printf("%d]", ans[i][j]);
                continue;
            }
            
            if ( j > 0 )
                printf(" ");
            if ( ans[i][j] < 10 )
                printf(" ");
            if (( j > 0 ) && (i == i0 ) && (j-1 == j0))
                printf(" ");
            else 
                printf("  ");

            if (ans[i][j] == 0) 
                printf(" ");
            else
                printf("%d", ans[i][j]);
        }
        printf("\n");

    }
    return 0;
}

