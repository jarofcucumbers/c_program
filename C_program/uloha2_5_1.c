//toto je trochu hardkod ktory vypisuje cisla z indexom 00 roznymy farbami

#include <stdio.h>
#include <unistd.h>
// \033[31m \033[0m]
int main() {
    

    int number = 0;
    printf("Zadaj cislo: ");
    scanf("%d", &number);
    int counter = 1;
    for(int i = 0; i <= number; i++) {
        if(counter == 10){
            counter = 1;
        }
        
        if(counter <= 3){
            if(i < 10){
                usleep(100000);
                printf("\033[31m00\033[0m" );
            }
            else if(i < 100){
                usleep(100000);
                printf("\033[31m0\033[0m" );
            }
            usleep(100000);
            printf("\033[31m%d\033[0m\n", i);
            counter++;
        }
            else if(counter <= 6){
            if(i < 10){
                usleep(100000);
                printf("\033[32m00\033[0m" );
            }
            else if(i < 100){
                usleep(100000);
                printf("\033[32m0\033[0m" );
            }
            usleep(100000);
            printf("\033[32m%d\033[0m\n", i);
            counter++;
        }
            else if(counter <= 9){
            if(i < 10){
                usleep(100000);
                printf("\033[33m00\033[0m" );
            }
            else if(i < 100){
                usleep(100000);
                printf("\033[33m0\033[0m" );
            }
            usleep(100000);
            printf("\033[33m%d\033[0m\n", i);
            counter++;
        }
    }
       return 0; 
    }
   
