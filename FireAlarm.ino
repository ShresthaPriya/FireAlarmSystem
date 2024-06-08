#This program is built for the fire alarm system using smoke sensor, the buzzer and the led 
activates when the sensor value exceeds the pre-defined threshold else, they remain inactive.
//include the libraries
#include <Wire.h> //for I2C communication
#include <LiquidCrystal_I2C.h> // to control LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address (0x27) if necessary
//define the pin configuration for led, buzzer and sensor analog pin
#define LED 2
#define Buzzer 3
#define Sensor A1
void setup() {
 Serial.begin(9600); //initializing the serial baud rate of 9600
 lcd.begin(); //prepare LCD module to communicate with microcontroller
 lcd.backlight(); //to ensure the display is visible
  pinMode(LED, OUTPUT); //setting output pin mode for the LED
 pinMode(Buzzer, OUTPUT); // setting output pin mode for the LED
}
void loop() {
 int value = analogRead(Sensor); //read analog value from analog pin on arduino
 Serial.print("Sensor value: "); //print the sensor value
 Serial.println(value);
 lcd.setCursor(0, 0); //top left position
 lcd.print("Smoke Level: "); //print the value of the smoke level in lcd display
 lcd.print(value);
//setting the threshold smoke level as 200 and applying if-else condition
if (value > 200) {
 digitalWrite(LED, HIGH); //Led turn on when sensor value is greater than 200
 digitalWrite(Buzzer, HIGH);//The buzzer buzzes for the sensor value more than 200
 lcd.setCursor(0, 1); // bottom left position on the LCD display
 lcd.print("Fire Alert!"); //display “Fire Alert” message on the LCD display
 } 
else
{
 digitalWrite(LED, LOW); //Led turn off when sensor value is less than 200
 digitalWrite(Buzzer, LOW);//Buzzer makes no sound for the sensor value less than 200
 lcd.setCursor(0, 1); //bottom left position on the LCD display
 lcd.print("Normal Smoke Lev:"); //display message on the LCD display
 }
 delay(1000); //setting time delay of 1 seconds
}
