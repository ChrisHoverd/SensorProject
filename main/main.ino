#include <SharpIR.h>
#include <Adafruit_NeoPixel.h>


#define IR A0
#define model 1080
int LEDPIN = 6;
int NUMPIXELS = 8;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);
SharpIR SharpIR(IR, model);
int distance;
int delayval = 500; // delay for half a second

void setup() {
  pinMode(IR, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);

}

void loop() {
  delay(2000);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.setPixelColor(0, pixels.Color(150,0,0)); // red at about 60% of full brightness
  pixels.setPixelColor(1, pixels.Color(0,150,0)); // green at about 60% of full brightness
  pixels.setPixelColor(2, pixels.Color(0,0,150)); // blue at about 60% of full brightness
  pixels.setPixelColor(3, pixels.Color(50,50,50)); // white at about 20% of full brightness
  pixels.setPixelColor(4, pixels.Color(0,0,0)); // off
  pixels.setPixelColor(5, pixels.Color(25,25,25)); // magenta
  pixels.setPixelColor(6, pixels.Color(90,50,170)); // 
  pixels.setPixelColor(7, pixels.Color(150,50,0)); // orange

  pixels.show(); // This sends the updated pixel color to the hardware.

  distance = SharpIR.distance();
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(delayval); // Delay for a period of time (in milliseconds).
}
