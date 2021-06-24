#include <stdio.h>
//#include <stdlib.h>
#include <libc.h>

typedef struct {
  char *buffer;
  size_t len;
  size_t cap;
} String;

void string_reset(String *s) {
  s->buffer = NULL;
  s->len = 0;
  s->cap = 0;
}

String string_new() {
  String s;
  string_reset(&s);
  return s;
}

void string_realloc(String *s) {
  if (s->cap == 0) {
    // first allocation
    s->buffer = calloc(4, sizeof(char));
    s->cap = 4;
  } else {
    // reallocate double the size.
    s->buffer = reallocarray(s->buffer, s->cap * 2, sizeof(char));
    s->cap *= 2;
  }
}

void string_destroy(String *s) {
  if (s->buffer) free(s->buffer);
  string_reset(s);
}

void string_push(String *s, char c) {
  if (s->cap == s->len) string_realloc(s);
  s->buffer[s->len] = c;
  s->len++;
}

int main() {
  String myString = string_new();
  char secondString[] = "Puedo Escribir los Versos";
  string_push(myString, secondString);

  printf("%s", myString);
  string_destroy(myString);
}

