#include "functions.h"
// #include <locale.h>
#include <stdio.h>
#include <wchar.h>
char word[]; // initialize extern var
char romaji_to_hiragana(char word[]);
int main() {

  // setlocale(LC_ALL, "ja_JP.UTF8");
  banner(); // Print banner
  // word look up
  printf("\n\nWelcome back\n\a");
  printf("Look up a word (enter it in romaji): ");
  scanf("%[^\n]", word);
  // print user's word and hiragana version
  // romaji_to_hiragana(word);
  printf("\nyour word is %s\t", word);

  romaji_to_hiragana(word);
  

    
  return 0;
}