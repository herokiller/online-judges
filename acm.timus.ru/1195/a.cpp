#include <iostream>

using namespace std;

char ch;
int i,j,p1,p2,a[10][10],x,b[10][10],k,q;

void check1() {
   p1 = 0;

   x = a[1][1] + a[2][2] + a[3][3]; if ( x >= 2 ) p1++;
   x = a[1][3] + a[2][2] + a[3][1]; if ( x >= 2 ) p1++;

   for ( i = 1; i <= 3; i++ ) {
      x = 0;
      for ( j = 1; j <= 3; j++ )
         x += a[i][j];
      if ( x >= 2 ) p1++;

      x = 0;
      for ( j = 1; j <= 3; j++ )
         x += a[j][i];
      if ( x >= 2 ) p1++;
   }
}

void check2() {
   p2 = 0;

   x = a[1][1] + a[2][2] + a[3][3]; if ( x <= -2 ) p2++;
   x = a[1][3] + a[2][2] + a[3][1]; if ( x <= -2 ) p2++;

   for ( i = 1; i <= 3; i++ ) {
      x = 0;
      for ( j = 1; j <= 3; j++ )
         x += a[i][j];
      if ( x <= -2 ) p2++;

      x = 0;
      for ( j = 1; j <= 3; j++ )
         x += a[j][i];
      if ( x <= -2 ) p2++;
   }

}

int main() {

   memset(b,0,sizeof(b));

   for ( i = 1; i <= 3; i++ ) {
      for ( j = 1; j <= 3; j++ ) {
         scanf("%c", &ch); 
         if ( ch == 'X' ) a[i][j] = 1; else
         if ( ch == 'O' ) a[i][j] = -1; else
         a[i][j] = 0;
      }
      if ( i < 3 ) scanf("%c", &ch);
   }

   check1();
   
   if ( p1 > 0 ) {
      printf("Crosses win"); 
      return 0;
   }

   check2();
      
   if ( p2 > 1 ) {
      printf("Ouths win"); 
      return 0;
   }


   for ( k = 1; k <= 3; k++ )
      for ( q = 1; q <= 3; q++ ) 
         if ( a[k][q] == 0 ) {
            a[k][q] = 1;

            check1(); check2();

            if (( p1 >= 2 ) && (p2 == 0)) {
               printf("Crosses win");
               return 0;
            }

            a[k][q] = 0;
         }

   printf("Draw");
      
         
   return 0;
}
