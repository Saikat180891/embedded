#include<avr/io.h>
#include<util/delay.h>
#include "pwm_32.h"



void InitPWM()
{
   /*
   TCCR0 - Timer Counter Control Register (TIMER0)
   -----------------------------------------------
   BITS DESCRIPTION


   NO:   NAME   DESCRIPTION
   --------------------------
   BIT 7 : FOC0   Force Output Compare [Not used in this example]
   BIT 6 : WGM00  Wave form generartion mode [SET to 1]
   BIT 5 : COM01  Compare Output Mode        [SET to 1]
   BIT 4 : COM00  Compare Output Mode        [SET to 0]

   BIT 3 : WGM01  Wave form generation mode [SET to 1]
   BIT 2 : CS02   Clock Select               [SET to 0]
   BIT 1 : CS01   Clock Select               [SET to 0]
   BIT 0 : CS00   Clock Select               [SET to 1]

   The above settings are for
   --------------------------

   Timer Clock = CPU Clock (No Prescalling)
   Mode        = Fast PWM
   PWM Output  = Non Inverted

   */


   TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);

   //Set OC0 PIN as output. It is  PB3 on ATmega16 ATmega32

   //DDRB|=(1<<PB3);
}

void SetPWMOutput(unsigned int duty)
{
   OCR0=duty;
}

void analogWrite(unsigned int brightness)
{
   //Initialize PWM Channel 0
   InitPWM();
   SetPWMOutput(brightness);
   //Now Wait For Some Time
   _delay_us(1000);
}
