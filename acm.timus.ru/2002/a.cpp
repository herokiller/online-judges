#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string users[111], p[111]; 

char s[111];
int l, n, t;
bool b[111];

int main() {
	scanf("%d\n", &t);
	for ( int i = 1; i <= t; i++ ) {
		gets(s);
		l = strlen(s);
		int k = 0;
		string type = "", username = "", password = "";

		for ( int j = 0; j < l; j++ )
			if ( s[j] == ' ' ) {
				k = j+1;
				break;
			} else
				type += s[j];	

		for ( int j = k; j < l; j++ )
			if ( s[j] == ' ' ) {
				k = j+1;
				break;
			} else 
				username += s[j];

		for ( int j = k; j < l; j++ )
			password += s[j];
	   	
		if (type == "register") {
			bool ok = true;			
			for ( int j = 1; j <= n; j++ ) 
			 	if (users[j] == username) {
			 		ok = false;
			 		break;
			 	}

			if ( ok ) {
				n++;
				users[n] = username;
				p[n] = password;
				printf("success: new user added\n");
			} else {
				printf("fail: user already exists\n");
			}
		} else if (type == "login") {
			bool ok = false;
			for ( int j = 1; j <= n; j++ )
				if ( users[j] == username ) {
					ok = true;
					if ( p[j] == password ) {
						if (b[j]) {
							printf("fail: already logged in\n");
						} else {
							printf("success: user logged in\n");
							b[j] = 1;	
						}
					} else {
						printf("fail: incorrect password\n");
					}
					break;
				}
			
			if (!ok) 
				printf("fail: no such user\n");
		} else {
			bool ok = false;
			for ( int j = 1; j <= n; j++ ) 
				if ( users[j] == username ) {
					ok = true;
					if ( b[j] == 1 ) {
					    printf("success: user logged out\n");
						b[j] = 0;
					} else {
						printf("fail: already logged out\n");
					}
					break;
				}
			if (!ok)
				printf("fail: no such user\n");
		}
	}
	return 0;
}
