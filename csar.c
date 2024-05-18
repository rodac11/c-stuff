//The C-sar (Caesar) cypher!

#include <stdio.h>
#include <string.h>

void encrypt(FILE* ptr)
{
  char ch;
do {
    ch = fgetc(ptr);
    char ch2;
    
    if (ch > 96 && ch < 123) {
      ch2 = (ch - 'a' + 3) % 26 + 'a';
      printf("%c", ch2);
    } else  if (ch > 64 && ch < 91) {
      ch2 = (ch - 'A' + 3) % 26 + 'A';
      printf("%c", ch2);
    }
    else printf("%c", ch);

  } while (ch != EOF);
 
  fclose(ptr);
  return;
}



int main(int argc, char **argv)
{
  FILE *ptr;
  ptr = fopen("textfiles/message.txt", "r");
  if (NULL == ptr) printf("no file!\n");
  printf("encrypted text:\n");
  encrypt(ptr);
  
  return 0;
}


