#define WORD_BUFFER 40
extern char word[WORD_BUFFER];
extern char *hiragana;
int banner();
void romaji_to_hiragana(char word[], char **save_to);
