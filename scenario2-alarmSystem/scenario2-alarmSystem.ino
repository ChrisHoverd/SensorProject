//cite for photocell(csd sensor) - https://learn.adafruit.com/photocells/arduino-code
//cite for neopixel stick - https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
//cite for sharp ir sensor - https://github.com/guillaume-rico/SharpIR
//reference for coloured keyboard: https://wiki.dfrobot.com/ADKeyboard_Module__SKU__DFR0075_#target_1
//                                 https://www.youtube.com/watch?v=HX2zDXK6E0Y


#include <SharpIR.h> 
#include <Adafruit_NeoPixel.h>


//declare variables required for IR and photocell
#define IR A0
#define PHOTOCELL A1
int distance;
int photocell_reading;
int mapped_photocell_reading;


#define model 1080
int LED_PIN = 6;
int NUM_PIXELS = 8;
int STROBE_BRIGHTNESS = 0;;
int SPEAKER_PIN = 3;
int RED_NEOPIXEL = 255;

//create neopixel and sharpIR objects
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); //create an adafruit neopixel object
SharpIR SharpIR(IR, model); //create a SharpIR object

//red LED strobe variables
unsigned long previousMillis = 0;
unsigned long flashingRedTimer = 500;

int delayval = 100; 

void setup() {
  pinMode(IR, INPUT);
  pinMode(SPEAKER_PIN, INPUT);
  pinMode(PHOTOCELL, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setPixelColor(0, pixels.Color(0,0,0)); //0,0,0 is the RGB values. thus 0,0,0 is off. 255, 0, 0 would be red
  pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  pixels.setPixelColor(2, pixels.Color(0,0,0)); 
  pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  pixels.setPixelColor(4, pixels.Color(0,0,0)); 
  pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  pixels.setPixelColor(6, pixels.Color(0,0,0)); 
  pixels.setPixelColor(7, pixels.Color(0,0,0)); 

  Serial.begin(9600);

}

void loop() {
  delay(500);
  photocell_reading = analogRead(PHOTOCELL); //take a reading from the photocell
  mapped_photocell_reading = map(photocell_reading, 0, 1023, 0, 255); //maps 0 - 1023 input from photocell to a 0-255 output to the LED
//  Serial.print("LED Brightness = ");
//  Serial.println(STROBE_BRIGHTNESS);
  Serial.print("Mapped Photocell Reading = ");
  Serial.println(mapped_photocell_reading);
  distance = SharpIR.distance(); //finds distance of object from IR sensor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (mapped_photocell_reading < 200)

  {

      if(distance < 15)
      {
      tone(SPEAKER_PIN, 200, 2000);
      
      pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);
      }

      if (distance >15 && distance < 34)
      {
        tone(SPEAKER_PIN, 600, 2000);

        pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);
      }

      if (distance >34 && distance <45)
      {
        tone(SPEAKER_PIN, 1000, 2000);

        pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(RED_NEOPIXEL,0,0));
      pixels.setPixelColor(1, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(2, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(3, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(4, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(5, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(6, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.setPixelColor(7, pixels.Color(RED_NEOPIXEL,0,0)); 
      pixels.show();
      delay(500);

      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0)); 
      pixels.show();
      delay(500);
      }
  }


  delay(delayval); // Delay for a period of time (in milliseconds).
}
