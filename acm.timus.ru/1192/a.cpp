#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

double v, a, k, pi = 3.1415926535, g = 10.0;

int main() {
	
	cin >> v >> a >> k;
	
	a = a*pi/((double)180);
	k = 1/k;

	double sum = (v*v)/(1-k);

	double ans = 2*cos(a)*sin(a)*sum/g;

	long long x = (long long)(ans*100);
	long long y = (long long)(ans*1000)%10;
	if ( y >= 5 ) 
		x++;

	cout << x/100 << '.' << (x/10)%10 << x%10 << endl;

	return 0;
}
