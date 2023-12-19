#include "klib.h"
#include <stddef.h>
void my_itoa (char *buf, int num, int hex){
	*buf = '1';
	*(buf + 1) = '\0';
	char num_arr[] = "0123456789";
	char temp[128];
	int len = 0;
	int i = 0;
	char sign = '+';
	int rem = 0;
	//反向写入temp
	temp[i++] = '\0';
	if (num < 0){
		sign = '-';
		buf[len++] = sign;
		num = -num;
	}
	do{
		rem = num % hex;
		temp[i++] = num_arr[rem];
		num = num / hex;
	}while(num != 0);
	i--;
	while (i >= 0){
		buf[len++] = temp[i--];	
	}
}
int my_vsprintf(char *out, const char *fmt, va_list ap) {
  char buf[128];
  int len;
  char *v_out = out;
  //modify point
  *v_out = '\0';
  while (*fmt != '\0'){
	if (*fmt == '%'){
		switch (*(fmt + 1)){
			case 'd':
				my_itoa(buf, va_arg(ap, int), 10);
				my_strcat(v_out, buf);
				break;
			case 's':
				my_strcat(v_out, va_arg(ap, char*));
				break;
			default:
				break;
		}
		fmt += 2;
		while(*v_out != '\0'){v_out ++;}
	}
	else{
		*v_out++ = *fmt++;
		//modify point
		*v_out = '\0';
	}
  }
  *v_out = '\0';
  len = v_out - out;
  return len;
}

int my_sprintf(char *out, const char *fmt, ...) {
  va_list args;
  int len;
  va_start(args, fmt);
  len = my_vsprintf(out, fmt, args);
  va_end(args);
  return len;
}
void *my_memset(void *s, int c, int n){
  char *dy_ptr = (char *)s;
  if (s == NULL){
	return NULL;
  }else{
	while(n-- > 0){
	  *dy_ptr = c;
	  dy_ptr ++;
	}
  } 
  return s;
}
