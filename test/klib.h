#include <stdarg.h>
// string.h
void  *my_memset    (void *s, int c, int n);
void  *my_memcpy    (void *dst, const void *src, int n);
void  *my_memmove   (void *dst, const void *src, int n);
int    my_memcmp    (const void *s1, const void *s2, int n);
int my_strlen    (const char *s);
char  *my_strcat    (char *dst, const char *src);
char  *my_strcpy    (char *dst, const char *src);
char  *my_strncpy   (char *dst, const char *src, int n);
int    my_strcmp    (const char *s1, const char *s2);
int    my_strncmp   (const char *s1, const char *s2, int n);

// stdlib.h
void   my_srand     (unsigned int seed);
int    my_rand      (void);
void  *my_malloc    (int size);
void   my_free      (void *ptr);
int    my_abs       (int x);
int    my_atoi      (const char *nptr);

// stdio.h
int    my_printf    (const char *format, ...);
int    my_sprintf   (char *str, const char *format, ...);
int    my_snprintf  (char *str, int size, const char *format, ...);
int    my_vsprintf  (char *str, const char *format, va_list ap);
int    my_vsnprintf (char *str, int size, const char *format, va_list ap);

