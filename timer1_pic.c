//T1: Generating Delay Using Timer1 in 16-Bit Mode – PIC18F4580

#include<p18f4580.h>
#define Led PORTCbits.RC0

void T1_delay(void);

void main(void)
{
	TRISCbits.RC0=0;

//Timer Init
	T1CON = 0XF0; //16 BIT,TIMER OFF,1:8

	while(1)
	{	
	 	Led =1;
		T1_delay();

		Led =0;
		T1_delay();
	}
}

void T1_delay(void)
{
	TMR1H =0XB6;
	TMR1L =0XC;

	PIR1bits.TMR1IF = 0;	//CLAER THE FLAG BIT

	T1CONbits.TMR1ON = 1;	//TIMER START

	while(PIR1bits.TMR1IF == 0);	//wait for interrupt overload
	
	T1CONbits.TMR1ON = 0;	//STOP TIMER
}