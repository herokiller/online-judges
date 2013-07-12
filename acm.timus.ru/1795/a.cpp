#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct product {
	char name[40];
	int q;
};
struct task {
	int q, p;
};

task d[1100];
product a[1100];
int n, m;
char s[40];

int main() {
	scanf("%d\n", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &a[i].q);
		char ch;
		for ( int j = 1; j <= 4; j++ )
			ch = getchar();
		gets(a[i].name);
   	}
                 
   	scanf("%d\n", &m);
   	for ( int i = 1; i <= m; i++ ) {
   		scanf("%d", &d[i].q);
		char ch;
		for ( int j = 1; j <= 4; j++ )
			ch = getchar();

   		gets(s);
   		int n1 = strlen(s), n2;

   		bool ok = false;

   		for ( int j = 1;j <= n; j++ ) {
   			n2 = strlen(a[j].name);
   			if (n1 != n2 ) continue;
   			ok = true;
   			for ( int k = 0; k < n1; k++ )
   				if ( a[j].name[k] != s[k] ) {
   					ok = false;
   					break;
   				}

   			if ( ok ) {
   				d[i].p = j;
   				break;
   			}
   		}
   	}


   	int ans = 0;
  	for ( int i = 1; i <= m; ) {
  		if (( d[i].p == 0 ) || ( a[d[i].p].q == 0)) {
  			i++;
  		} else {
  			if ( a[d[i].p].q >= d[i].q ) {  				
  				a[d[i].p].q -= d[i].q;
  				i++;  				
  			} else {
  				d[i].q = a[d[i].p].q;  			
  				if ( i < m ) {  					
  					task c = d[i];
  					d[i] = d[i+1];
  					d[i+1] = c;
  				} else {
  					i++;
  				}
  			}
  		}

  		ans++;
  	}

  	printf("%d\n", ans);
   		
   	return 0;	
}
