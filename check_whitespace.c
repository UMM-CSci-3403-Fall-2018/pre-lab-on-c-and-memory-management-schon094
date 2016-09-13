#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Strips spaces from both the front and back of a string,
 * leaving any internal spaces alone.
 */
char* strip(char* str) {
  int size;
  int num_spaces;
  int first_non_space, last_non_space, i;
  char* result;

  size = strlen(str);

  // This counts the number of leading and trailing spaces
  // so we can figure out how big the result array should be.
  num_spaces = 0;
  first_non_space = 0;
  while (first_non_space<size && str[first_non_space] == ' ') {
    ++num_spaces;
    ++first_non_space;
  }

  last_non_space = size-1;
  while (last_non_space>=0 && str[last_non_space] == ' ') {
    ++num_spaces;
    --last_non_space;
  }

  // If num_spaces >= size then that means that the string
  // consisted of nothing but spaces, so we'll return the
  // empty string.
  if (num_spaces >= size) {
    return "";
  }

  // Allocate a slot for all the "saved" characters
  // plus one extra for the null terminator.
  result = calloc(size-num_spaces+1, sizeof(char));
  // Copy in the "saved" characters.
  for (i=first_non_space; i<=last_non_space; ++i) {
    result[i-first_non_space] = str[i];
  }
  // Place the null terminator at the end of the result string.
  result[i-first_non_space] = '\0';

  return result;
}

/*
 * Return true (1) if the given string is "clean", i.e., has
 * no spaces at the front or the back of the string.
 */
int is_clean(char* str) {
  char* cleaned;
  int result;

  // We check if it's clean by calling strip and seeing if the
  // result is the same as the original string.
  cleaned = strip(str);

  // strcmp compares two strings, returning a negative value if
  // the first is less than the second (in alphabetical order),
  // 0 if they're equal, and a positive value if the first is
  // greater than the second.
  result = strcmp(str, cleaned);

  return result == 0;
}

int main() {
  int i;
  int NUM_STRINGS = 7;
  // Makes an array of 7 string constants for testing.
  char* strings[] = {  "Morris", 
		       "  stuff", 
		       "Minnesota", 
		       "nonsense  ", 
		       "USA", 
		       "   ", 
		       "     silliness    "
  };

  for (i=0; i<NUM_STRINGS; ++i) {
    if (is_clean(strings[i])) {
      printf("The string '%s' is clean.\n", strings[i]);
    } else {
      printf("The string '%s' is NOT clean.\n", strings[i]);
    }
  }

  return 0;
}
