#define WORD_BUFFER 40
extern char word[WORD_BUFFER];
extern char *hiragana;
extern char *dictionary[][2]; // column 0 words, column 1 definition
extern int dict_location;

int banner(); // prints welcome screen (edited ascii art from
              // https://www.deviantart.com/yari-ashigaru/art/Japanese-Castle-Text-Art-545107783)
void romaji_to_hiragana(
    char word[],
    char **save_to); // enter word in romaji and an array to save the hiragana
int file_to_array(); // file to array, this is gonna help me look up word easier
int dict_lookup(char word[]); // look up word in dictionary

int append_to_dict(char *hiragana, char *meaning); // adds word to end of file