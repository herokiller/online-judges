#include <iostream>
#include <algorithm>
#include <stdio.h>

#define N 200200

using namespace std;

int a[N], b[N], n;
long long p[40];

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) 
        scanf("%d", &a[i]);
    
    sort(a+1, a+n+1);

    int l = 1, k = 0;

    for ( int i = 1; i <= n; i++ ) {
        if ( a[i] != a[i+1] ) {
            k++;
            b[k] = i-l+1;
            l = i+1;
        }
    }

    sort(b+1, b+k+1);
    
    p[0] = 1;
    for ( int i = 1; i <= 32; i++ )
        p[i] = p[i-1]*(long long)2;
  
  /*
    for ( int i = 1; i <= k; i++ )
        cout<< b[i] << ' ';
    cout << endl;
*/
    int ans = b[k], sum = b[k];

    for ( int i = k-1; i >= 1; i-- ) {
        
        int x = min(b[i], b[i+1]/2);
        b[i] = x;
//        cout << x << ' ' << p[k-i+1] - 1 << endl;
        if (x*(p[k-i+1] - 1) > ans )
            ans = x*(p[k-i+1] - 1);

        //else
        //    break;

    }

    cout << ans << endl;
    return 0;
}

