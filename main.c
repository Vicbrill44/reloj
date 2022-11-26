#include "display.h"

int main(void) {
    open_display();
    
    int hours;
    int minutes;
    int seconds;

    while((scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3)){
        display_time(hours, minutes, seconds);
    }

    close_display();

    return 0;
}
