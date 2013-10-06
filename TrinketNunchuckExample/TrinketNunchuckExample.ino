/*
*
 * TrinketNunchuckDemo -- 
 *
 * Original library for ATMega chips by: Tod E. Kurt, 2008 , http://thingm.com/
 *
 * Port to Adafruit Trinket by Andrew H. Meyer "PyroAVR", 10/5/2013
 ***INSTRUCTIONS***
 * Connect DATA to #0 on Trinket
 * Connect CLK to #2 on Trinket
 * Don't forget to add a level shifter that is I2C capable if you have the 5V Trinket!
 *
 */

#include <TinyWireM.h>
#include "TrinketNunchuck.h"

#define ledtestpin 1

int loop_cnt=0;

byte accx,accy,zbut,cbut,joyX;

void setup()
{
    nunchuck_init(); // send the initilization handshake
    //pinMode(ledtestpin, OUTPUT);
}

void loop()
{
    if( loop_cnt > 100 ) { // every 100 msecs get new data
        loop_cnt = 0;

        nunchuck_get_data();

        accx  = nunchuck_accelx(); // ranges from approx 70 - 182
        accy  = nunchuck_accely(); // ranges from approx 65 - 173
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton();
        joyX = nunchuck_joyx();
    }
    analogWrite(ledtestpin, joyX);
    
    loop_cnt++;
    delay(1);
}

