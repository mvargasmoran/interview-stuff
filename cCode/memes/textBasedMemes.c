#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
 #include <Windows.h>
#else
 #include <unistd.h>
#endif


void scrollingText(char *text) {
  printf("\n%s", text);
}

void printPoemaXX() {
const char myString[] =
  "Puedo escribir los versos más tristes esta noche.\n"
  "\n"
  "Escribir, por ejemplo: La noche está estrellada,\n"
  "y tiritan, azules, los astros, a lo lejos.";

  printf("%s", myString);
}

int main() {


  printPoemaXX();

//
//  char * longboitext[1000];
//  char ch, fileName[] = "poemaxx";
//
//  FILE *fp;
//  fp = fopen(fileName, "r");
//  if(fp == NULL) {
//    perror("Error while opening the file.\n");
//    exit(EXIT_FAILURE);
//  }
//
//  printf("The contents of %s file are:\n", fileName);
//
//
//  while( (ch = fgetc(fp)) != EOF) {
//    //printf("%c", ch);
//    strcat(longboitext, ch);
//  }
//
//  fclose(fp);
//
//  scrollingText(longboitext);
}

