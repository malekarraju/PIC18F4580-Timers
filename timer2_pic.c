// T2: Generating Delay Using Timer2 and PR2 – PIC18F4580

#include <p18f4580.h>
#define Led PORTCbits.RC0

void T2_Delay(void);

void main(void)
{
	TRISCbits.RC0 = 0;

	T2CON = 0x0A; // timer1 initialization
	while(1)
	{
		Led = 1;
		T2_Delay();
		Led = 0;
		T2_Delay();
	}
}

void T2_Delay(void)
{
	PR2 = 0x9C;

	T2CONbits.TMR2ON =1; // Start timer1

	while(PIR1bits.TMR2IF == 0); // wait for interrupt
	PIR1bits.TMR2IF = 0;       // Clear old flag

	
	T2CONbits.TMR2ON = 0; // Stop timer1
}
