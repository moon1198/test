#include <stdarg.h>
#include <stdio.h>


int p_args(char *arg, ...){
	va_list ap;
	va_start(ap, arg);
	char *f;
	for (f = arg; f != NULL; f = va_arg(ap, char*)){
		printf("%s\n", f);
	}
	va_end(ap);
}


int main (){
	p_args("hello", "world", 123);
}
