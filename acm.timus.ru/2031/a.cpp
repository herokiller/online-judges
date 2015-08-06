#include <iostream>
#include <stdio.h>

using namespace std;

string s[5];
int n;

int main() {
    scanf("%d", &n);
    s[1] = "16";
    s[2] = "06";
    s[3] = "68";
    s[4] = "88";
    if ( n > 4 ) {
        printf("Glupenky Pierre\n");
    } else {
        for ( int i = 1; i <= n; i++ )
            cout << s[i] << ' ';
    }
    return 0;
}

