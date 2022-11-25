
#include <stdlib.h>
#include <string.h>
#define HIRAGANA_SIZE 16

void romaji_to_hiragana(
    char word[],
    char **save_to) { // receives two arrays, one with the input
                      // word and the pointer to pointer to where the hiragana
                      // converstion should be saved to

  char *individual_hiragana = (char *)malloc(sizeof("ああ"));
  char *complete_hiragana = (char *)malloc(18 * sizeof("あ") + 1);
  complete_hiragana[0] = '\0';
  char *result;
  int consonant = 0;
  // flags
  // char to string
  char charString[2] = {' ', '\0'};
  // char to string
  char *hiragana[HIRAGANA_SIZE][9] = {
      // a    i   u   e   o   ya    yu    yo
      {"\0", "a", "i", "u", "e", "o", "a", "u", "o"},
      {"\0", "あ", "い", "う", "え", "お", "\0", "\0", "\0"}, // vowels
      {"k", "か", "き", "く", "け", "こ", "きゃ", "きゅ", "きょ"},
      // S special case shi
      {"s", "さ", "し", "す", "せ", "そ", "しゃ", "しゅ", "しょ"},
      // T especial case tsu, ya =cha, yu =chu,  yo = cho
      {"t", "た", "ち", "つ", "て", "と", "ちゃ", "ちゅ", "ちょ"},
      {"n", "な", "に", "ぬ", "ね", "の", "にゃ", "にゅ", "にょ"},
      // H especial case fu
      {"h", "は", "ひ", "ふ", "へ", "ほ", "ひゃ", "ひゅ", "ひょ"},
      {"m", "ま", "み", "む", "め", "も", "みゃ", "みゅ", "みょ"},
      {"y", "や", "\0", "ゆ", "\0", "よ", "\0", "\0", "\0"},
      {"r", "ら", "り", "る", "れ", "ろ", "りゃ", "りゅ", "りょ"},
      {"w", "わ", "ゐ", "\0", "ゑ", "を", "\0", "\0", "\0"},
      {"g", "が", "ぎ", "ぐ", "げ", "ご", "ぎゃ", "ぎゅ", "ぎょ"},
      // z especial case ji TODO
      {"z", "ざ", "じ", "ず", "ぜ", "ぞ", "じゃ", "じゅ", "じょ"},
      // d especial case ji, zu TODO
      {"d", "だ", "ぢ", "づ", "で", "ど", "ぢゃ", "ぢゅ", "ぢょ"},

      {"b", "ば", "び", "ぶ", "べ", "ぼ", "びゃ", "びゅ", "びょ"},

      {"p", "ぱ", "ぴ", "ぷ", "ぺ", "ぽ", "ぴゃ", "ぴゅ", "ぴょ"}

  };

  int row = 0;
  int column = 0;
  int hflag = 0;
  // int word_index;
  int word_index;
  // for loop for word index.
  for (word_index = 0; word_index < strlen(word); word_index++) {
    for (row = 0; row < HIRAGANA_SIZE; row++) {
      // convert chars from word to string
      if (word[word_index] == 'c') {
        if (word[word_index + 1] == 'h') {
          word[word_index + 1] = 'y';
        }
        word[word_index] = 't';
      }
      if (word[word_index] == 'f') {
        word[word_index] = 'h';
      }

      charString[0] = word[word_index]; // word index
      // if charString is c, then interpret it as t

      if (!strcmp(charString, hiragana[row][0])) {
        consonant = 1;
        // if statement to check if its especial case of S
        //
        ++word_index; // move to next letter of word

        break;
      }
    }
    if (consonant != 1) {
      row = 1;
    }
    // printf("row %d column %d\n", row, column);

    // scans first row the the vowels and others are found
    // it should only scan 6 to 9 if there is a consonant before

    // if consonant>1, then use ++word_index for the word index

    for (column = 0; column < 9; column++) {
      if (word[word_index] == 'y') {
        charString[0] = word[++word_index];
        column = 6;
        // handle h in the word
      } else if (word[word_index] == 'h') {

        // if previous char was t, then column = 6
        if (word[word_index - 1] == 't') {

          column = 6;
        }
        charString[0] = word[++word_index];
        // handle especial case tsu

      } else if (word[word_index] == 's') {

        if (word[word_index - 1] == 't') {
          charString[0] = word[++word_index];
        }

      }

      else
        charString[0] = word[word_index]; // word index
      // printf("%s\t", hiragana[0][column]);
      if (!strcmp(charString, hiragana[0][column])) {
        break;
      }
    }
    // individual_hiragana = malloc(sizeof(hiragana[row][column]));
    strcpy(individual_hiragana, hiragana[row][column]);

    // use word to hiragana and

    strcat(complete_hiragana, individual_hiragana);

    consonant = 0;
  }

  // printf("%s\n", complete_hiragana);
  // printf("%li\n", strlen(complete_hiragana));

  *save_to = strdup(complete_hiragana);
}