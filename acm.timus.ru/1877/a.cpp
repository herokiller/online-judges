#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s1, s2;

int main() {
	getline(cin,s1);
	getline(cin,s2);
	
	int x1 = (int)(s1[3]);
	int x2 = (int)(s2[3]);

	if (( x1%2 == 1 ) && ( x2%2 == 0)) 
		printf("no");
	else 
		printf("yes");

	return 0;
}

