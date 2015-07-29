#include <iostream>
#include <stdio.h>
#include <set>
#include <cmath>

using namespace std;

string names[3][9] = {
    {"Alice", "Ariel", "Aurora", "Phil", "Peter", "Olaf", "Phoebus", "Ralph", "Robin"}, 
    {"Bambi", "Belle", "Bolt", "Mulan", "Mowgli", "Mickey", "Silver", "Simba", "Stitch"}, 
    {"Dumbo", "Genie", "Jiminy", "Kuzko", "Kida", "Kenai", "Tarzan", "Tiana", "Winnie" }
};
set <string> a[3];
int n;

int main() {
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 9; j++ )
            a[i].insert(names[i][j]);

    int p = 0, ans = 0;
    scanf("%d\n", &n);
    string s;
    for ( int i = 0; i < n; i++ ) {
        getline(cin, s);
        if ( a[p].find(s) != a[p].end() ) {
            continue;
        } else {
            int pt = (p+1)%3;
            if ( a[pt].find(s) == a[pt].end() ) {
                pt = (pt+1)%3;
            }
            ans += abs(pt - p);
            p = pt;
        }
    }
    printf("%d\n", ans);
    return 0;
}
