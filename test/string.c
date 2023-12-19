#include <stddef.h>
char *my_strcat(char *dst, const char *src) {
  char *v_dst = dst;
  while(*v_dst != '\0') {v_dst ++;};
  const char *v_src = src;
  while(*v_src != '\0'){
	*v_dst++ = *v_src++;
  }
  *v_dst = '\0';
  return dst;
}

int my_strcmp(const char *s1, const char *s2) {
  int flag = 0;
  if ((s1 == NULL && s2 != NULL)||(s2 == NULL&&s1 != NULL)){
	return 1;
  }else if (s1 == NULL && s2 == NULL){
	return 0;	
  }else{
	while(*s1 != '\0' && *s2 != '\0'){
	  flag = (int) *s1 - (int) *s2;
	  if (flag != 0){
	    return flag;
	  }
	  s1 ++; s2 ++;
	}
	if(*s1 == '\0' && *s2 == '\0') {flag = 0;} else {flag = 1;}
  }
  return flag;
}

void *my_memcpy(void *out, const void *in, int n) {
  if (out == NULL || in == NULL || n <= 0){
	return NULL;	  
  }
  char *v_out = (char *)out;
  char *v_in = (char *)in;
  while(n --){
	  *v_out ++ = *v_in ++;
  }
  return out;
}

