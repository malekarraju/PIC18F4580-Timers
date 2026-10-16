//T0: Generating Delay Using Timer0 in 16-Bit Mode – PIC18F4580

#include<p18f4580.h>
#define Led PORTCbits.RC0

void T0_delay();

void main()
{
	TRISCbits.RC0=0;

//Timer Init
	T0CON = 0X07;//16 BIT,TIMER OFF,1:25

	while(1)
	{
	 	Led =1;
		T0_delay();
		Led =0;
		T0_delay();
	}
}

void T0_delay()
{
	TMR0H =0XFE;
	TMR0L =0X78;

	T0CONbits.TMR0ON = 1;//TIMER START

	while(INTCONbits.TMR0IF==0);//wait for interrupt overload
	INTCONbits.TMR0IF=0;//CLAER THE FLAG BIT

	T0CONbits.TMR0ON = 0;//STOP TIMER
}