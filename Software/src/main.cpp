//http://thewanderingengineer.com/2014/08/11/rotary-encoder-on-the-attiny85-part-2/

#include "main.h"
#include "Bounce.h"

volatile int value = 122;
Bounce boSwitchOnOff(0, 50);
bool bLightOn;

void setup()
{
    // Initialize Arduino Librairies
    init();
    pinMode(1, OUTPUT);
    pinMode(0, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    bitSet(PCMSK, 3);
    bitSet(PCMSK, 4);
    sei();                    // Turn on interrupts
}

void loop(){
    boSwitchOnOff.update();
    if(boSwitchOnOff.fallingEdge()){
        bLightOn=(bLightOn?false:true);
        bitWrite(GIMSK, PCIE, bLightOn);
    }
    analogWrite(1, bLightOn?value:255);
}

// This is the ISR that is called on each interrupt
// Taken from http://bildr.org/2012/08/rotary-encoder-arduino/
// /usr/avr/include/avr/iotnx5.h
ISR(PCINT0_vect)
{
    static byte lastEncoded = 0;
    byte MSB = digitalRead(3); //MSB = most significant bit
    byte LSB = digitalRead(4); //LSB = least significant bit

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
