//http://thewanderingengineer.com/2014/08/11/rotary-encoder-on-the-attiny85-part-2/

#include "main.h"
#include "Bounce.h"

volatile int value = 122;

//avr pin to arduino port mapping can be found on: /home/ctack/sketchbook/hardware/tiny/cores/tiny/pins_arduino.c
byte pinSwitchOnOff=0;
byte pinEnc1=1;
byte pinSenseOnOff=2;
byte pinEnc2=3;
byte pinPwmOut=4;
Bounce boSwitchOnOff(pinSenseOnOff, 200);

void setup()
{
    // Initialize Arduino Libraries
    init();
    pinMode(pinSwitchOnOff, OUTPUT);
    pinMode(pinEnc1, INPUT_PULLUP);
    pinMode(pinSenseOnOff, INPUT_PULLUP);
    pinMode(pinEnc2, INPUT_PULLUP);
    pinMode(pinPwmOut, OUTPUT);
    digitalWrite(pinPwmOut, LOW);
    bitSet(PCMSK, pinEnc1);
    bitSet(PCMSK, pinEnc2);
    bitSet(GIMSK, PCIE);
    digitalWrite(pinSwitchOnOff, HIGH);
    sei();                    // Turn on interrupts
}

void loop(){
    boSwitchOnOff.update();
    if(boSwitchOnOff.fallingEdge()){
       digitalWrite(pinSwitchOnOff, LOW);
    }
    analogWrite(pinPwmOut, value);
}

// This is the ISR that is called on each interrupt
// Taken from http://bildr.org/2012/08/rotary-encoder-arduino/
// /usr/avr/include/avr/iotnx5.h
ISR(PCINT0_vect)
{
    static byte lastEncoded = 0;
    byte MSB = digitalRead(pinEnc1); //MSB = most significant bit
    byte LSB = digitalRead(pinEnc2); //LSB = least significant bit

    int encoded = (MSB << 1) | LSB; //converting the 2 pin value to single number
    byte sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

    if((sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) && value>0){
        value--;
    }
    if((sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) && value<255){
        value++;
    }
    lastEncoded = encoded; //store this value for next time

}
