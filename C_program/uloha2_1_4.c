//tento program vypise id vaseho procesora pomocou asm
#include <stdio.h>

void cp_id(int *a, int *b, int *c) {
    
    __asm(

        "mov eax, 0;"
        "cpuid;"
        "mov %0, ebx;"
        "mov %1, edx;"
        "mov %2, ecx;"
        : "=r" (*a), "=r" (*b), "=r" (*c)
        : 
        :  "eax", "ebx", "ecx", "edx"
    );


    }

    int main() {
    char nazov[13];
    int a,b,c;

    cp_id(&a,&b,&c);

    *(int*)&nazov[0] = a;  
    *(int*)&nazov[4] = b; 
    *(int*)&nazov[8] = c;  
    nazov[12] = '\0';
    printf("%s", nazov);
    return 0;
}
