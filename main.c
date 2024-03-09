#include <stdio.h>

char buffio[];

int readln(char* var);
char gbufchar(char* var);
int cpybufstr(char* var, char* str, const int maxlen);

int main(void) {
  readln(buffio);
  printf("Buffer: %s\n", buffio);
  //char c = gbufchar(buffio);
  //printf("Buffer: %s\n", buffio);
  char str[5];
  cpybufstr(buffio, str, 5);
  printf("String: %s\nBuffer: %s", str, buffio);
  return 0;
}

int cpybufstr(char* var, char* str, const int maxlen) {
    char checkStr[32];
    for (int i = 0; var[i] != ' '; i++) {
        checkStr[i] = var[i];
    }
    for (int i = 0; i < maxlen; i++) {
        if (i < maxlen) {
            str[i] = checkStr[i];
        } else {
            str[i] = '\0';
        }
    }
    return 0;
}

char gbufchar(char* var) {
    char firstChar;
    firstChar = var[0];
    for (int i = 0; var[i] != '\0'; i++) {
        var[i] = var[i+1];
    }

    return firstChar;
}
int readln(char* var) {
    scanf("%[^\n]", var);
    getchar(); // очищение \n
}