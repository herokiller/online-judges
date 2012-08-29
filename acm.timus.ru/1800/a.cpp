#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int l, h, w;

int main() {
	scanf("%d%d%d", &l, &h, &w);

	double g = 9.81;
	double time = sqrt((double)(2*(h - (double)l/(double)2))/g);

	cout << time << endl;

	int times = (int)(((double)w/(double)90)*time);
	
	cout << times << endl;
	if (( times%4 == 0 ) || ( times%4 == 3)) 
		printf("butter\n");
	else 
		printf("bread\n");


	return 0;
}

