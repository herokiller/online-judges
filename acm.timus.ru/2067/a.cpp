#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

#define N 200100

using namespace std;

/*
int gcd(int a, int b) {
    if ( b == 0 )
        return a;
    else
        return gcd(b, a%b);
}


const double e = 0.0000000000000001;
*/

struct point {
    int x, y, p;
};

point a[N];
int n;

bool comp(point a, point b) {
    return ((a.x < b.x) || ((a.x == b.x) && (a.y < b.y)));
}

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].p = i;
    }
    
    sort(a+1, a+n+1, comp);
    bool ok = 1;

    for ( int i = 2; i <= n-1; i++ ) {
    /*
        int x1 = a[i].x - a[i-1].x;
        int y1 = a[i].y - a[i-1].y;
        int x2 = a[i+1].x - a[i].x;
        int y2 = a[i+1].y - a[i].y;
    
        int g1 = gcd(x1, y1);
        int g2 = gcd(x2, y2);
        
        x1 /= g1;
        y1 /= g1;

        x2 /= g2;
        y2 /= g2;
*/
    
        double t1 = (double)(a[i].x - a[i-1].x)/(double)(a[i].y - a[i-1].y);
        double t2 = (double)(a[i+1].x - a[i].x)/(double)(a[i+1].y - a[i].y);
    

//        if ( (x1 != x2) || ( y1 != y2)) {
        //if ( fabs(t1 - t2) > e ) {
        if ( t1 != t2 ) {
            ok = 0;
            break;
        }
    }

    if ( ok ) {
        printf("1\n");
        printf("%d %d\n", a[1].p,  a[n].p);
    } else {
        printf("0\n");
    }
    return 0;
}

