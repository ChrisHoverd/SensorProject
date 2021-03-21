//cite for photocell(csd sensor) - https://learn.adafruit.com/photocells/arduino-code
//cite for neopixel stick - https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
//cite for sharp ir sensor - https://github.com/guillaume-rico/SharpIR


#include <SharpIR.h>
#include <Adafruit_NeoPixel.h>


#define IR A0
#define PHOTOCELL A1
#define model 1080
int LED_PIN = 6;
int NUM_PIXELS = 8;
int SPEAKER_PIN = 7;
int LED_BRIGHTNESS;
int GREEN_LED = 10;

int distance;
int photocell_reading;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
SharpIR SharpIR(IR, model);

int delayval = 500; // delay for half a second

void setup() {
  pinMode(IR, INPUT);
  pinMode(SPEAKER_PIN, INPUT);
  pinMode(PHOTOCELL, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);

}

void loop() {
  delay(500);
  photocell_reading = analogRead(PHOTOCELL);
  distance = SharpIR.distance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance>15)

    {
      pixels.setPixelColor(0, pixels.Color(0,255,0));
      pixels.setPixelColor(1, pixels.Color(0,255,0)); 
      pixels.setPixelColor(2, pixels.Color(0,255,0)); 
      pixels.setPixelColor(3, pixels.Color(0,255,0)); 
      pixels.setPixelColor(4, pixels.Color(0,255,0)); 
      pixels.setPixelColor(5, pixels.Color(0,255,0)); 
      pixels.setPixelColor(6, pixels.Color(0,255,0)); 
      pixels.setPixelColor(7, pixels.Color(0,255,0)); 
      noTone(SPEAKER_PIN);
   }
  else
   {
      pixels.setPixelColor(0, pixels.Color(255,0,0));
      pixels.setPixelColor(1, pixels.Color(255,0,0)); 
      pixels.setPixelColor(2, pixels.Color(255,0,0)); 
      pixels.setPixelColor(3, pixels.Color(255,0,0)); 
      pixels.setPixelColor(4, pixels.Color(255,0,0)); 
      pixels.setPixelColor(5, pixels.Color(255,0,0)); 
      pixels.setPixelColor(6, pixels.Color(255,0,0)); 
      pixels.setPixelColor(7, pixels.Color(255,0,0));
      digitalWrite(SPEAKER_PIN, HIGH);
      tone(SPEAKER_PIN, 200);
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  Serial.print("Analog reading = ");
  Serial.println(photocell_reading);     // the raw analog reading
  LED_BRIGHTNESS = map(1023 - photocell_reading, 0, 1023, 0, 255);
  Serial.println(LED_BRIGHTNESS);
  analogWrite(GREEN_LED, LED_BRIGHTNESS );
//  if(LED_BRIGHTNESS<=50)
//  {
//    analogWrite(GREEN_LED, 50);
//  }
//
//  if(50<LED_BRIGHTNESS<=150)
//  {
//    analogWrite(GREEN_LED, 150);
//  }
//  if(150<LED_BRIGHTNESS<=255)
//  {
//    analogWrite(GREEN_LED, 255);
//  }

  delay(delayval); // Delay for a period of time (in milliseconds).
}
