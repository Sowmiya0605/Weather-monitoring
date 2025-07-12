#include<LPC21XX.H>
void UART0_Tx(unsigned char);
void UART0_INIT(void);
void UART0_fp(float);
void UART0_INTEGER(int);
unsigned char UART0_Rx(void);

void UART0_INIT(void)
{
	PINSEL0|=0X00000005;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;
}
void UART0_Tx(unsigned char d)
{
	while(!(U0LSR&(1<<5)));
		U0THR=(d);
}
unsigned char UART0_Rx(void)
{
	while(!(U0LSR&(1<<0)));
		return U0RBR;
}
void UART0_INTEGER(int n)
{
unsigned char arr[5];
	signed int i=0;
	
if(n==0)
UART0_Tx('0');
else
{
	if(n<0)
	{
		UART0_Tx('-');
		n=-n;
	}
	while(n!=0)
	{
		arr[i++]=n%10;
		n=n/10;
	}
	for(--i;i>=0;i--)
	UART0_Tx(arr[i]+48);
}
}

void UART0_fp(float f)
{
	int temp;
	temp=f;
	UART0_INTEGER(temp);
	UART0_Tx('.');
	temp=(f-temp)*100;
	UART0_INTEGER(temp);
}

