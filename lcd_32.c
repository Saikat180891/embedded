#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<inttypes.h>

#define rs PB0
#define rw PB1
#define en PB2
#define pir PD0

unsigned char c;
int num[5];


void lcd_init()			// fuction for intialize
{
	dis_cmd(0x02);		// to initialize LCD in 4-bit mode.
	dis_cmd(0x28);		//to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	dis_cmd(0x0C);
	dis_cmd(0x01);
	dis_cmd(0x06);
	dis_cmd(0x80);
}

void dis_cmd(char cmd_value)
{
	char cmd_value1;

	cmd_value1 = cmd_value & 0xF0;		//mask lower nibble because PA4-PA7 pins are used.
	lcdcmd(cmd_value1);			// send to LCD

	cmd_value1 = ((cmd_value<<4) & 0xF0);	//shift 4-bit and mask
	lcdcmd(cmd_value1);			// send to LCD
}


void dis_data(char data_value)
{
	char data_value1;

	data_value1=data_value&0xF0;
	lcddata(data_value1);

	data_value1=((data_value<<4)&0xF0);
	lcddata(data_value1);
}

void lcdcmd(char cmdout)
{
	PORTB=cmdout;
	PORTB&=~(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
}

void lcddata(char dataout)
{
	PORTB=dataout;
	PORTB|=(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
}

void lcd_xy(unsigned char x,unsigned char y)
{
unsigned char command[]={0x80,0xc0,0x94,0xd4};

dis_cmd(command[y-1] + x-1);

_delay_us(100);
}



void lcd_string(unsigned char *disp)    // function to send string to LCD
{
int x;
for(x=0;disp[x]!=0;x++)
{
dis_data(disp[x]);

}
}


void lcd_num(unsigned int i)     //Function to send data on LCD
{   int p;
int k=0;
while(i>0)
{
  num[k]=i%10;
  i=i/10;
  k++;
}
k--;
for (p=k;p>=0;p--)
{
  c=num[p]+48;
  dis_data(c);

}
return;
}
