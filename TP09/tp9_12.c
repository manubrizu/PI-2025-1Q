#include <stdio.h>
#include <assert.h>

int balance(const char *s);

int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}

int balance(const char *s){
    if(*s=='\0'){
        return 0;
    }

    if(*s=='('){
        return balance(s+1) + 1;
    }        
    
    if(*s==')'){
        return balance(s+1) - 1;
    }

    return balance(s+1);
}