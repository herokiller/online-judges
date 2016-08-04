#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int b[20], n, m, nt;

string s;
int main() {
    string sep = "+------------------------------+--------+-------------+";
    cout << sep << endl;
    printf("|Contest name                  |Date    |ABCDEFGHIJKLM|\n");
    cout << sep << endl;

    scanf("%d\n", &nt);
    
    for ( int t = 1; t <= nt; t++ ) {
        getline(cin, s);
        printf("|");
        cout << s;
        for ( int i = 1; i <= 30 - s.length(); i++ )
            cout << ' ';
    
        getline(cin, s);
        cout << '|' <<  s << '|';
        scanf("%d%d\n", &n, &m);
        memset(b, 0, sizeof(b));

        for( int i = 1; i <= m; i++ ) {
            char ch;
            scanf("%c ", &ch);
            int j = int(ch - 'A');
            getline(cin, s);
            if ( s == "Accepted" )
                b[j] = 1;
            else if ( b[j] == 0 )
                b[j] = -1;
        }

        for ( int i = 0; i < 13; i++ ) {
            if ( i > n-1 )
                cout << ' ';
            else if ( b[i] == 0 )
                cout << '.';
            else if ( b[i] == -1 )
                cout << 'x';
            else 
                cout << 'o';
        }
        cout << '|' <<  endl;
        cout << sep << endl;
    }
    return 0;
}

