#include <SparkFun_ADXL345.h>


/*********** COMMUNICATION SELECTION ***********/
/*    Comment Out The One You Are Not Using    */
ADXL345 adxl = ADXL345(10);           // USE FOR SPI COMMUNICATION, ADXL345(CS_PIN);
//ADXL345 adxl = ADXL345();             // USE FOR I2C COMMUNICATION
int led = 8;
/******************** SETUP ********************/
/*          Configure ADXL345 Settings         */
void setup(){

Serial.begin(9600);                 // Start the serial terminal
//Serial.println("SparkFun ADXL345 Accelerometer Hook Up Guide Example");
//Serial.println();
pinMode(led,OUTPUT);
adxl.powerOn();                     // Power on the ADXL345

adxl.setRangeSetting(2);           // Give the range settings
                                    // Accepted values are 2g, 4g, 8g or 16g
                                    // Higher Values = Wider Measurement Range
                                    // Lower Values = Greater Sensitivity

adxl.setSpiBit(0);                  // Configure the device to be in 4 wire SPI mode when set to '0' or 3 wire SPI mode when set to 1
                                    // Default: Set to 1
                                    // SPI pins on the ATMega328: 11, 12 and 13 as reference in SPI Library 
}
/****************** MAIN CODE ******************/
/*     Accelerometer Readings and Interrupt    */
int x,y,z,timer = 11;
float gX, gY, gZ;
bool LED=false;
void loop(){

// Accelerometer Readings
adxl.readAccel(&x, &y, &z);         // Read the accelerometer values and store them in variables declared above x,y,z
gX = float(x-6)/274;
gY = float(y+4)/273;
gZ = float(z-198)/248;
if (gZ>0.02)
{ 
  LED =true;
  digitalWrite(led,HIGH);
  timer = 0;
  }
else if (timer<10)
{}
else
{
  LED =false;
  digitalWrite(led,LOW);
  timer =11;
  }
// Output Results to Serial
/* UNCOMMENT TO VIEW X Y Z ACCELEROMETER VALUES */
Serial.print(LED);
Serial.print(", ");  
Serial.print(gX,DEC);
Serial.print(", ");
Serial.print(gY,DEC);
Serial.print(", ");
Serial.println(gZ,DEC); 
delay(10);
timer = timer+1;
//ADXL_ISR();
// You may also choose to avoid using interrupts and simply run the functions within ADXL_ISR(); 
//  and place it within the loop instead.  
// This may come in handy when it doesn't matter when the action occurs. 

}
