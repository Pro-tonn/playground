#include <stdio.h>

void func(void){
    int x = 0xFFFFFFFE;
    printf("%d\n", x*5);
}

int main(void){
    func();
    return 0;
}
