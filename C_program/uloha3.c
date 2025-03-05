//tento program implementuje prevod dex number to hex pomocou assambler


#include <stdio.h>

int main(){
    int number1;
    int hex_number;
    printf("Enter your number(0-15): ");
    do{
        scanf("%d", &number1);
    }while(number1 > 15 || number1 < 0);

    __asm (

        "mov eax, %1;"
        "cmp eax, 9;"
        "jle less;"
        "add eax, 87;"
        "jmp end;"
        "less:"
        "add eax, 48;"
        "jmp end;"

        "end:"
        "mov %0, eax;"
        : "=r"(hex_number)  
        : "r"(number1)       
        : "eax"
        
    );
    

    printf("%c\n", hex_number);
    return 0;
}
