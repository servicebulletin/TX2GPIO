# jetsonTX2GPIO

A straightforward library to interface with the NVIDIA Jetson TX2 Development Kit GPIO pins.

exampleGPIOApp.cpp describes a simple usage case using a tactile button and LED as input and output. 

* Build the application using build.sh

* Remember to type sudo when running ./exampleGPIOApp

* Refer to the TX1 GPIO tutorial by JetsonHacks, available at
  http://www.jetsonhacks.com/2015/12/29/gpio-interfacing-nvidia-jetson-tx1/
  for breadboard setup instructions and a general idea of what it does. 

* Note that the TX2 GPIO pin numbers are different from those of the TX1. 
  Refer to jetsonGPIO.h for pin numbers. 

* The pin header looks like this: 

     02 04 06 08 10 12 14 16 18 20 ...
     01 03 05 07 09 11 13 15 17 19 ...
     ^ J21
 
  There is a white triangle next to the words "J21" or "J26". 
  It points to pin 1. 
  Start counting from there. 
