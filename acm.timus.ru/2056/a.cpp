#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string ans = "Common";
int s, n;

int main() {

	scanf("%d", &n);
	for ( int i = 0; i < n; i++ ) {
		int x;
		scanf("%d", &x);
		s += x;
		if (x < 4)
			ans = "None";
	}

	double avg = (double)s/(double)n;

	if ( ans != "None")
		if ( s == 5*n ) {
			ans = "Named";
		} else if ( avg >= 4.5 ) {
			ans = "High";
		}

	cout << ans << endl;
	return 0;
}