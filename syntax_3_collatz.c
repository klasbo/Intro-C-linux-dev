#include <stdio.h>

void collatz(int n){
    while(n != 1){
        if(n % 2 == 0){
            n = n/2;
        } else {
            n = 3*n + 1;
        }
        printf("%-3d ", n);
    }
    printf("\n");
}

int main(){    
    for(int n = 1; n < 10; n++){
        collatz(n);
    }
}
