#include "my_tar.h"

// custom strlen
size_t my_strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Custom string function (replaces strncpy)
char* my_strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    while (i < n) {
        dest[i++] = '\0';
    }

    return dest;
}

// Custom string copy function
void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the string
}

// Custom error handling function
void my_error(const char *message){
    write(2, message, my_strlen(message)); 
}

int main(int argc, char * argv[]){
    int op_c = 0;
    int op_r = 0;
    int op_t = 0;
    int op_u = 0;
    int op_x = 0;
    int op_f = 0;
    const char *archive_name = NULL;

   if(argc < 4){
      my_error("Missing required arguments\n");
      return 1;
   }

   for(int i = 1; i < argc; i++){
       if(argv[i][0] == '-'){
           for(int j = 1; argv[i][j] != '\0'; j++){
               if(argv[i][j] == 'c'){
                   op_c = 1;
               } else if(argv[i][j] == 'r'){
                   op_r =1;
               } else if(argv[i][j] == 't'){
                   op_t = 1;
               } else if(argv[i][j] == 'u'){
                   op_u =1;
               } else if(argv[i][j] == 'x'){
                   op_x = 1;
               } else if(argv[i][j] == 'f'){
                   op_f = 1;
                   if(i + 1 < argc){
                      archive_name = argv[i + 1];
                      i++;
                   } else {
                       my_error("Error: Archive name must be provided for -f option.\n");
                       return 1;
                   }
               } else {
                   my_error("Wrong flag\n");
                   return 1;
               }
           }
       }
   }

   if((op_r || op_u || op_c) && !op_f){
       my_error("The -f option is required\n");
       return 1;
   }

   return 0;
}
