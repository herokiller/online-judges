#include <iostream>

using namespace std;

int a[2500],m1[2500],m2[2500],i,n,j;

int main() {
   cin >> n;

   memset(m1,sizeof(m1),0); memset(m2,0,sizeof(m2));

   for ( i = 1; i <= n; i++ ) {
      cin >> a[i];  
      for ( j = i-1; j >= 1; j-- ) 
         if ( a[j] > a[i] ) m1[a[i]]++;
   }

   for ( i = 1; i <= n; i++ )
      for ( j = i+1; j <= n; j++ )
         if ( a[j] < a[i] ) m2[a[i]]++;

   for ( i = 1; i <= n; i++ )
      cout << m1[i]+1 << ' ' << n - m2[i] << endl;
       
   return 0;
}
