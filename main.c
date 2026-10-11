#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

int main(){
    srand(time(NULL));
    char input[2] = {5,5}; //hight is the first # and width is the second # 
                            //not currently able to figure out how to get the inputs from the command line
    if(sizeof(input) != 2){ //checks to see if the number of arcuments is correct, if wrong iit will not continue
        printf("Wrong number of arguments");
        return 0;
    }
    char** canvas = createCanvas(input[0],input[1]); //assignes a blank box
    canvas = printCanvas(input[0],input[1],canvas); //reassignes the box and fills it with characters, it also prints it
    canvas = freeCanvas(canvas,input[0],input[1]); // frees up the canvas and also assign it to the orrigional canvas so its fully gone
    
}




