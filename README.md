# Whack-A-Mole
Arduino based 'Whack-a-Mole" game to keep our cat entertained. 
- 3 servo motors are controlled with an Arduino Nano, which will eventually be used to raise and lower whatever is going to be the "mole".
- In each loop of the program, a random servo is chosen from the 3, then the delay before it raises, the speed at which it raises, how long it waits at the top, and how quickly it drops back down are all randomly generated.
- Eventually the arm mechanics will be constructed with Lego and placed inside some form of enclosure, along with soldered circuitry. 

## Hardware:
- [Arduino Nano (Clone)](https://www.amazon.ca/gp/product/B01FSDVZ98/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- [Servo Motors](https://www.amazon.ca/gp/product/B07Z16DWGW/ref=ppx_yo_dt_b_asin_image_o01_s00?ie=UTF8&psc=1)

## Considerations:
- The servo motors jitter when the Arduino is hooked up to power - from a quick Google search this seems to be a byproduct of powering them directly from the 5V pins. Powering them from an external 5V supply _should_ solve this issue.
- Right now there are 3 motors hooked up to pins 3, 4, and 5. The line `servo_pin = random(3,6);` determines which one will be powered in each loop.
