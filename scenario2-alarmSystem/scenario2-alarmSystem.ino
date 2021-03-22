//cite for photocell(csd sensor) - https://learn.adafruit.com/photocells/arduino-code
//cite for neopixel stick - https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
//cite for sharp ir sensor - https://github.com/guillaume-rico/SharpIR
//reference for coloured keyboard: https://wiki.dfrobot.com/ADKeyboard_Module__SKU__DFR0075_#target_1
//                                 https://www.youtube.com/watch?v=HX2zDXK6E0Y


// **** Author: Christopher Hoverd


//include necessary libraries
#include <SharpIR.h> 
#include <Adafruit_NeoPixel.h>


//declare variables required for IR and photocell
#define IR A0
#define PHOTOCELL A1
#define model 1080
int distance;
int photocell_reading;


int mapped_photocell_reading;
int LED_PIN = 6;
int NUM_PIXELS = 8;
int SPEAKER_PIN = 3;
int RED_NEOPIXEL = 255;

//create neopixel and sharpIR objects
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); //create an adafruit neopixel object
SharpIR SharpIR(IR, model); //create a SharpIR object

//red LED strobe variables
unsigned long flashingRedTimer = 500;

//delay at end of main loop
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
  mapped_photocell_reading = map(photocell_reading, 0, 1023, 0, 255); //maps 0 - 1023 input from photocell to 0 - 255
  distance = SharpIR.distance(); //finds distance of object from IR sensor

// commented out processes for debugging
//  Serial.print("LED Brightness = ");
//  Serial.println(STROBE_BRIGHTNESS);
//  Serial.print("Mapped Photocell Reading = ");
//  Serial.println(mapped_photocell_reading);
//  Serial.print("Distance: ");
//  Serial.println(distance);

  if (mapped_photocell_reading < 200) //only trigger alarm system if the mapped photocell value is less than 200

  {

      if(distance < 15) //if distance is less than 15 cm, do this
      {
      tone(SPEAKER_PIN, 200, 2000); //turn on an alarm at 200 Hz for 2000 ms


      //the following lines in this 
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

      if (distance >15 && distance < 34) //if distance is greater than 15 cm and less than 34 cm, do this
      {
        tone(SPEAKER_PIN, 600, 2000); //turn on an alarm at 600 Hz for 2000 ms

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

      if (distance >34 && distance <45) //if distance is greater than 34 cm and less than 45 cm, do this
      {
        tone(SPEAKER_PIN, 1000, 2000); //turn on an alarm at 1000 Hz for 2000 ms

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
