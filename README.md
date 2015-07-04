# leddimmer
Dimmer for 7W LED, powered by 24Vdc

24V Dimmable LED driver
* for use with 21V/350mA LEDs, commonly found in 230V, GU10 LED bulbs
* Dimmable 0-100% in +20 discrete steps
* ON/OFF push button

The basis for this project was finding a new life for a broken GU10 7W LED bulb and a +€300 light fixture.

# Mechanics
The mechanics part of this project consists of a description of an assembly to mount the GU10 LED on the fixture and to add a lamp shade.
This assembly consists of two subparts, milled out of a 10mm Delrin sheet.

# Electronics
The broken 230V power circuit was removed, leaving only the plain 21V/350mA LED.  
In this way, a SELV 24Vdc power supply could be used to power the LED driver.  By keeping the hazardous voltages on the side of the power supply,
the design of the dimmer can be made without too much safety precautions.

# Firmware
It only checks for changes on the rotary encoder and then sets the PWM output for the LED accordingly.  There's no magic going on here.
