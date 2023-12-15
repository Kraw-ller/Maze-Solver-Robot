#include <Arduino.h>

#define trigPinL A2
#define echoPinL A0

#define trigPinR 13
#define echoPinR 12

#define trigPinF A4
#define echoPinF A3


float duration;
float distance;


void dclrUltrason()
{
    pinMode(trigPinL, OUTPUT);
    pinMode(echoPinL, INPUT_PULLUP);
    pinMode(trigPinR, OUTPUT);
    pinMode(echoPinR, INPUT_PULLUP);
    pinMode(trigPinF, OUTPUT);
    pinMode(echoPinF, INPUT_PULLUP);
}

float leftDistance()
{
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    duration = pulseIn(echoPinL, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}

float rightDistance()
{
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    duration = pulseIn(echoPinR, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}
float frontDistance()
{
    digitalWrite(trigPinF, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinF, LOW);
    duration = pulseIn(echoPinF, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}