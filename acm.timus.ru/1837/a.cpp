#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

int np;
int a[500][500];
char s[10000];

struct person {
	string name;
	int dist;
};

person people[1000];

struct team {
	string name;
	int pos;
};

team team[3];

void bfs(int start) {
	bool b[500];
	memset(b,0,sizeof(b));
	int	q[500];
	b[start] = 1;
	int nq = 1;
	q[1] = start;
	
	people[start].dist = 0;

	int i = 0;
	while ( i < nq ) {
		i++;

		for ( int j = 1; j <= np; j++ ) 
			if ( ( a[q[i]][j] > 0 ) && (!b[j]) ) {
				nq++;
				q[nq] = j;
				b[j] = 1;
				people[j].dist = people[q[i]].dist + 1;
			}
	}
}

bool comp(person x, person y) {
	return x.name < y.name;
}
int main() {
	int nt;
	np = 0;
	scanf("%d\n", &nt);
	for ( int i = 0; i < nt; i++ ) {
		gets(s); 
		int l = strlen(s), p = 0;

		for ( int t = 0; t < 3; t++ ) {
			string person = "";
			for ( int j = p; j < l; j++ ) {
				if ( s[j] == ' ' ) {
					p = j+1;
					break;
				}
				else person += s[j];
			}
			
			team[t].name = person;
			team[t].pos = 0;
		}

		for ( int t = 0; t < 3; t++ ) {
			for ( int j = 1; j <= np; j++ )
				if ( people[j].name == team[t].name ) {
					team[t].pos = j;
					break;
				}
			if ( team[t].pos == 0 ) {
				np++;
				team[t].pos = np;
				people[np].name = team[t].name;
				people[np].dist = -1;
			}
		}

		for ( int j = 0; j < 3; j++ )
			for ( int k = j+1; k < 3; k++ ) {
				a[team[j].pos][team[k].pos] = 1;
				a[team[k].pos][team[j].pos] = 1;
			}
	}
	int start = 0;
	for ( int i = 1; i <= np; i++ )
		if ( people[i].name == "Isenbaev" )
			start = i;

	bfs(start);

	sort(people+1, people+np+1, comp);

	for ( int i = 1; i <= np; i++ ) {
		cout << people[i].name << ' ';
		if ( people[i].dist == -1 ) printf("undefined\n");
		else printf("%d\n", people[i].dist);
	}
	return 0;
}

