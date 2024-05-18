//The C-sar (Caesar) cypher!

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *ptr;
  char ch;
  ptr = fopen("message.txt", "r");
  if (NULL == ptr) printf("no file!\n");
  printf("encrypted text:\n");

  do {
    ch = fgetc(ptr);
    char ch2;
    
    if (ch > 96 && ch < 123) {
      ch2 = (ch - 'a' + 3) % 26 + 'a';
      printf("%c", ch2); 
    }
    else if (ch > 64 && ch < 91) {
      ch2 = (ch - 'A' + 3) % 26 + 'A';
      printf("%c", ch2);
    }
    else printf("%c", ch);

  } while (ch != EOF);
 
  fclose(ptr);
  return 0;
}
