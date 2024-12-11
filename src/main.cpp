#include <Arduino.h>
  // make it constant
#define trig 2 // same as line 3
#define echo 3
int t0=0;
unsigned long t1=0;
int t2=micros ();


// void output and input
void interrupt_function(){

// if rising, measure the time with micros and store it in t1
// if falling, measure the time with micros, store it in t2, calculate t2-t1 and print it
    if(digitalRead(echo)==HIGH){

        Serial.println("Its rising");
        t1= micros();
    }
    else {
        t2=micros();
        Serial.println(343*(t1-t2)/2*pow(10, -4));
    }
// print if it is rising, otherwaise print it's falling

    Serial.println("Hello Im an interrupt");
}
void setup(){

Serial.begin(115200);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

attachInterrupt(digitalPinToInterrupt(echo),interrupt_function,CHANGE);

}

// unsigned no sign, positive
// long: an int with twice memory

void loop(){

if(millis()-t0>100){ // If 0.1 second has passed
    digitalWrite(trig,HIGH);
    // delay(0.01);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    t0=millis();
}
}
    // delay(100);   

 // step 1: take the time using millis, store it in t0
 // step 2:take the time later, and if t-t0 is more than 100, 100ms have passed)