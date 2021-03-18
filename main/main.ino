#include <SharpIR.h>


#define IR A0
#define model 1080
SharpIR SharpIR(IR, model);
int distance;
void setup() {
  pinMode(IR, INPUT);

  Serial.begin(9600);

}

void loop() {
  delay(2000);


  distance = SharpIR.distance();
  Serial.print("Distance: ");
  Serial.println(distance);
}
