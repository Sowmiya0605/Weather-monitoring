#include<LPC21XX.h>
#include"delay.h"
#define LCD_D 0xff<<8
#define RS 1<<16
#define RW 1<<19
#define E 1<<17
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_INTEGER(int);
void LCD_STR(unsigned char*);
void LCD_fp(float);

void LCD_INTEGER(int n)
{
unsigned char arr[5];
	signed int i=0;
	
if(n==0)
LCD_DATA('0');
else
{
	if(n<0)
	{
		LCD_DATA('-');
		n=-n;
	}
	while(n!=0)
	{
		arr[i++]=n%10;
		n=n/10;
	}
	for(--i;i>=0;i--)
	LCD_DATA(arr[i]+48);
}
}

void LCD_fp(float f)
{
	int temp;
	temp=f;
	LCD_INTEGER(temp);
	LCD_DATA('.');
	temp=(f-temp)*100;
	LCD_INTEGER(temp);
}

void LCD_INIT(void)
{
IODIR0|=LCD_D|RS|RW|E;//P0.8 to P0.19 as Output pins.
LCD_COMMAND(0x01);
LCD_COMMAND(0x02);
LCD_COMMAND(0x0c);
LCD_COMMAND(0x38);
LCD_COMMAND(0x80);
}

void LCD_COMMAND(unsigned char cmd)
	{
		IOCLR0=LCD_D;
		IOSET0=cmd<<8;
		IOCLR0=RS;
		IOCLR0=RW;
		IOSET0=E;
		delay_milliseconds(2);
		IOCLR0=E;
	
	}
	
void LCD_DATA(unsigned char d)
	{
		IOCLR0=LCD_D;
		IOSET0=d<<8;
	IOSET0=RS;
		IOCLR0=RW;
	IOSET0=E;
	delay_milliseconds(2);
	IOCLR0=E;
}

void LCD_STR(unsigned char *s)
{
 while(*s)
 {
  LCD_DATA(*s++);
 }

}
