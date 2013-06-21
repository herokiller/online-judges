#include <iostream>

using namespace std;

double pi = 3.14159265358979, a, b, n, step, now, x;

double volume(double x, double y) {
   return pi*a*a*( (y - (y*y*y)/(double(3)*b*b)) - (x - (x*x*x)/(double(3)*b*b)) );
}

int main() {
   scanf("%lf%lf%lf", &a, &b, &n);
   step = b/n;
   a = a/double(2); b = b/double(2);
   now = -b;

   for ( int i = 1; i <= n; i++ ) {
      x = volume(now, now+step);
      printf("%.6f\n", x);
      now += step;
   }
   
   return 0;
}
