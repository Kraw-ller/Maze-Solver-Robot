#include <Arduino.h>
#include <Ultrasonic.h>
#include <math.h>
#include <Compass.h>
#include <Encoder.h> 

#define motorR1 11
#define motorR2 10

#define motorL1 9
#define motorL2 12


#define speed_limit 60
#define error_limit 1.5
#define speed1 100
#define speed2 85
#define speed0 60

float error;
int kp =5;
float error_sum;
float speedR, speedL;


void dclrMotors()
{
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
}

void moveForward()
{
    error = leftDistance() - rightDistance();
   
        error_sum = error * kp;
        speedR = constrain((error_sum + 80), 0, 80);
        speedL = constrain((80 - error_sum), 0, 80
        );
        Serial.print("SpeedR: ");
        Serial.println(speedR);
        Serial.print("  SpeedL: ");
        Serial.println(speedL);

        analogWrite(motorR1,speedR);
        analogWrite(motorL1,speedL);

}

void straight(int x, int y)
{
    analogWrite(motorR1,x);
    analogWrite(motorL1,x);
    delay(y);
}

void moveBackward()
{
    analogWrite(motorR1, 0);
    analogWrite(motorR2, 80);
    analogWrite(motorL1, 0);
    analogWrite(motorL2, 80);
}
void stop()
{
    digitalWrite(motorR1, 0);
    digitalWrite(motorR2, 0);
    digitalWrite(motorL1, 0);
    digitalWrite(motorL2, 0);
}

void turnR_P()
{
    
   int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    
        
    
     while ( stepsL - stepsL_now < 6 and stepsR - stepsR_now < 6 )
    {
        error = abs(leftDistance() - rightDistance());
   
    error_sum = error * 7;
    speedL = constrain((70 + error_sum), 0, 80);
    speedR = constrain((70 - error_sum), 0, 80);

    Serial.print("SpeedR: ");
    Serial.println(speedR);
    Serial.print("  SpeedL: ");
    Serial.println(speedL);

    analogWrite(motorR1,speedR);
    analogWrite(motorL1,speedL);

    }
    
        stop();
    
}

void turnL_P()
{
    int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    
        
    
     while ( stepsL - stepsL_now < 7 and stepsR - stepsR_now < 7 )
    {
        error = abs(leftDistance() - rightDistance());
   
    error_sum = error * 7;
    speedR = constrain((70 + error_sum), 0, 80);
    speedL = constrain((70 - error_sum), 0, 80);

    Serial.print("SpeedR: ");
    Serial.println(speedR);
    Serial.print("  SpeedL: ");
    Serial.println(speedL);

    analogWrite(motorR1,speedR);
    analogWrite(motorL1,speedL);

    }
    
        stop();
    
}

void turn_180()
{
    int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    
        analogWrite(motorL1, 80);
        analogWrite(motorL2, 0);
        analogWrite(motorR1, 0);
        analogWrite(motorR2, 80);
        while ((stepsL - stepsL_now < 10) and (stepsR - stepsR_now < 10))
    {
        delay(1);
    }
    
        stop();
}





void selfCenter()
{
    

}



void ready()
 {
    analogWrite(motorR1, 50);
    analogWrite(motorR2, 0);
    analogWrite(motorL1, 50);
    analogWrite(motorL2, 0);
    
}



/*

void turnR_P()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 90 && abs(tmpY - compassY()) < 90)
    {
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    }
}

void turnL_P()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 90 && abs(tmpY - compassY()) < 90)
    {
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    }
}

void turn_180()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 180 && abs(tmpY - compassY()) < 180)
    {
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    }
}

*/
