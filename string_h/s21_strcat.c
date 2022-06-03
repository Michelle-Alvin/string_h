#include "s21_sprintf.h"

char* s21_strcat(char *dest, char src) {
    char *save = dest;
    int flag = 1;
    while (*dest) {
        dest++;
    }
    if (src == '+' && dest[-1] == ' ') {
        dest[-1]= '+';
        dest[0] = '\0';
        flag = 0;}
    if (src == '-' && (dest[-1] == '+' || dest[-1] == ' ')) {
        dest[-1]= '-';
        dest[0] = '\0';
        flag = 0;}
    if (flag == 1){
        dest[0] = src;
        dest[1] = '\0';}
    /*while(*src) {
        *dest = *src;
        dest++;
        src++;
    }*/

    //*dest = '\0';
    return save;
}
