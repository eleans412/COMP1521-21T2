#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "put_string.h"

// print s to stdout with a new line appended using fputc (only)

void put_string(char *s) {

   int len = strlen(s);
   int i = 0;

   for (i = 0; i < len; i++) {
      fputc((int)s[i], stdout);
   }
   fputc('\n', stdout);
   return;
}
