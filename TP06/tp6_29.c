#include <stdio.h>
#include <assert.h>
#include <string.h>

void deleteChars(char * s1, char * s2);

int main(void) {
    char s1[] = "abc";
    char s2[] = "axc123456789012345678901234567890";
    deleteChars(s1, s2);
    assert(strcmp(s1, "b") == 0);
    assert(strcmp(s2, "x123456789012345678901234567890") == 0);

    char s3[] = "Hola, soy un string";
    char s4[] = "Yo soy otro string";
    deleteChars(s3, s4);
    assert(strcmp(s3, "Hla, sy un string") == 0);
    assert(strcmp(s4, "Y soy tro string") == 0);

    char s5[] = "Hla, sy un string";
    char empty[] = "";
    deleteChars(s5, empty);
    assert(strcmp(s5, "Hla, sy un string") == 0);
    assert(strcmp(empty, "") == 0);

    char s6[] = "ABCDE";
    char s7[] = "abcde";
    deleteChars(s6, s7);
    assert(strcmp(s6, "ABCDE") == 0);
    assert(strcmp(s7, "abcde") == 0);

    char s8[] = "ABCDE";
    deleteChars(s8, s8);
    assert(strcmp(s8, "") == 0);

    puts("OK!");
    return 0;
}

void deleteChars(char * s1, char * s2){
    int i, j, k, l;
    k = l = 0;

    for (i = 0, j = 0; s1[i] && s2[j]; i++, j++){
        if(s1[i] != s2[j]){
            s1[k++] = s1[i];
            s2[l++] = s2[j];
        }
    }

    while (s1[i]){
        s1[k++] = s1[i++];
    }

    while (s2[j]){
        s2[l++] = s2[j++];
    }

    s1[k] = 0;
    s2[l] = 0;    
}