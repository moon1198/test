#include <stdio.h>


typedef unsigned char *byte_pointer;
	//％ｘ的格式化输出，使temp_byte[0]经过了到uint的转换，故temp_byte要初始化为无符号的；

void show_bytes(byte_pointer start, size_t len){
	size_t i;
	for (i=0; i<len; i++){
		
		//start[0] is a unsigned char,one byte.however,%.2x is a usigned int, 4 bytes.so, unsigned make it possible to neglect the fromer zero in the convert.instead,it has the possiblity to fill out one in the former.
		printf("%.2x", start[i]);

		printf("\n");
	}
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x){
	show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}


/*
*int main (){
*	int i = 255;
*	show_int(i);
*	printf("\n");
*	float j = 255;
*	show_float(j);
*	printf("\n");
*	show_pointer(&j);
*	printf("\n");
*
*	char ch[] = "Hello world";
*	show_bytes((unsigned char*)ch, strlen(ch));
*
*	return 0;
*}*/
