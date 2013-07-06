#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int l, k, h;
	scanf("%d%d%d", &l, &k, &h);
	double ans1, ans2;
	
	ans2 = ans1 = (double)((l/k)*h);
	if ( l%k != 0 )
		ans2 += (double)h;

	printf("%.5lf %.5lf\n", ans1, ans2);
	

	return 0;
}

