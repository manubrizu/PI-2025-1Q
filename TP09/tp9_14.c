#include <stdio.h>

int apareados(const char *s){
    if(*s=='\0'){
        return 0;
    }

    if(apareados(s+1)>0){
        return apareados(s+1);
    }

    if(*s=='('){
        return apareados(s+1) + 1;
    }        
    
    if(*s==')'){
        return apareados(s+1) - 1;
    }

    return apareados(s+1);

}

int main(){
    printf("%d\n", apareados("()(()())")); // 0
    printf("%d\n", apareados(")("));       // 1
    printf("%d\n", apareados(""));         // 0
    printf("%d\n", apareados("()("));      // 1
    printf("%d\n", apareados("(()())"));   // 0
    printf("%d\n", apareados("()())"));    // -1

    return 0;
}
