#include <Arduino.h>
#include <Servo.h>

// Servo Init
Servo servo;
int pos = 0;
int servo_pin;
unsigned int start_delay, up_delay, top_delay, down_delay;

// Lock (LED/Button Init)
const int button_pin = 10;
const int led_pin = 11;
int button_state = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

// Since I'm not re-homing the servos, there needs to be some way of ensuring they're all
// in the bottom position before powering down the toy. This very smooth-brain function
// will lock execution before a loop starts, and light up an LED to let you know
// it's safe to unplug
void lock() {
  digitalWrite(led_pin, HIGH);
  while(true);
}


void loop() {
  
  // Check to see if "lock" button is pressed 
  button_state = digitalRead(button_pin);
  if (button_state == HIGH) {
    lock();
  }

  // Generate the random values to drive the servo
  start_delay = random(10, 2500);
  top_delay = random(10, 500);
  up_delay = random(1, 50);
  down_delay = random(1, 50);
  servo_pin = random(3,6);

 // Servo UP
  delay(start_delay);
  servo.attach(servo_pin);
  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(up_delay);
  }

  // Servo DOWN
  delay(top_delay);
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(down_delay);
  }
}