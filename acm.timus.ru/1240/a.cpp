#include <iostream>
#include <stdio.h>

#define N 14

using namespace std;

int l[10], n, hp, mp, hpm, k, vm, heal, nans;

struct data {
    int dmg;
    char action;
    int p;
    int i, j;
};

data ans[60];

data d[60][N][111];
bool b[60][N][111];

int main() {
    scanf("%d%d%d%d%d%d%d", &n, &hp, &mp, &hpm, &k, &vm, &heal);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &l[i]);

    
    b[0][n][hp] = 1;
    d[0][n][hp].dmg = 0;
    d[0][n][hp].action = ' ';

    for ( int m = 0; m < mp; m++ ) {
        bool ok = 0;
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= hp; j++ ) {
                if ( b[m][i][j] ) {
                    ok = 1;
                    int h = j;
                    int p = i;
                    int dmg = d[m][i][j].dmg;
                    int kleft = (k*hpm - dmg)/hpm;
                    if ((( k * hpm - dmg)%hpm) != 0)
                        kleft++;
                    //try teleport

                    for ( int t = 1; t <= n; t++ ) {
                        h = j;
                        p = max(1, t - vm);
                        if ( p == 1 )
                            h -= kleft;
                        if ( h > 0 ) {
                            
                            b[m+1][p][h] = 1;
                            if (dmg >= d[m+1][p][h].dmg) {
                                d[m+1][p][h].dmg = dmg;
                                d[m+1][p][h].action = 'T';
                                d[m+1][p][h].p = t;
                                d[m+1][p][h].i = i;
                                d[m+1][p][h].j = j;
                            }
                        }
                    }
                    //try heal
                    h = j;
                    if ( h < hp ) {
                        h += heal;
                        if (h > hp )
                            h = hp;
                        p = max(1, i-vm);
                        if ( p == 1 )
                            h -= kleft;
                        if ( h > 0 ) {
                            b[m+1][p][h] = 1;
                            if (dmg >= d[m+1][p][h].dmg) {
                                d[m+1][p][h].dmg = dmg;
                                d[m+1][p][h].action = 'H';
                                d[m+1][p][h].i = i;
                                d[m+1][p][h].j = j;
                            }
                        }
                    }
                    //try attack
                    h = j;
                    dmg += l[i];
                    if ( dmg >= k*hpm ) {
                        printf("VICTORIOUS\n");
                        nans = 1;
                        ans[1].action = 'L';

                        while ( d[m][i][j].action != ' ' ) {
                    //        cout << m << ' ' << i << ' ' << j << endl;
                            nans++;
                            ans[nans].action = d[m][i][j].action;
                            ans[nans].p  = d[m][i][j].p;
                            int ti = d[m][i][j].i;
                            int tj = d[m][i][j].j;
                            i = ti;
                            j = tj;
                            m--;
                        }


                        for ( int t = nans; t >= 1; t-- ) {
                            printf("%c", ans[t].action);
                            if ( ans[t].action == 'T' )
                                printf(" %d", ans[t].p);
                            printf("\n");
                        }
                        return 0;
                    }
                    kleft = (k*hpm - dmg)/hpm;
                    if ( (k*hpm - dmg)%hpm > 0 )
                        kleft++;

                    p = max(1, i-vm);
                    if ( p == 1 ) 
                        h -= kleft;
                    if ( h > 0 ) {
                        b[m+1][p][h] = 1;
                        if ( dmg >= d[m+1][p][h].dmg ) {
                            d[m+1][p][h].dmg = dmg;
                            d[m+1][p][h].action = 'L';
                            d[m+1][p][h].i = i;
                            d[m+1][p][h].j = j;
                        }
                    }

                    //if ( d[m][i][h] + l[i] > d[m+1][max(1, i-vm)][h-
                }
            }
        if ( !ok ) {
            break;
        }
    }

    printf("DEFEATED\n");
    return 0;
}
