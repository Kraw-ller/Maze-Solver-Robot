#include <IR.h>
#include "Algorithm.h"
//#include "Motors.h"
//#include"UltraSonic.h"
#define d 1000
int A = 0;
int d1 = 300;
int d2 = 500;

void setup() 
{
    Serial.begin(9600);
    dclrUltrason();
    dclrEncoder();
    attachInterrupt(digitalPinToInterrupt(ENCL), readEcoder, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR), readEcoder, RISING);
}


void moveForwardTest()
{
    error = leftDistance() - rightDistance();
   
    error_sum = error * 7;
    speedR = constrain((80 + error_sum), 0, 80);
    speedL = constrain((80 - error_sum), 0, 80);

    Serial.print("SpeedR: ");
    Serial.println(speedR);
    Serial.print("  SpeedL: ");
    Serial.println(speedL);

    analogWrite(motorR1,speedR);
    analogWrite(motorL1,speedL);

}



void loop() 
{ 
  
   

moveForwardTest();

 if ((leftDistance() > minDistance )|| (rightDistance() > minDistance) || (frontDistance() < 4))
    {
        straight(80,100);
        
        stop();
        delay(300);
        
    if (leftDistance() > minDistance)
    {
        
        stop();
        path[counter] = 'L';
        counter++;
        turnL_P();
        
    }

    else if ((frontDistance() > minDistance) && (rightDistance() > minDistance))
    {
        path[counter] = 'S';
        counter++;
        straight(60,100);
    }
    else if (rightDistance() > minDistance)
    {
        
        
        path[counter] = 'R';
        counter++;
        turnR_P();
        

    }
    else if (frontDistance() < 4)
    {
        
        stop();
        delay(500);
        path[counter] = 'B';
        counter++;
        turn_180();
   }
   }






    }

