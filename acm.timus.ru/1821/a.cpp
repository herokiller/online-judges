#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

struct racer {
	string name;
	int tf, t;
};

racer a[110];
char s[110];
string temp;
int n;

bool comp(racer A, racer B) {
	return (A.tf < B.tf);
}

bool comp2(string a, string b) {
	return a < b;
}

int main() {
	scanf("%d\n", &n);
	for ( int i = 0; i < n; i++ ) {
		gets(s);
		temp = "";
		int l = strlen(s);

		for ( int j = 0; j < l; j++ ) {
			if ( s[j] == ' ' ) {
				a[i].name = temp;
				int t = ( (((int)s[j+1])*10 + (int)s[j+2])*60 + (((int)s[j+4])*10 + (int)s[j+5]))*10 + (int)s[j+7];
				int tf =  ( (((int)s[j+1])*10 + (int)s[j+2])*60 + (((int)s[j+4])*10 + (int)s[j+5]) + 30*i)*10 + (int)s[j+7];
				a[i].tf = tf;
				a[i].t = t;
				break;
			} else {
				temp += s[j];
			}
		}
	}

	sort(a, a+n, comp);

	int min = -1;
	string ans[110];
	int nans = 0;

	for ( int i = 0; i < n; i++ ) {
		if (( a[i].t < min ) || ( min == -1 )) {
			ans[nans] = a[i].name;
			nans++;
			min = a[i].t;
		}
	}
	sort(ans, ans+nans, comp2);
	
	printf("%d\n", nans);
	for ( int i = 0; i < nans; i++ ) {
		for ( int j = 0; j < ans[i].length(); j++ )
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}

