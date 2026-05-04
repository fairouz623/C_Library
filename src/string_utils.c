#include "../include/string_utils.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*count caracter*/
int my_strlen(const char* s){

    int i=0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}
/* copy a string in another string*/
char* my_strcpy(char* dest, const char* src){

    int i = 0 ;
    while( src[i] != '\0'){
        dest[i]=src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
/* version sfer to copy a stering*/
char* my_strncpy(char* dest, const char* src, int n){

    int i = 0;
    while( i < n && src[i] != '\0'){
        dest[i]=src[i];
        i++;
    }
    while( i < n){
        dest[i] = '\0';
        i++;
    }
    return dest;
}
/* */
char* my_strcat(char* dest, const char* src){}