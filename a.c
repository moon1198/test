#include <stdio.h>
#include "a.h"
int main(){
	int i =  255;
	int j = i << 31;
	show_int(i);
	printf("\n");
	show_int(j);
int test;
	long long k = 0x3ff0000000000000;
	double f = *(double *)&k;
	printf("%f\n", f);
	printf("%f\n", 0x3ff0000000000000);

	show_double(1.0);
	return 0;
}
