#ifndef MY_TAR_H
#define MY_TAR_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t my_strlen(const char *str);
char* my_strncpy(char *dest, const char *src, size_t n);
void my_strcpy(char *dest, const char *src);
void my_error(const char *message);
int main(int argc, char * argv[]);

#endif
