#include <iostream>
#include <stdio.h>
#define MAXN 300

using namespace std;

int b[MAXN], adv[MAXN], n, m;

int main() {
    int budget, alone1, alone2, rent, qual, rooms, maxAdv = -1, app = 0, f = 0;
    scanf("%d%d%d", &budget, &alone1, &alone2);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
        scanf("%d%d", &b[i], &adv[i]);

    scanf("%d", &m);
    for ( int i = 1; i <= m; i++ ) {
        scanf("%d%d%d", &rooms, &rent, &qual);
        if ( budget >= rent ) {
            int add;
            if ( rooms == 1 )
                add = alone1;
            else
                add = alone2;

            if ( add + qual > maxAdv ) {
                maxAdv = add + qual;
                app = i;
                f = 0;
            }
        }
        if (( budget >= rent/2 + rent%2 ) and (rooms == 2)) {
            for ( int j = 1; j <= n; j++ )
                if ( b[j] >= rent/2 + rent%2 )
                    if ( adv[j] + qual > maxAdv ) {
                        maxAdv = adv[j] + qual;
                        app = i;
                        f = j;
                    }
        }
    }

    if ( maxAdv == -1 ) {
    	printf("Forget about apartments. Live in the dormitory.\n");
    } else {
	if ( f == 0 ) {
		printf("You should rent the apartment #%d alone.\n", app);
	} else {
		printf("You should rent the apartment #%d with the friend #%d.\n", app, f);
	}
    }
    return 0;
}

