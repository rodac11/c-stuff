//The Vignere!

#include <stdio.h>
#include <stdlib.h>

//because of textfile shenanigans, the key can use anything but \n
//since that's what's used to check if the pointer should rewind
int getOffset(FILE* ptr)
{
  int ret;
  char tmp;
  tmp = fgetc(ptr);

   if(tmp == '\n'){
     rewind(ptr);
      tmp = fgetc(ptr);
   }

    if (tmp > 64 && tmp < 91){
      ret = (tmp - 'A' ) % 26;
    }
    else if (tmp > 96 && tmp < 123){
      ret = (tmp - 'a' ) % 26;
    }
    else {
      ret = 0;}

    return ret;  
}

void encrypt(FILE* t_ptr, FILE* k_ptr)
{
  char ch;
  char ch2;
  int i;
do {
  
  ch = fgetc(t_ptr);
  i = getOffset(k_ptr);
  
    if (ch > 96 && ch < 123) {
      ch2 = (ch - 'a' + i) % 26 + 'a';
          printf("%c", ch2);
    }
    else if (ch > 64 && ch < 91) {
      ch2 = (ch - 'A' + i) % 26 + 'A';
        printf("%c", ch2);
    }

    //prints original char as is, key goes on char back to not get skipped
    else {
      printf("%c", ch);
      fseek(k_ptr, -1, SEEK_CUR);
    }
    
  } while (ch != EOF);
 
  fclose(t_ptr);
  fclose(k_ptr);
  return;
}

int main()
{
  FILE *t_ptr;
  FILE *k_ptr;
  t_ptr = fopen("textfiles/v-message.txt", "r");
  k_ptr = fopen("textfiles/v-key.txt", "r");
  
  if (NULL == t_ptr || NULL == k_ptr) {
    printf("missing text or key!");
    return 1;
  }
  printf("encrypted text:\n");

  
  encrypt(t_ptr, k_ptr);
  return 0;
}


