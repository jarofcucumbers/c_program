//tento program ipmlimentuje sucet pomocou asembler cast na c

#include <stdio.h>

    int main(){

        int num1, num2, sum;

        printf("Enter your numbers: ");
        scanf("%d %d", &num1, &num2);

        __asm (

            "mov eax, %1;"
            "add eax, %2;"
            "mov %0, eax;"
            : "=r"(sum)                // output %0
            : "r"(num1), "r"(num2)     // input %1, %2
            : "eax"
        );

        printf("%d + %d = %d\n", num1, num2, sum);

        return 0;
    }
