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
void toUpperCase(char* s){

    isalpha(s);
    if('a'>=s && s<='z'){
        toupper(s);
    }
}
/* */
void toLowerCase(char* s){

    isalpha(s);
    if('A'>=s && s<='Z'){
        tolower(s);
    }
}
/* */
void reverseString(char *s)
{
    if (s == NULL)
    {
        return;
    }
    int len = my_strlen(s);
    char tmp[len + 1];
    for (int i = 0; i < len; i++)
    {
        tmp[i] = s[len - 1 - i];
    }
    tmp[len] = '\0';
    for (int i = 0; i <= len; i++)
    {
        s[i] = tmp[i];
    }
}
/* */
int countWords(const char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    int count = 0;
    int inWord = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            if (!inWord)
            {
                count++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }
    return count;
}