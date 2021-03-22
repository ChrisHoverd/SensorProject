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


#define model 1080
int LED_PIN = 6;
int NUM_PIXELS = 8;
int LED_BRIGHTNESS;

//intialize variables required for adc keyboard
#define KEYBOARD A2
int adc_value;
int old_key = 6;
int key;
int GREEN_LED_PWM = 0;
int GREEN_LED_PIN = 10;
int YELLOW_LED_PIN = 9;
int YELLOW_LED_PWM = 0;

int SPEAKER_PIN = 3;
//white 170 - 1
//blue 340 - 2
//red 500 - 3
//yellow 680 - 4
//green 865 - 5
//no button pressed = 1023

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
  pinMode(GREEN_LED_PIN, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);

}

void loop() {
  delay(500);
  adc_value = analogRead(KEYBOARD);
  key = (buttonFromAnalog(adc_value));
  Serial.println(GREEN_LED_PWM);
  analogWrite(GREEN_LED_PIN, GREEN_LED_PWM);
  analogWrite(YELLOW_LED_PIN, YELLOW_LED_PWM);

  


  photocell_reading = analogRead(PHOTOCELL); //take a reading from the photocell
  LED_BRIGHTNESS = map(1023 - photocell_reading, 0, 1023, 0, 255); //maps 0 - 1023 input from photocell to a 0-255 output to the LED
  Serial.print("LED Brightness = ");
  Serial.println(LED_BRIGHTNESS);
  Serial.print("Analog reading = ");
  Serial.println(photocell_reading);
  distance = SharpIR.distance(); //finds distance of object from IR sensor
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


void changeGreenLED(){
  if (GREEN_LED_PWM == 0)
  {
     GREEN_LED_PWM = 255;
  }

  else {
    GREEN_LED_PWM = 0;
  }
}

void changeYellowLED(){
  if (YELLOW_LED_PWM == 0)
  {
     YELLOW_LED_PWM = 255;
  }

  else {
    YELLOW_LED_PWM = 0;
  }
}