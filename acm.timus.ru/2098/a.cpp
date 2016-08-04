#include <iostream>
#include <stdio.h>

using namespace std;

int x, c, d, n, p;

int main() {
    scanf("%d%d%d%d%d", &x, &c, &d, &n, &p);

    double cash = x + c*n + d*(((n+1)*n)/2);
    double no_cash = (c*n + d*(((n+1)*n)/2))*(1+(double)p/100);
    
    if ( cash < no_cash )
        printf("Cash\n%.7lf\n", no_cash - cash);
    else
        printf("Insurance\n%.7lf\n", cash - no_cash);

    return 0;
}

