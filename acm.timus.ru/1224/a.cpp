#include <iostream>

using namespace std;

long long n, m;

int main() {
	cin >> n >> m;

	long long ans;

	if ( n <= m )
		ans = (n-1)*2;
	else 
		ans = (m-1)*2 + 1;

	cout << ans;

	return 0;
}
