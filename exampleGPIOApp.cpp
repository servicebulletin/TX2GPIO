// exampleApp.c
/* If this code doesn't work for the TX2, you might want to try:
 *   - Changing the GPIO pin numbers here and in the header file. 
 *   - Enabling GPIO for application space: https://elinux.org/GPIO
 *     Type into terminal:
 *
 *     sudo -i                       (goes into root user)
 *     GPIO=398
 *     cd /sys/class/gpio
 *     ls
 *     echo $GPIO > export
 *     ls
 *
 *     Repeat for GPIO=481
 */ 

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "jetsonGPIO.h"
using namespace std;

int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    // set the terminal to raw mode 
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    // read a character from the stdin stream without blocking
    //   returns EOF (-1) if no character is available 
    character = fgetc(stdin);

    // restore the original terminal attributes 
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

int main(int argc, char *argv[]){

    cout << "Testing the GPIO Pins" << endl;

    //change gpio398 to gpio219 for the TX1
    jetsonTX2GPIONumber redLED = gpio398 ;    // Ouput
    //change gpio481 to gpio38 for the TX1
    jetsonTX2GPIONumber pushButton = gpio481 ; // Input
    // Make the button and led available in user space
    gpioExport(pushButton) ;
    gpioExport(redLED) ;
    gpioSetDirection(pushButton,inputPin) ;
    gpioSetDirection(redLED,outputPin) ;
    // Reverse the button wiring; this is for when the button is wired
    // with a pull up resistor
    // gpioActiveLow(pushButton, true);

    // Flash the LED 5 times
    for(int i=0; i<5; i++){
        cout << "Setting the LED on" << endl;
        gpioSetValue(redLED, on);
        usleep(200000);         // on for 200ms
        cout << "Setting the LED off" << endl;
        gpioSetValue(redLED, off);
        usleep(200000);         // off for 200ms
    }

    // Wait for the push button to be pressed
    cout << "Please press the button! ESC key quits the program" << endl;

    unsigned int value = low;
    int ledValue = low ;
    // Turn off the LED
    gpioSetValue(redLED,low) ;
    while(getkey() != 27) {
        gpioGetValue(pushButton, &value) ;
        // Useful for debugging
        cout << "Button " << value << endl;
        if (value==high && ledValue != high) {
            // button is pressed ; turn the LED on
            ledValue = high ;
            gpioSetValue(redLED,on) ;
        } else {
            // button is *not* pressed ; turn the LED off
            if (ledValue != low) {
                ledValue = low ;
                gpioSetValue(redLED,off) ;
            }

        }
        usleep(1000); // sleep for a millisecond
    }

    cout << "GPIO example finished." << endl;
    gpioUnexport(redLED);     // unexport the LED
    gpioUnexport(pushButton);      // unexport the push button
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "jetsonGPIO.h"
using namespace std;

int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

int main(int argc, char *argv[]){

    cout << "Testing the GPIO Pins" << endl;

    //change gpio398 to gpio219 for the TX1
    TX2_GPIO redLED = gpio398 ;    // Ouput
    //change gpio481 to gpio38 for the TX1
    TX2_GPIO pushButton = gpio481 ; // Input
    // Make the button and led available in user space
    gpio_export(pushButton) ;
    gpio_export(redLED) ;
    gpio_set_direction(pushButton,GPIO_DIRECTION_INPUT) ;
    gpio_set_direction(redLED,GPIO_DIRECTION_OUTPUT) ;
    // Reverse the button wiring; this is for when the button is wired
    // with a pull up resistor
    // gpioActiveLow(pushButton, true);

    // Flash the LED 5 times
    for(int i=0; i<5; i++){
        cout << "Setting the LED on" << endl;
        gpio_set_value(redLED, GPIO_PIN_VALUE_HIGH);
        usleep(200000);         // on for 200ms
        cout << "Setting the LED off" << endl;
        gpio_set_value(redLED, GPIO_PIN_VALUE_LOW);
        usleep(200000);         // off for 200ms
    }

    // Wait for the push button to be pressed
    cout << "Please press the button! ESC key quits the program" << endl;

    GPIO_PIN_VALUE value = GPIO_PIN_VALUE_LOW;//unsigned int value = GPIO_PIN_VALUE_LOW;
    int ledValue = GPIO_PIN_VALUE_LOW ;
    // Turn off the LED
    gpio_set_value(redLED,GPIO_PIN_VALUE_LOW) ;
    while(getkey() != 27) {
        gpio_get_value(pushButton, &value) ;
        // Useful for debugging
        cout << "Button " << value << endl;
        if (value==GPIO_PIN_VALUE_HIGH && ledValue != GPIO_PIN_VALUE_HIGH) {
            // button is pressed ; turn the LED on
            ledValue = GPIO_PIN_VALUE_HIGH ;
            gpio_set_value(redLED,GPIO_PIN_VALUE_HIGH) ;
        } else {
            // button is *not* pressed ; turn the LED off
            if (ledValue != GPIO_PIN_VALUE_LOW) {
                ledValue = GPIO_PIN_VALUE_LOW ;
                gpio_set_value(redLED,GPIO_PIN_VALUE_LOW) ;
            }

        }
        usleep(1000); // sleep for a millisecond
    }

    cout << "GPIO example finished." << endl;
    gpio_unexport(redLED);     // unexport the LED
    gpio_unexport(pushButton);      // unexport the push button
    return 0;
}


