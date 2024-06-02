#include "bufio.h"
#include <stdlib.h>

char buffer[1024];
int main() {
    if (readln(buffer) == BUF_EXIT_FAIL) exit(1);
    printf("str: %s\n", buffer);

  return 0;
}
