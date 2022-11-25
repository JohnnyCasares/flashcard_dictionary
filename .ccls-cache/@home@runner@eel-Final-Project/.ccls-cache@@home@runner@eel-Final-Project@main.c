#include "functions.h"
// #include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <wchar.h>
char word[]; // initialize extern var
void romaji_to_hiragana(char word[], char **save_to);
char *hiragana;
// int dict_location;
int file_to_array();
int dict_lookup(char word[]);
int append_to_dict(char *hiragana, char *meaning);

void scanner(char line[]) {
  char c;
  int index = 0;
  while ((c = getchar()) != '\n') {
    if (c >= 'A' && c <= 'Z') {
      c = c + 32;
    }
    line[index++] = c;
  }
  line[index] = '\0';
}

// void get_meaning(char *meaning) {
//   char c;
//   meaning[0] = ;
//   while ((c = getchar()) != '\n') {
//     strcat(&c, meaning);
//   }
// }
int main() {
  file_to_array(); // saves file to array
  char answer[3];

  char *meaning;
  banner(); // Print banner
  // word look up

LOOP:
  do {

    printf("\nLook up a word (enter it in romaji or 'exit'): ");
    scanner(word);
    if (!strcmp(word, "exit")) {
      return 0;
    }
    // print user's word and hiragana version
    // romaji_to_hiragana(word);
    romaji_to_hiragana(word, &hiragana);
    printf("\nyour word is %s\t%s\n", word, hiragana);
    printf("Are you sure? (yes/no) ");
    scanner(answer);

  } while (!strcmp(answer, "no"));

  // look up word in dictionary
  if (dict_lookup(hiragana)) {
    // found
    printf("Your word was found\n");
    // display word and meaning

    printf("%s %s\n", hiragana, dictionary[dict_location][1]);
    goto LOOP;

  } else {

    // not found
    printf("Word not found. Do you wish to add it to the dictionary?(yes/no) ");
    scanner(answer);

    if (!strcmp(answer, "yes")) {
      // display word and ask user for meaning

    DEFINE:
      printf("Your word is: %s (%s)\n", hiragana, word);
      printf("Add its definition (up to 300 characters): ");
      char input[300];
      scanner(input);
      meaning = strdup(input);

      printf("\nYour definition: %s", input);

      printf("\nAre you sure? (yes/no) ");
      scanner(answer);
      if (!strcmp(answer, "yes")) {
        append_to_dict(hiragana, meaning);
        printf("Wish to look up another word? ");
        scanner(answer);
        if (!strcmp(answer, "yes"))
          goto LOOP;
      } else
        goto DEFINE;
    } else {
      goto LOOP;
    }
  }

  return 0;
}