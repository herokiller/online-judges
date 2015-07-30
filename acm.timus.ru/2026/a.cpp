#include <iostream>
#include <stdio.h>
#include <string.h>

#define N 100100

using namespace std;

char s[N];
int n, k;
bool b[30];

int main() {
    gets(s);
    scanf("%d", &k);
    n = strlen(s);
    
    for ( int i = 0; i < n; i++ ) {
        if ( s[i] != '?' ) {
            int index = s[i] - 'a';
            if ( !b[index] )
                k--;
            b[s[i] - 'a'] = 1;
        }
    }

    int l = 0, r = 25;
    while (( k > 0 ) && (l <= r)) {
        bool ok = 0;
        while (( b[l] ) && (l<=r))
            l++;
        while (( b[r] ) && (l<=r))
            r--;
        if ( l > r ) 
            break;
        if ( l < 25 - r ) {
            for ( int i = 0; i < n; i++ )
                if (( s[i] == '?' ) && (i%2 == 1)) {
                    b[l] = 1;
                    k--;
                    s[i] = char(int('a') + l);
                    ok = 1;
                    break;
                }
        } else {
            for ( int i = 0; i < n; i++ )
                if (( s[i] == '?' ) && (i%2 == 0)) {
                    b[r] = 1;
                    k--;
                    s[i] = char(int('a') + r);
                    ok = 1;
                    break;
                }
        }

        if (!ok)
            break;

    }

    if ( k > 0 ) {
        printf("-1\n");
        return 0;
    }

    for ( int i = 0; i < n; i++ ) 
        if ( s[i] == '?' )
            if ( i%2 == 0 )
                s[i] = 'z';
            else 
                s[i] = 'a';
    
    for ( int i = 0; i < n; i++ )
        printf("%c", s[i]);
    printf("\n");
    return 0;
}

