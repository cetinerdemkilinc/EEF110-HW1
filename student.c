//***************************************
//** SUBMIT ONLY THIS FILE
//** DO NOT CHANGE ANYTHING
//** ONLY ADD THE IMPLEMENTATION
//***************************************
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

//****************** Q1 ******************
#define WIDTH 140
#define HEIGHT 20

void generateSine()
{
    for(int curr_height = HEIGHT*2 ; curr_height>=0 ; curr_height--){
        double real_pos = asin((double)(2*curr_height) / (HEIGHT*2) -1); // between -pi/2 and +pi/2
        double pos_on_grid = (WIDTH*real_pos) / (M_PI*2); // map arcsin value to our grid sizes
        int number_of_spaces = 0;
        if(pos_on_grid < 0) { // this mean arcsin value is between -pi/2 and 0, but we need to draw this interval between pi and 2pi
            pos_on_grid += WIDTH;
            number_of_spaces = pos_on_grid; // get the integer part
            number_of_spaces = WIDTH - number_of_spaces -1 + WIDTH/2;
            for(int i=0 ; i<number_of_spaces ; i++) putchar(' '); // pi to 3pi/2 interval
            printf("*");

            number_of_spaces = (int)pos_on_grid - (number_of_spaces + 1);
            for(int i=0 ; i<number_of_spaces ; i++) putchar(' '); // 3pi/2 to 2pi interval
            if(number_of_spaces>0)printf("*");
        }
        else{
            number_of_spaces = pos_on_grid; // get the integer part
            for(int i=0 ; i<number_of_spaces ; i++) putchar(' '); // 0 to pi/2 interval
            printf("*");

            number_of_spaces = (WIDTH/2) - (number_of_spaces*2 + 2);
            for(int i=0 ; i<number_of_spaces ; i++) putchar(' '); // pi/2 to pi interval
            if(number_of_spaces>0)printf("*");
        }
        putchar('\n');
    }
}

//****************** Q2 ******************
// double line_segment_distance(int x1,int y1,int x2,int y2,int x3,int y3)
// {
//     //implementation goes here
//     return 0;
// }
