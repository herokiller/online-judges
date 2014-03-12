#include <iostream>
#include <stdio.h>

using namespace std;

int n;

int main() {
	scanf("%d", &n);

	long long ans1, ans2;

	if ( n%2 == 0 ) {
		if ( n == 4 ) 
			ans1 = 0;
		else if ( n == 6 ) 
			ans1 = 6;
		else 
			ans1 = ((long long)(n-3)*(long long)n)/2;


		ans2 = (long long)(n - 3)*(long long)n/2;
	} else {
		if ( n <= 5 )
			ans1 = 0;
 		else
 			ans1 = (long long)(n-3)*(long long)n/2;
		ans2 = 0;
	}

	printf("%I64d %I64d\n", ans1, ans2);
	return 0;
}
