#include <iostream>
#include <stdio.h>

using namespace std;

string s1, s2;
int n;

int check(string s1, string s2, int turn) {
    int n = s1.length(), acnt = 0, bcnt = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( s1[i] == 'A' )
            acnt++;
        else
            bcnt++;

        if ( s2[i] == 'A' )
            acnt++;
        else
            bcnt++;
    }
    if ( bcnt == 0 ) { 
        return 1;
    }
    if ( acnt == 0 ) {
        return -1;
    }
    if ( n%2 != 0 ) 
        return 0;

    string st1 = "", st2 = "";
    for ( int i = 0; i < n/2; i++ )
        st1 += s1[i];
    for ( int i = n/2; i < n; i++ )
        st2 += s1[i];

    int ch1 = check(st1, st2, (turn+1)%2);
    
    st1 = ""; st2 = "";
    for ( int i = 0; i < n/2; i++ ) 
        st1 += s2[i];
    for ( int i = n/2; i < n; i++ )
        st2 += s2[i];
    
    int ch2 = check(st1, st2, (turn+1)%2);

    if ( turn == 0 ) {
        return (max(ch1, ch2));
    } else {
        return (min(ch1, ch2));
    }
}

int main() {
    scanf("%d\n", &n);
    getline(cin, s1);
    getline(cin, s2);

    int ans = check(s1, s2, 0);
    if ( ans == 1 ) {
        printf("Alice\n");
    } else if ( ans == 0 ) {
        printf("Draw\n");
    } else {
        printf("Bob\n");
    }
    return 0;
}

