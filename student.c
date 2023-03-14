//***************************************
//** SUBMIT ONLY THIS FILE
//** DO NOT CHANGE ANYTHING
//** ONLY ADD THE IMPLEMENTATION
//***************************************
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

//****************** Q1 ******************
#define WIDTH 14
#define HEIGHT 2

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
double line_segment_distance(int x1,int y1,int x2,int y2,int x3,int y3)
{
    double sqr_length = pow((x2 - x1),2) + pow((y2 - y1),2); // squared length of line segment

    if(sqr_length == 0) // length of segment is 0, return distance between c and any of a or b
        return sqrt(pow(x3-x2,2) + pow(y3-y2,2));

    double proj_t = ((y2 - y1) * (y3 - y1) + (x2 - x1) * (x3 - x1)) / sqr_length; // t val for projection c over ab

    if(proj_t < 0) // c is outside of the segment, nearest point is a
        return sqrt(pow(x3-x1,2) + pow(y3-y1,2));

    if(proj_t > 1) // c is outside of the segment, nearest point is b
        return sqrt(pow(x3-x2,2) + pow(y3-y2,2));

    double proj_x = proj_t * (x2 - x1) + x1; // projection x
    double proj_y = proj_t * (y2 - y1) + y1; // projection y

    return sqrt(pow(x3-proj_x,2) + pow(y3-proj_y,2)); // distance between c and projection point
}
