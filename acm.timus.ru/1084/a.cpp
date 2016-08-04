#include <stdio.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

double x, r, ans;

int main() {
    scanf("%lf%lf", &x, &r);

    double a = x/2;
    if ( r <= a  ) {
        ans = PI*r*r;
    } else if ( r >= a*sqrt(2) ) {
        ans = x*x;
    } else {
        double c = acos(a/r);
        double d = PI/2 - c*2;
        ans = r*r*(d*2/PI)*PI + 4*r*a*sin(c);
    }

    printf("%.5lf\n", ans);
    return 0;
}

