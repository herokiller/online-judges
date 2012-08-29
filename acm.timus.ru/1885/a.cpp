#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int h, t, max, min;
	scanf("%d%d%d%d", &h, &t, &max, &min);

	double ans1 = (double)(h-t*min)/(double)(max - min);
	if (ans1 < 0) ans1 = 0;
	double ans2;

	if ( h > t*min ) ans2 = t;
	else ans2 = (double)h/(double)min;

	printf("%.6lf %.6lf\n", ans1, ans2);

	return 0;
}

