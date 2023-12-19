#include <stdio.h>
#include <unistd.h>

int main(void){
	for (int i = -8; i < 8 ; i++){
		printf(i==0 ? "[%02x] " : "%02x", 0xcc);
	
	
	}
	printf("\n");
//printf("%d\n", !!(-1));
	char *newenviron[] = {NULL};
	char *newargv[] = { NULL };
	execve("./a.out", newargv, newenviron);
	int test;
	return 0;
}
