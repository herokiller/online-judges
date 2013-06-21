#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char s[10];
	gets(s);
	int x = 0, y = 0;
	for ( int i = 0; i < strlen(s); i++ ) {
		if (( s[i] >= '0' ) && ( s[i] <= '9')) {
			x = x*10 + (int)(s[i] - '0');
		} else {
			y = (int)(s[i] - 'A' + 1);
			break;
		}
	}
	
	if ( y >= 10 ) y--;

	if ( x <= 2 ) {
		if (( y == 1 ) || ( y == 4)) 
			printf("window");
		else 
			printf("aisle");
	} else if ( x <= 20 ) {
		if (( y == 1) || ( y == 6)) 
			printf("window");
		else
			printf("aisle");
	} else if ( x <= 65 ) {
		if ((y == 1) || ( y == 10))
			printf("window");
		else if ((y==3) || (y==4) || (y==7) || (y==8)) 
			printf("aisle");
		else
			printf("neither");
	}
}

