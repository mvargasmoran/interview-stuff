/*
 * This should be compiled like these
 * gcc map.c stringmemes.c && ./a.out
 */


#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
 #include <Windows.h>
#else
 #include <unistd.h>
#endif

//#include "stringmemes.h"

int main() {
  int i=0;
  //printf("slow message\n");
  //for(i=1; i<=4;i++) {
  //  sleep(1);
  //  characterSpacer("+", i);
  //  printf("%d\n", i);
  //}
  //int j=0;
  //for (i=0; i<255; i++) {
  //  printf("%d ", i);
  //  printf("\t");
  //  printf("%c ", j);
  //  printf("\n");
  //  j++;
  //}
  //

  printf("%s", "&#9786;");
  printf("\n");
  printf("%s", "\xE2\x98\xA0");
  printf("\n");
  printf("%s", "\xE2\x98\xBA");
}

