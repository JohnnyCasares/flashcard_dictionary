#include "functions.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
char word[]; // initialize extern var
int main() {

  setlocale(LC_ALL, "ja_JP.UTF8");
  banner(); // Print banner
  // word look up
  printf("\n\nWelcome back\n\a");
  printf("Look up a word (enter it in romaji): ");
  scanf("%s", word);
  // print user's word, hiragana version, and katakana
  printf("\nyour word is %s", word);


    
  return 0;
}