 
#include "DHT.h"
#include "LiquidCrystal.h" // includes the LiquidCrystal Library

#define dataPin 2 // Defines pin number to which the sensor is connected
#define DHTTYPE DHT11
DHT dht(dataPin,DHTTYPE); // Creats a DHT object
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

 
void setup() {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  Serial.begin(9600);
  dht.begin();
}
void loop() {
//  int readData = DHT.read11(dataPin);
// 
  float t = dht.readTemperature(); // Gets the values of the temperature
  float h = dht.readHumidity(); // Gets the values of the humidity
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed

    // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  lcd.setCursor(0,1);
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(3000);
  }
