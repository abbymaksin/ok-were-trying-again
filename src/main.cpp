#include <Arduino.h>
  // make it constant
#define trig 2 // same as line 3
#define echo 3
unsigned long t0=0;
unsigned long t1=0;
unsigned long t2=micros ();


// this runs when the echo changes
void interrupt_function(){

// if rising, measure the time with micros and store it in t1
// if falling, measure the time with micros, store it in t2, calculate t2-t1 and print it
    if(digitalRead(echo)==HIGH){

        Serial.println("Its rising");
        t1= micros();
    }
    else {
        t2=micros();
        Serial.println(343*(t2-t1)/2*pow(10, -4)); //343 is the speed of sound in units of meters per second- converts distance to centimeters
    }
// print if it is rising, otherwaise print it's falling

    Serial.println("Hello Im an interrupt");
}
void setup(){
//setup serial and pins for trigger, input, output, etc
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.println ("Hi Dr.Nironi!!!:)");
// unsigned no sign, positive
// long: an int with twice memory

attachInterrupt(digitalPinToInterrupt(echo),interrupt_function,CHANGE);
//attaches interrupt function to run when the echo changes
}


void loop(){

if(millis()-t0>500){ // If 0.5 second has passed
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