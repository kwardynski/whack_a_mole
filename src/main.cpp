#include <Arduino.h>
#include <Servo.h>

Servo servo;

byte pos = 0;
byte servo_pin;
unsigned int start_delay, up_delay, top_delay, down_delay;

void setup() {

}

void loop() {
  
  start_delay = random(10, 2500);
  top_delay = random(10, 500);
  up_delay = random(1, 50);
  down_delay = random(1, 50);
  servo_pin = random(3,6);

  delay(start_delay);
  servo.attach(servo_pin);

  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(up_delay);
  }

  delay(top_delay);

  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(10);
  } 
}