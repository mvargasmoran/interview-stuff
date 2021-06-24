#include "stringmemes.h"
#include <stdio.h>

void characterSpacer(char* spacerString, int lenght)
{
  int i = 1;
  for(i=1; i<=lenght; i++) {
     printf("%s", spacerString);
  }
}

