#include <stdio.h>

#define N 2000100

using namespace std;

struct mass {
    int next, val;
};

mass a[N];
int n, x, m;

int main() {
    scanf("%d", &n);
    int head = 0, tail = -1, size = 0, m = 0;

    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &x);
        if ( x == 0 ) {
            int h = head;
            int t = tail;
            int s = size;

            for ( int j = 0; j < s; j++ ) {
                if ( size >= 999999 ) 
                    break;
                a[m].val = a[h].val;
                a[t].next = m;
                t = m;
                size++;
                m++;
                h = a[h].next;
            }
            tail = t;

        } else if ( x == -1 ) {
            printf("%d\n", a[head].val);
            head = a[head].next;
            size--;
            if ( size == 0 ) 
            	tail = -1;
        } else {
            a[m].next = head;
            a[m].val = x;
            head = m;
            size++;
            m++;
            if ( tail < 0 ) 
            	tail = m - 1;
        }
    }

    return 0;
}