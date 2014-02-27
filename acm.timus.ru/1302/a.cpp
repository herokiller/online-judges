#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	int x1, x2;
	scanf("%d%d", &x1, &x2);
	if ( x1 > x2 ) 
		swap(x1, x2);

	int l1 = (int)sqrt((double)x1);
	if ( l1*l1 < x1 ) 
		l1++;
	int r1 = x1 - (l1-1)*(l1-1);

	int l2 = (int)sqrt((double)x2);
	if ( l2*l2 < x2 )
		l2++;
	int r2 = x2 - (l2-1)*(l2-1);


//	cout << r1 << ' ' << l1 << endl;
//	cout << r2 << ' ' << l2 << endl;

	int d = abs((l2 - l1 + r1) - r2);

//	cout << d << endl;

	int h = 0, skip = 0;
	if (l2 > l1 ) {
		skip = l2 - l1 - 1; 
		h = (l2 - l1 - 1)*2 + 1;
		if ( r1%2 == 0 ) {
			h++;
			skip++;
		}

		if ( r2%2 == 1 ) {
			h++;		
			skip++;
		}
	}
//	cout << h << ' ' << skip << endl;
	
	int ans = h;

	if ( d > skip ) 
		ans += d - skip;

	cout << ans << endl;
	return 0;
}
