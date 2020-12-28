#include "dcl.h"

int main(void) {
  while (gettoken() != EOF) {
    if (tokentype == '\n')
      continue;
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n')
      printf("syntax error\n");
    else if (errtok == FALSE)
      printf("%s: %s %s\n", name, out, datatype);
  }

  return 0;
}
