/*toto je program ktory nacita vstup z klavesnici v real time a pracuje z tim(mam tu 2 moznych rezima manual a challeng)

*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>


void chalenge_press_button(bool additionInfo, int y, int x){
        struct timespec start, end;
        srand(time(NULL));
        int ch = 65;
        int r_ch = 97;
        clear();
        int count = 0;
        double alltime = 0;

        mvprintw(y, x, "Challenge mode (F2 = start, F3 = end, ESC/F10 = EXIT)\n");
        mvprintw(y + 1, x, "Press any key to start\n");
        ch = getch();
        clear();
        while (ch != 27 && ch != KEY_F(10)) {  // 27 - ESC
        int r_ch = 97 + (rand() % 26);
        
        mvprintw(y,x,"Press: %c\n", r_ch);
        refresh();
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        do{
            ch = getch();
            if(ch == 27 || ch == KEY_F(10)){
                break;
            }
        }while(ch != r_ch);
        
        clock_gettime(CLOCK_MONOTONIC, &end);   
        
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000;
        
        printw("You press: %c for %.3f milisecond(%.1f second)\n", ch, elapsed_time, elapsed_time / 1000);
        if(additionInfo == true){
            printw("(dex: %d, hex: %x, char: %c)\n", ch, ch, ch);
        }
    
        count++;
        alltime += elapsed_time;
        clear();
        refresh();
        
        

    
    }
        printw("Chalenge mode end\n");
        printw("====================================\n");
        printw("Result:\n");
        printw("You press %d times\n", count);
        printw("All time: %.3f milisecond(%.1f second)\n", alltime, alltime / 1000);
        printw("Average time: %.3f milisecond(%.1f second)\n", alltime / count, alltime / count / 1000);
        printw("====================================\n");
        printw("\nPress any key to continue\n");
        refresh();
        ch = getch();
}

void press_button(bool additionInfo, int y, int x){
    struct timespec start, end;
        
        int ch = 65;
        clear();

        mvprintw(y, x,"Timer mode: Press any key to start timer(clear = F7)\n");
        
        
        
        while (ch != 27 && ch != KEY_F(10)) {  // 27 - ESC
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        ch = getch();
        
        clock_gettime(CLOCK_MONOTONIC, &end);   
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000;
        
        printw("You press: %c for %.3f milisecond(%.1f second)\n", ch, elapsed_time, elapsed_time / 1000);
        if(additionInfo == true){
            printw("(dex: %d, hex: %x, char: %c)\n", ch, ch, ch);
        }
        
        refresh();
        
        if(ch == KEY_F(7)){
            clear();
            mvprintw(y,x,"Timer mode: Press any key to start timer(clear = F7)\n");
            refresh();
        }

        
    }
}

int main() {
    initscr();            
    noecho();           
    cbreak();             
    keypad(stdscr, TRUE); 
    curs_set(0);
    
    bool additionInfo = false;
    int ch = 65;
    int x = 10, y = 5;
    
    getmaxyx(stdscr, y, x);

    while(ch != 27 && ch != KEY_F(10)) {
        clear();
        mvprintw((y/3),(x/3),"\tKEYBORD WORLD: \n");
        mvprintw((y/3) + 1,(x/3),"1. Timer\n");
        mvprintw((y/3) + 2,(x/3),"2. Addition info mode\n");
        mvprintw((y/3) + 3,(x/3),"3. Chalange mode\n");
        mvprintw((y/3) + 4,(x/3), "4. Exit\n");

        
        ch = getch();

        switch(ch){
            case 49:
                press_button(additionInfo, y / 3, x / 3);
                break;
            case 50:
                additionInfo = !additionInfo; 
                clear();
                mvprintw(y/3,x/3,"Addition info mode is now %s\n", additionInfo ? "ON" : "OFF");
                refresh();
                sleep(1);   
                break;
            case 51:
                chalenge_press_button(additionInfo,y / 3,x / 3);
                break;    
            case 52:
                printw("Bye!\n");
                sleep(1);
                ch = 27;
                break;
            

        }
    }

    endwin();  
    return 0;
    
    }
