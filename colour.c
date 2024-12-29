#include"prof.h"

void give_colour_box(int width,int height){
        int b = 0, a = 0;  // initalize local variables

        for (a = 0; a != height; a++) {

                // fill the width
                for (b = 0; b != width; b++ ) {

                        if ((a == 0) || (a == height-1) || (b == width-1) || (b == 0)){  // put all * printing condition in one place
        //also, conditions, (a == height-1) and (b == width-1) to be used
                                printf("*");
                        }
                        else   // if not to print *, print space
                                printf(" ");
                }
                        printf("\n");
        }
}
