#include<avr/io.h>
#include "adc_32.h"

void adc_init()
{
ADMUX=(1<<REFS0);
ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

int adc(unsigned int ch)
{
ch=ch&0b00000111;
ADMUX|=ch;                       //Start Single conversion
ADCSRA|=(1<<ADSC);               //Wait for conversion to complete
while(!(ADCSRA & (1<<ADIF)));    //Clear ADIF by writing one to it
ADCSRA|=(1<<ADIF);
return(ADC);
}
