#include <SharpIR.h>
#include <Adafruit_NeoPixel.h>


#define IR A0
#define model 1080
int LED_PIN = 6;
int NUM_PIXELS = 8;
int SPEAKER_PIN = 7;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
SharpIR SharpIR(IR, model);
int distance;
int delayval = 500; // delay for half a second

void setup() {
  pinMode(IR, INPUT);
  pinMode(SPEAKER_PIN, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);

}

void loop() {
  delay(500);

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

  delay(delayval); // Delay for a period of time (in milliseconds).
}
