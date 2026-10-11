#ifndef CANVASMAKE_H
#define CANVASMAKE_H

int pickChar();     
			//unsure if pick char and get random char are suposed to be their own functions, in the canvasMake.c rubric it descreibes them seperatly but everywhere else it says that only create canvas, print canvas, and free canvas are supposed to be called

int getRandomChar(); //anyways, all this primes the computer to expect the functions so it dosent cry or something

char** createCanvas(int hight, int width);

char** printCanvas(int hight, int width, char** canvas);

char** freeCanvas(char **pointer, int hight, int width);

#endif
