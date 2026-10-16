// T3: Generating Delay Using Timer3 in 16-Bit Mode – PIC18F4580

#include <p18f4580.h>
#define Led PORTCbits.RC0

void T3_Delay(void);

void main(void)
{
	TRISCbits.RC0 = 0;

	T3CON = 0xF4; // timer1 initialization

	while(1)
	{
		Led = 1;
		T3_Delay();
		Led = 0;
		T3_Delay();
	}
}

void T3_Delay(void)
{
	TMR3H = 0X85;
	TMR3L = 0XED;

	T3CONbits.TMR3ON =1; // Start timer1

	while(PIR2bits.TMR3IF == 0); // wait for interrupt
	PIR2bits.TMR3IF = 0;       // Clear old flag

	T3CONbits.TMR3ON = 0; // Stop timer1
}
