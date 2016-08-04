#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

string s;
int n, ans1, ans2;
map <string, bool> a1;
map <string, bool> a2;

int main() {
    scanf("%d\n", &n);
    for ( int i = 1; i <= n; i++ ) {
        cin >> s;
        char ch = getchar();
        string r;
        getline(cin, r);
        if (( r == "AC" ) || ( r == "WA 6" ) || (r == "TL 6") || (r == "ML 6")
            || (r == "WA 7") || (r == "TL 7") || (r == "ML 7")) {
            if ( a2[s] == 0 ) {
                ans2++;
                a2[s] = 1;
            }
        }

        if  ((r == "WA 7") || (r == "TL 7") || (r == "ML 7")) {
            if ( a1[s] == 0 ) {
                ans1++;
                a1[s] = 1;
            }
        }
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}

