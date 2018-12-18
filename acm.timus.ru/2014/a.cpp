#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100100

using namespace std;

long long INF = 1000000000000000000;

struct transaction {
    int v, p, o;
    string date;
};

transaction a[N];

struct node {
    long long add, min;
};
node t[N*4];

bool comp(transaction a, transaction b) {
    return a.date < b.date;
}

bool comp2(transaction a, transaction b) {
    return a.o < b.o;
}


void build(transaction a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v].add = a[tl].v;
        t[v].min = a[tl].v;
    } else {
        int tm = (tl+tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if ( l > r )
        return;
    if ( l == tl && r == tr ) {
        t[v].add += (long long)add;
        t[v].min = t[v].min + add;
    } else {
        int tm = (tl + tr)/2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        t[v].min = min(t[v*2].min, t[v*2+1].min) + t[v].add;
    }
}

long long get(int v, int tl, int tr, int l, int r) {
    if ( l > r )
        return INF;
    if ( tl == l && tr == r )
        return t[v].min;
    int tm = (tl + tr)/2;
    
    return t[v].add + min(
        get(v*2, tl, tm, l, min(r, tm)),
        get(v*2+1, tm+1, tr, max(l, tm+1), r)
    );  
}

int n;

int main() {
    scanf("%d\n", &n);
    for ( int i = 1; i <= n; i++ ) {
        string s;
        scanf("%d ", &a[i].v);
        getline(cin, s);
        char ch = s[0];
        s[0] = s[3];
        s[3] = ch;

        ch = s[1];
        s[1] = s[4];
        s[4] = ch;

        a[i].o = i;
        a[i].date = s;
    }

    sort(a+1, a+n+1, comp);
    
    for ( int i = 1; i <= n; i++ ) {
        a[i].p = i;
    }

    sort(a+1, a+n+1, comp2);
    
    long long ans = 0;
    int p = 0;

    for ( int i = 1; i <= n; i++ ) {
        update(1, 1, n, a[i].p, n, a[i].v);

        ans = get(1, 1, n, 1, n);
        
        if ( ans > 0 )
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    
    return 0;
}

