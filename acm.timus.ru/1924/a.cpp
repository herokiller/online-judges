#include <stdio.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int x = (n*(n+1))/2;

    if ( x%2 == 0 )
        printf("black\n");
    else 
        printf("grimy\n");

    return 0;
}

