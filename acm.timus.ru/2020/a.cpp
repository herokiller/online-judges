#include <iostream>
#include <stdio.h>

using namespace std;

string s1, s2;

int main() {
    getline(cin, s1);
    getline(cin, s2);
    int n1 = s1.length(), n2 = s2.length(), i1 = 0, i2 = 0, ans = 0;

    while ((i1 < n1) || (i2 < n2)) {
        if ( i1 < n1 ) {
            if ( i2 < n2 ) {
                if (( s1[i1] == 'L' ) && ( (s2[i2] == 'R') || ( s2[i2] == 'F'))) {
                    i2++;
                } else if  (( s2[i2] == 'L' ) && ( (s1[i1] == 'R') || ( s1[i1] == 'F'))) {
                    i1++;
                } else {
                    i1++;
                    i2++;
                }
            } else {
                i1++;
            }
        } else if ( i2 < n2 ) {
            i2++;
        } else {
            break;
        }
        ans++;
    }

    printf("%d\n", ans);
}

