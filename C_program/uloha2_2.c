//tento program je vzorec pre pracu z polami(char a int), praca z ich pointerami

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vypis_char_address(char* p_pole){
    printf("Adresa pola znakov: %p\n", p_pole);
}

void vypis_int_address(int* p_pole){
    printf("Adresa pola cisel: %p\n", p_pole);
}

void vypis_int(int *int_pole){
    printf("Vypis pola cisel: ");
    for(int i = 0; i < 32; i++){
        printf("%d ", int_pole[i]);
    }
    printf("\n");
}

void vypis(char *pole, int dlzka){
    printf("Vypis pola znakov: ");
    for(int i = 0; i < dlzka; i++){
            printf("%c", pole[i]);
        
    }
    printf("\n");
    }

    int main(){

        char pole[100];
        int int_pole[32] = {3,2,2};
        char* p_pole = pole;
        int* p_int_pole = int_pole;

        strcpy(pole, "architektura_pocitacov_je_super_predmet");
        int dlzka = strlen(pole);

        vypis(pole, dlzka);
        vypis_int(int_pole);

        vypis_char_address(p_pole);
        vypis_int_address(p_int_pole);

        p_pole++;
        p_int_pole += 10;

        vypis_char_address(p_pole);
        vypis_int_address(p_int_pole);
        
        *p_pole = '&';
        *p_int_pole = 777;
        
        vypis(pole, dlzka);
        vypis_int(int_pole);

        //p_pole += 1000000;
        //p_int_pole += 1000000;
        //*p_pole = '*';
        //*p_pole = 888;



        return 0;
    } 
