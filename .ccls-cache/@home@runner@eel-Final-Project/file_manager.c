#include <ctype.h>
#include <stdio.h>
#include <string.h>
char *dictionary[100][2];
int dict_location;
void file_to_array() {
  // store words into dictionary array.
  FILE *dictFile;
  int index = 0;
  if ((dictFile = fopen("dict.txt", "r")) == NULL) {
    printf("Error, file dict.txt doesnt exist in directory");
    exit(1);
  } else {

    char *word;
    char *definition;
    char line[400];
    while (!feof(dictFile)) {

      // token with comma
      // stuff before comma is word, stuff after comma is meaning
      // add check if file is empty
      fgets(line, sizeof(line), dictFile);
      word = strtok(line, ",");
      definition = strtok(NULL, "\n");
      // add words to dictionary

      dictionary[index][0] = strdup(word);

      dictionary[index][1] = strdup(definition);

      index++;
    }
    fclose(dictFile);
  }
}

int dict_lookup(char word[]) {

  // scan dict[index++][0] for matches
  int index = 0;

  while (dictionary[index][0] != NULL) {
    if (!strcmp(word, dictionary[index][0])) {
      // printf("%s", dictionary[index][0]);
      dict_location = index;
      // printf("%i", dict_location);
      return 1; // found
    }
    index++;
  }
  return 0; // not found
}

int append_to_dict(char *hiragana, char *meaning) {
  FILE *dictFile;
  int index = 0;
  if ((dictFile = fopen("dict.txt", "a")) == NULL) {
    printf("Error, file dict.txt doesnt exist in directory");
    exit(1);
  } else {
    fprintf(dictFile, "\n%s, %s", hiragana, meaning);

    fclose(dictFile);
  }

  return 1; // success
}