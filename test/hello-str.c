#include "klib.h"
#include <stdio.h>
#include <string.h>
int main () {
	//char buf[128]; 
	char buf[20];
	printf("%s", buf);
	memset(buf, '#', 5);
	printf("%s", buf);
	my_memset(buf, '#', 5);
	printf("%s", buf);
	//my_sprintf(buf, "%d + %d = %d", 1, 1, 2);
	//printf("%s\n", buf);
	//my_sprintf(buf, "%d + %d = %d", 3, 3, 6);
	//printf("%s\n", buf);
	//printf("hello\n");
}
