
void delay_seconds(int seconds)
{
	T0PR=15000000-1;
 T0TCR=0x01;
	while(T0TC<seconds);
		T0TCR=0x03;
	T0TCR=0x00;
}

void delay_milliseconds(int milliseconds)
{
	T0PR=15000-1;
 T0TCR=0x01;
	while(T0TC<milliseconds);
		T0TCR=0x03;
	T0TCR=0x00;
}

void delay_microseconds(int us)
{
	T0PR=15-1;
 T0TCR=0x01;
	while(T0TC<us);
		T0TCR=0x03;
	T0TCR=0x00;
}
