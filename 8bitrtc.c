 #include<LPC21XX.H>
#include"spi_combine.h"
#include"8bitlcdheader.h"
#include"uart_header.h"
void time(char a,char b,char c);



int main()
{ 
f32 f;
  char a,b,c;
  Init_SPI0();	
	LCD_INIT();
	UART0_INIT();
	CCR=0X01;
	SEC=0;
	MIN=46;
	HOUR=9;	  

	PREINT=0X01C8;
	PREFRAC=0X61C0;	
	 	
	
	
	
  while(1)
   {
   a=SEC;
	b=MIN;
	c=HOUR;
   f=Read_ADC_MCP3204(0);
		LCD_COMMAND(0x80);
		LCD_STR("Voltage:  ");
		LCD_COMMAND(0x89);
		LCD_fp(f);
		delay_milliseconds(1000);
	
   
	
	LCD_COMMAND(0xC0);
	LCD_STR("Time:");
	//LCD_COMMAND(0xC6);
//	LCD_STR("Time:");
 time(a,b,c);
 	UART0_fp(f);

 //delay_milliseconds(500);


 
//	delay_seconds(3);
 
	
 }
 }




void time(char a,char b,char c)
{


LCD_COMMAND(0xc6);
LCD_DATA(48+(c/10));
LCD_DATA(48+(c%10));
LCD_DATA(':');
LCD_DATA(48+(b/10));
LCD_DATA(48+(b%10));
LCD_DATA(':');
LCD_DATA(48+(a/10));
LCD_DATA(48+(a%10));
//lcd_data('\r');


}

void uarttime(char a,char b,char c)
{



UART0_Tx(48+(c/10));
UART0_Tx(48+(c%10));
UART0_Tx(':');
UART0_Tx(48+(b/10));
UART0_Tx(48+(b%10));
UART0_Tx(':');
UART0_Tx(48+(a/10));
UART0_Tx(48+(a%10));
UART0_Tx('\r');
//UART0_Tx('\n');


}
