#ifndef N__BUFIO__H
#define N__BUFIO__H

#include <stdio.h>

enum {
    BUF_EXIT_SUCCESS,
    BUF_EXIT_FAIL
};
int cpybufstr(char* buf, char* str, const int maxlen) {
    char checkStr[32];
    for (int i = 0; buf[i] != ' '; i++) {
        checkStr[i] = buf[i];
    }
    
    for (int i = 0; i < maxlen; i++) {
        if (i < maxlen) {
            str[i] = checkStr[i];
        } else {
            str[i] = '\0';
        }
    }
    return BUF_EXIT_SUCCESS;
}

char gbufchar(char* buf) {
    char firstChar;
    firstChar = buf[0];
    for (int i = 0; buf[i] != '\0'; i++) {
        buf[i] = buf[i+1];
    }

    return firstChar;
}

int readln(char* buf) {
    if (scanf("%[^\n]", buf) == 0) {
        fputs("WARN: buf has not been read\n", stderr);
        
        return BUF_EXIT_FAIL;
    }
    getchar(); // clear \n
    
    return BUF_EXIT_SUCCESS;
}


#endif
