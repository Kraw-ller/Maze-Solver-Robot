#include <Arduino.h>
#include "Motors.h"
#include <stdlib.h>



#define minDistance 17
char path[50];
char path_op[50];
int i=0, j=0, counter = 0;

bool left = (leftDistance() >= minDistance);
bool front_right = (frontDistance() >= 6 && rightDistance() >= minDistance);
bool right = (rightDistance() >= minDistance);
bool dead_end = (frontDistance() <= 6);
bool intersection = (frontDistance() >= minDistance || rightDistance() >= minDistance || leftDistance() >= minDistance);


void LSRB()

{


 if ((leftDistance() > minDistance )|| (rightDistance() > minDistance) || (frontDistance() < 7))
    {
        
        delay(250);
        stop();
        
    if (leftDistance() > minDistance)
    {
        delay(100);
        path[counter] = 'L';
        counter++;
        turnL_P();
        straight(60, 700);
    }

    else if (frontDistance() > minDistance && rightDistance() > minDistance)
    {
        path[counter] = 'S';
        counter++;
        straight(80,700);
    }
    else if (rightDistance() > minDistance)
    {
        delay(100);
        path[counter] = 'R';
        counter++;
        turnR_P();
        straight(60,700);

    }
    else if (frontDistance() < 7)
    {
        
        stop();
        delay(500);
        path[counter] = 'B';
        counter++;
        turn_180();
   }
   }
}


void LSRB_OP()
{
    for (i = 0, j = 0; i < counter; j++)
    {
        if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='R')
        {
            path_op[j] = 'B';
            i = i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='S')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='R' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'B';
            i=i+3;
        }
        else if (path[i]=='S' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'S';
            i=i+3;
        }  
        else //in case none of the optimisations is possible
        {
            path_op[j] = path[i];
            i++;
        }
    }
}



void shortestPath()
{
    moveForward();

    if(leftDistance() > minDistance || rightDistance() > minDistance || frontDistance() < 7)
    {
        if(path_op[j] == 'L')
        {
            delay(100);
            turnR_P();
            straight(60,700);
            j--;
            
        }
        else if (path_op[j] == 'S')
        {
           
            delay(100);
            straight(80,700);
            j--;
        }
        else if (path_op[j] == 'R')
        {
            delay(100);
            turnL_P();
            straight(60,700);
            j--;
        }
    }
}





/*

void shortPath()  // while running
{
    if (path[counter] == '?' && path[counter-1] == '?' && path[counter-2] == '?')
        counter-=2;
        path[counter] = '?'
}


turnLeft();
path[counter] = 'L';

if (counter >= 2)
{
    shortPath();
}
counter++;
*/

