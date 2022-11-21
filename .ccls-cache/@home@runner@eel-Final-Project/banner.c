#include <stdio.h>
int banner() {
  FILE *banner;
  if ((banner = fopen("banner.txt", "r")) == NULL) {
    printf("File cannot be opened");
    return 1;
  } else {
    char c = fgetc(banner);
    while (c != EOF) {
      printf("%c", c);
      c = fgetc(banner);
    }
    fclose(banner);
    return 0;
  }
}