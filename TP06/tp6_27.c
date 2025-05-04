#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHARS_DIM 256

int analize(const char * text, char * chars);

int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}

int analize(const char * text, char * chars){
    int len = strlen(text);
    char apariciones[CHARS_DIM] = {0};

    for (int i = 0; i < len; i++){
        if(!apariciones[(int) text[i]]){
            apariciones[(int) text[i]] = 1;
        }
    }
    int cant = 0;

    for (int i = 0; i < CHARS_DIM; i++){
        if(apariciones[i]){
            chars[cant++] = i;
        }
    }
    chars[cant] = '\0';
    return cant;
}

