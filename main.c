#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pickChar(){
    char options[7] = {'*','-','#','%','&','0','<'}; //"list" of characters
    int num = rand()%7; //picks from spot 0-6 which is all the characters
    char pick = options[num];
    return pick;
}
int getRandomChar(){
    int chance = rand()%10; //gives me a 1 in 10 chance (0-9)
    
    if(chance>-1 && chance<8){ //if its between -1 and 8 its looking at 0-7 inclusive which out of 9 is an 80% chance of happening
        char space = ' '; //80% chance to be an empty space
        return space;
    }
    if(chance>7 && chance<11){ // between 7 and 11 is 8-10 inclusive which out of 9 is 20% chance of heppening
        char thing = pickChar(); // 20% chance to be a random character  ---------- I realize that 8,9,10 is three chances but the random int dosent get to 10 so its effectivly 8,9
    }                                                           //I will not fix this^, it dosent change the functionally and I dont want to risk it
}

char** createCanvas(int hight, int width){ 
    char** canvas =malloc(hight*sizeof(char*)); //assign the starting slots (Hight)
    
    for(int count = 0; count < hight; count++){ //assign the amount in each of the slots established(Width)
        canvas[count] = malloc(width*sizeof(char*));
    }
    
    return canvas;
}

char** printCanvas(int hight, int width, char** canvas){
    for(int count = 0; count < width; count++){ //makes an easy marker for the top of the box
        printf("-");
    }
    printf("\n");
    
    for(int countH = 0; countH < hight; countH++){ //goes through each slot one by one and uses the get character function I made to assign it
        for(int countW = 0; countW < width; countW++){
            canvas[countH][countW] = getRandomChar();
        }
    }
    
    for(int countH = 0; countH < hight; countH++){//prints it in the same way the slots were assigned but this time its printed intsead of assigned
        for(int countW = 0; countW < width; countW++){
            printf("%c",canvas[countH][countW]);
        }
        printf("\n");
    }
    for(int count = 0; count < width; count++){ //makes a good marker for the end of the box
        printf("-");
    }
    printf("\n");
    
    return canvas;
}

char** freeCanvas(char **pointer, int hight, int width){
    for(int countH = 0; countH < hight; countH++){ //frees up the hight ones which should include the width
            free(pointer[countH]);
    }
    free(pointer); //frees up the last bit
    return pointer;
}

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

