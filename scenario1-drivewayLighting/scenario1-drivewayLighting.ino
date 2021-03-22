
//import necessary libraries
#include <SharpIR.h>
#include <Adafruit_NeoPixel.h>

//declare variables required for IR and photocell
#define IR A0
#define PHOTOCELL A1
int distance;
int photocell_reading;
#define model 1080

//declare neopiexel and speaker variables
int LED_PIN = 6;
int NUM_PIXELS = 8;
int LED_BRIGHTNESS;
int SPEAKER_PIN = 3;

//intialize variables required for adc keyboard
#define KEYBOARD A2
int adc_value;
int old_key = 6;
int key;

//declare variables required for green and yellow LEDs
int GREEN_LED_PWM = 0;
int GREEN_LED_PIN = 10;
int YELLOW_LED_PIN = 9;
int YELLOW_LED_PWM = 0;

//intialize variables needed to time the alarm speaker
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

//adc keyboard values and their assigned integer value for debugging and reference
//white 170 - 1
//blue 340 - 2
//red 500 - 3
//yellow 680 - 4
//green 865 - 5
//no button pressed = 1023

//create neopixel and sharpIR objects
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); //create an adafruit neopixel object
SharpIR SharpIR(IR, model); //create a SharpIR object

int delayval = 100; // delay for half a second at end of main loop

void setup() {
  //declare pin modes
  pinMode(IR, INPUT);
  pinMode(PHOTOCELL, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);

}

void loop() {
  delay(500);
  adc_value = analogRead(KEYBOARD); //read adc values from keyboard
  key = (buttonFromAnalog(adc_value)); //assign a value to the adc conversion
  analogWrite(GREEN_LED_PIN, GREEN_LED_PWM); //send analog signals to green and yellow pins
  analogWrite(YELLOW_LED_PIN, YELLOW_LED_PWM);

    // these nested if statements are used to debounce the adc key signal 
    //  then determine if a new key has been pressed
    //      then from there, it determines which key was pressed and does something
    //          depending on which key
    if (key!=old_key)
  {
      delay(50);
      adc_value = analogRead(KEYBOARD);
      key = (buttonFromAnalog(adc_value));
      if (key!=old_key)
      {
            old_key = key;
            if (key >=0)
            {
                switch(key)
                {

                  // if white button has been pushed, do this.. if blue button has been pushed...etc.
                   case 1:Serial.println("White");
                          break;
                   case 2:Serial.println("Blue");
                          break;
                   case 3:Serial.println("Red");
                          break;
                   case 4:Serial.println("Yellow");
                          changeYellowLED(); //calls function that changes yellow LED analog signal to 0 or 255
                          break;
                   case 5:Serial.println("Green");
                          changeGreenLED(); //calls function that changes green LED analog signal to 0 or 255
                          break;
                }
            }
      }
  }
  
  photocell_reading = analogRead(PHOTOCELL); //take a reading from the photocell
  LED_BRIGHTNESS = map(1023 - photocell_reading, 0, 1023, 0, 255); //maps 0 - 1023 input from photocell to a 0-255 output to the LED
  Serial.print("LED Brightness = "); //print statements used for debugging
  Serial.println(LED_BRIGHTNESS);
  Serial.print("Analog reading = ");
  Serial.println(photocell_reading);
  distance = SharpIR.distance(); //finds distance of object from IR sensor
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance>15) //only turn on lightbar if object is 15cm or less from IR sensor

    {
      pixels.setPixelColor(0, pixels.Color(0,0,0)); //0,0,0 is the RGB values. thus 0,0,0 is off. 255, 0, 0 would be red
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0)); 
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.setPixelColor(5, pixels.Color(0,0,0)); 
      pixels.setPixelColor(6, pixels.Color(0,0,0)); 
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      noTone(SPEAKER_PIN); 
   }
  else
   {

    //LED lightbar changes light intensity inverely propoertional to the brightness around the photocell
      pixels.setPixelColor(0, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS));
      pixels.setPixelColor(1, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(2, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(3, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(4, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(5, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(6, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS)); 
      pixels.setPixelColor(7, pixels.Color(LED_BRIGHTNESS,LED_BRIGHTNESS,LED_BRIGHTNESS));
      
      currentMillis = millis(); 
      if(currentMillis - previousMillis > 10000) //if statement used to only play the speaker every 10 seconds and only if an object is within the 15cm range
      {
        previousMillis = currentMillis;
        tone(SPEAKER_PIN, 500, 500);
      }
      
  }
  
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(delayval); // Delay for a period of time (in milliseconds).
}

byte buttonFromAnalog(int analogInput) // function used to determine which button was pushed on the adc keyboard
{
    if(analogInput > 130 && analogInput <=250 )
    {
        return 1; //white
    }

    if(analogInput >= 250 && analogInput <430 )
    {
        return 2; //blue
    }

    if(analogInput >= 430 && analogInput <560 )
    {
        return 3; //red
    }

    if(analogInput >= 560 && analogInput <750 )
    {
        return 4; //yellow
    }

    if(analogInput >= 750 && analogInput <950 )
    {
        return 5; //green
    }
    if(analogInput >= 950 )
    {
        return 0; //no button press
    }
}

void changeGreenLED(){ //function that changes pwm of green LED pin to 0 or 255
  if (GREEN_LED_PWM == 0)
  {
     GREEN_LED_PWM = 255;
  }

  else {
    GREEN_LED_PWM = 0;
  }
}

void changeYellowLED(){ //function that changes pwm of yellow LED pin to 0 or 255
  if (YELLOW_LED_PWM == 0)
  {
     YELLOW_LED_PWM = 255;
  }

  else {
    YELLOW_LED_PWM = 0;
  }
}
