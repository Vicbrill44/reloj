#include "display.h"
#include <ncurses.h>

#define YELLOW 4
#define BLUE 3
#define RED 2
#define WHITE 1
#define BLACK 0

int open_display(void){
    initscr();
    int num;

    if(initscr() == NULL) {
        num = 0;
    }
    else {
        num = 1;
    }

    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);

    return num;

}

void display_time(int hours, int minutes, int seconds) {
    
    attron(COLOR_PAIR(WHITE));
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            attron(COLOR_PAIR(WHITE));
            mvaddch(y,x,'#');
        }
    }
    clear();
    refresh;

    display_colons();
    refresh();
    display_hours(hours);
    refresh();
    display_minutes(minutes);
    refresh();
    display_seconds(seconds);
    refresh();
    //attron(COLOR_PAIR(WHITE));


}



void display_colons(void) {

    attron(COLOR_PAIR(WHITE));
    //these are the coords on the grid in which we will place the colons 
    mvaddch(6,2,'#');
    mvaddch(6,3,'#');
    mvaddch(6,5,'#');
    mvaddch(6,6,'#');
    mvaddch(5,2,'#');
    mvaddch(5,3,'#');
    mvaddch(5,5,'#');
    mvaddch(5,6,'#');
    mvaddch(3,2,'#');
    mvaddch(3,3,'#');
    mvaddch(3,5,'#');
    mvaddch(3,6,'#');
    mvaddch(2,2,'#');
    mvaddch(2,3,'#');
    mvaddch(2,5,'#');
    mvaddch(2,6,'#');

    refresh();
}

void display_hours(int hours){
    //hrsToBinary will hold the 1's and 0's used for binary
    int hrsToBinary[6];
    
    int hrs = hours;
    
    // indx will hold the value of the hrsToBinary array  
    int indx = 0;
   
    //This algorithm will fill the hrsToBinary array with the 1's and 0's. It will take 
    //advantage of integer division as well as modulo. 
    while (hrs != 0){
        if (hrs % 2 == 0){
            hrsToBinary[indx] = 0;
        }
        else{
            hrsToBinary[indx] = 1;
        }
        
        //Cut the hrs in half to proceed on with finding the next binary number
        hrs = hrs / 2;
       
        //Add 1 to the index for the next iteration  
        indx = indx + 1;
    }
    
    //Once we have all the binary numbers in the array, we will fill up the grid
    
    //Will fill up the hours column with the color blue 
    attron(COLOR_PAIR(BLUE));
    int row = 7;    //starting at row 7, ones place
    for(int k = 0; k < 6; k++){
        if(hrsToBinary[k] == 1){
            //Will color in if encounters a 1 in array 
            mvaddch(row,1,'#');
        }

        //move up a row
        row = row - 1;
    }
    refresh();

}

void display_minutes(int minutes){
    int minsToBinary[6];
    int mins = minutes;
    int indx = 0;

    while(mins != 0) {
        if(mins % 2 == 0){
            minsToBinary[indx] = 0;
        }
        else{
            minsToBinary[indx] = 1;
        }
        mins = mins / 2;
        indx = indx + 1;

    }
    attron(COLOR_PAIR(YELLOW));
    int row = 7;
    for (int k = 0; k < 6; k++){
        if(minsToBinary[k] == 1){
            mvaddch(row, 4, '#');
        }
        row = row - 1;
    }
    refresh();
}

void display_seconds(int seconds){
    int secToBinary[6];
    int sec = seconds;
    int indx = 0;
    while(sec != 0) {
        if(sec % 2 == 0){
            secToBinary[indx] = 0;
        }
        else{
           secToBinary[indx] = 1;
        }
        sec = sec / 2;
        indx = indx + 1;
    }
    attron(COLOR_PAIR(RED));
    int row = 7;
    for (int k = 0; k < 6; k++){
        if(secToBinary[k] == 1){
            mvaddch(row, 7, '#');
        }
        row = row - 1;
    }
    refresh();
}





void close_display(void){
    
    clear();
    refresh();
    sleep(1);
    endwin();

}






/*

void display_time(int hours, int minutes, int seconds){
    //code goes here
 
}

void display_colons(void) {
     //code goes here

}

void display_hours(int hours) {
    //code goes here

}

void display_minutes(int minutes) {
    //code goes here

}

void display_seconds(int seconds) {
    //code goes here

}

void close_display(void) {
    //code goes here

}
*/
