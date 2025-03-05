// tento program ipmlimentuje bitovy posun pomocou assembler


#include <stdio.h>

    int main(){

        int number;
        int shl;

        printf("Enter your number and power: ");
        scanf("%d %d", &number, &shl);

        __asm (

            "mov eax, %1;"
            "shl eax, %2;"
            "mov %0, eax;" 
            : "=r"(number)
            : "r"(number), "r"(shl)             
            : "eax"
            
        );

        printf("%d\n", number);

        return 0;
    }
