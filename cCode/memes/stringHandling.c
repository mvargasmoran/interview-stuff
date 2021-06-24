#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc_private.h>
//#include <malloc.h>

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

void string_destroy(String *s) {
  if (s->buffer) free(s->buffer);
  string_reset(s);
}

size_t log2_basic(size_t value) {
  size_t pow = 0;
  for(; value > 1; value >>= 1) pow++;
  return pow;
}

void string_ensure_capacity(String *s, size_t capacity) {
  // no need to do more.
  if (s->cap >= capacity) return;
  // find the nearest power of two that is greater than `capacity`.
  size_t final_capacity = 1 << (log2_basic(capacity) + 1);
  if (final_capacity < 4) final_capacity = 4; // minimum capacity is 4.
  if (s->cap == 0) {
    // first allocation
    s->buffer = calloc(final_capacity, sizeof(char));
  }
  else {
    // reallocated.
    s->buffer = reallocarray(s->buffer, final_capacity, sizeof(char));
  }
  s->cap = final_capacity;
}

void string_realloc(String *s) {
  size_t target_size = s->cap == 0 ? 4 : s->cap * 2;
  string_ensure_capacity(s, target_size);
}

void string_push_char(String *s, char c) {
  if (s->cap == s->len) string_realloc(s);
  s->buffer[s->len] = c;
  s->len++;
}

void string_push_cstr(String *s, const char *cs) {
  size_t len = strlen(cs);
  string_ensure_capacity(s, s->len + len);
  // copy at most the empty space that I have.
  strncpy(s->buffer + s->len, cs, s->cap - s->len);
  // increment the length.
  s->len += len;
}

// not very clean, but serves the purpose.
const char *string_cstr(String *s) {
  string_push_char(s, 0);
  s->len--; // act as if nothing had been pushed.
  return s->buffer;
}

String string_copy(const String *s) {
  String new = string_new();
  string_ensure_capacity(&new, s->cap);
  strncpy(s->buffer, new.buffer, new.cap);
  new.len = s->len;
  return new;
}

int main() {
  String s = string_new();
  string_push_cstr(&s, "Hello, world! ");
  string_push_cstr(&s, "I am Gsus.");

  puts(string_cstr(&s));

  string_destroy(&s);
  return 0;
}

