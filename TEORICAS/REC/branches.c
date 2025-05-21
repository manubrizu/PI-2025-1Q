#include <stdio.h>

int branches(int n, int h){
    if(n < h){
        return 0;
    }

    return 1 + 2 * branches(n/2, h);

}

int main(){
    printf("%d\n", branches(8, 2));
}