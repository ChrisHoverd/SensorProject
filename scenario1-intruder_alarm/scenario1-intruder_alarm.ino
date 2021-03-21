#include <SharpIR.h>
#include <Adafruit_NeoPixel.h>


#define IR A0
#define PHOTOCELL A1
#define model 1080
int LED_PIN = 6;
int NUM_PIXELS = 8;
int SPEAKER_PIN = 7;

int distance;
int photocell_reading;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
SharpIR SharpIR(IR, model);

int delayval = 500; // delay for half a second

void setup() {
  pinMode(IR, INPUT);
  pinMode(SPEAKER_PIN, INPUT);
  pinMode(PHOTOCELL, INPUT);
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
  Serial.print("Analog reading = ");
  Serial.print(photocell_reading);     // the raw analog reading
 
  if (photocell_reading < 10) {
    Serial.println(" - Dark");
  } else if (photocell_reading < 200) {
    Serial.println(" - Dim");
  } else if (photocell_reading < 500) {
    Serial.println(" - Light");
  } else if (photocell_reading < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(delayval); // Delay for a period of time (in milliseconds).
}
