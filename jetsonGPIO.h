/*

#ifndef JETSONGPIO_H_
#define JETSONGPIO_H_

 //Constants
 
#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) // 3 seconds 
#define MAX_BUF 64

typedef unsigned int jetsonGPIO ;
typedef unsigned int pinDirection ;
typedef unsigned int pinValue ;

enum pinDirections {
	inputPin  = 0,
	outputPin = 1
} ;

enum pinValues {
    low = 0,
    high = 1,
    off = 0,  // synonym for things like lights
    on = 1
}  ;

enum jetsonGPIONumber {
  gpio57  =  57,    // J3A1 - Pin 50
	gpio160 = 160,	  // J3A2 - Pin 40	
	gpio161 = 161,    // J3A2 - Pin 43
	gpio162 = 162,    // J3A2 - Pin 46
	gpio163 = 163,    // J3A2 - Pin 49
	gpio164 = 164,    // J3A2 - Pin 52
	gpio165 = 165,    // J3A2 - Pin 55
	gpio166 = 166,    // J3A2 - Pin 58
}  ;

enum jetsonTX1GPIONumber {
  gpio36 = 36,      // J21 - Pin 32 - Unused - AO_DMIC_IN_CLK
  gpio37 = 37,      // J21 - Pin 16 - Unused - AO_DMIC_IN_DAT
  gpio38 = 38,      // J21 - Pin 13 - Bidir  - GPIO20/AUD_INT
  gpio63 = 63,      // J21 - Pin 33 - Bidir  - GPIO11_AP_WAKE_BT
  gpio184 = 184,    // J21 - Pin 18 - Input  - GPIO16_MDM_WAKE_AP
  gpio186 = 186,    // J21 - Pin 31 - Input  - GPIO9_MOTION_INT
  gpio187 = 187,    // J21 - Pin 37 - Output - GPIO8_ALS_PROX_INT
  gpio219 = 219,    // J21 - Pin 29 - Output - GPIO19_AUD_RST
} ;

enum jetsonTX2GPIONumber {
  gpio388 = 388,     // J21 - Pin 37 - GPIO8_ALS_PROX_INT
  gpio298 = 298,     // J21 - Pin 31 - GPIO9_MOTION_INT
  gpio389 = 389,     // J21 - Pin 33 - GPIO11_AP_WAKE_BT
  gpio481 = 481,     // J21 - Pin 18 - GPIO16_MDM_WAKE_AP
  gpio398 = 398,     // J21 - Pin 29 - GPIO19_AUD_RST
} ;


int gpioExport ( jetsonGPIO gpio ) ;
int gpioUnexport ( jetsonGPIO gpio ) ;
int gpioSetDirection ( jetsonGPIO, pinDirection out_flag ) ;
int gpioSetValue ( jetsonGPIO gpio, pinValue value ) ;
int gpioGetValue ( jetsonGPIO gpio, unsigned int *value ) ;
int gpioSetEdge ( jetsonGPIO gpio, char *edge ) ;
int gpioOpen ( jetsonGPIO gpio ) ;
int gpioClose ( int fileDescriptor ) ;
int gpioActiveLow ( jetsonGPIO gpio, unsigned int value ) ;

#endif

*/

//the code below is for the TX2



#ifndef TX2_GPIO_H
#define TX2_GPIO_H

#include "jetsonStatus.h"
#include "jetsonConstants.h"

#define GPIO_DIR "/sys/class/gpio"

typedef enum
{
    gpio298 = 298,  // Pin 31 GPIO9_MOTION_INT
    gpio388 = 388,  // pin 37 GPIO8_ALS_PROX_INT
    gpio389 = 389,  // Pin 33 GPIO11_AP_WAKE_BT
    gpio398 = 398,  // Pin 29 GPIO19_AUD_RST
    gpio481 = 481   // Pin 18 GPIO16_MDM_WAKE_AP
} TX2_GPIO;

typedef enum
{
    GPIO_FILE_MODE_READ = 0,
    GPIO_FILE_MODE_WRITE
} GPIO_FILE_MODE;

typedef enum
{
    GPIO_DIRECTION_INPUT = 0,
    GPIO_DIRECTION_OUTPUT
} GPIO_PIN_DIRECTION;

typedef enum
{
    GPIO_PIN_VALUE_LOW = 0,
    GPIO_PIN_VALUE_HIGH,
} GPIO_PIN_VALUE;

typedef enum
{
    GPIO_PIN_EDGE_NONE = 0,
    GPIO_PIN_EDGE_RISING,
    GPIO_PIN_EDGE_FALLING,
    GPIO_PIN_EDGE_BOTH
} GPIO_PIN_EDGE;

typedef enum
{
    GPIO_ACTIVE_LOW_FALSE = 0,
    GPIO_ACTIVE_LOW_TRUE
} GPIO_ACTIVE_LOW;

static Status _gpio_open_file(TX2_GPIO gpio, GPIO_FILE_MODE mode, char *dirToOpen, TxS32 *fd);
Status gpio_export(TX2_GPIO gpio);
Status gpio_unexport(TX2_GPIO gpio);
Status gpio_set_direction(TX2_GPIO gpio, GPIO_PIN_DIRECTION direction);
Status gpio_set_value(TX2_GPIO gpio, GPIO_PIN_VALUE value);
Status gpio_get_value (TX2_GPIO gpio, GPIO_PIN_VALUE *value);
Status gpio_set_edge(TX2_GPIO gpio, GPIO_PIN_EDGE edge);
Status gpio_active_low(TX2_GPIO gpio, GPIO_ACTIVE_LOW activeLow);
Status gpio_open(TX2_GPIO gpio, TxS32 *fd);
Status gpio_close(TxS32 *fd);

#endif
