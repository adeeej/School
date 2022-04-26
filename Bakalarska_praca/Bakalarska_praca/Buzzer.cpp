#include "Buzzer.h"

// default constructor
Buzzer::Buzzer()
{
	sbi(DDRB,BUZZ);													//set as output
	sbi(PORTB, BUZZ);
} //Buzzer

// default destructor
Buzzer::~Buzzer()
{
} //~Buzzer

void Buzzer::delay_us(int us) {
	for(int i=0; i<us; i++) _delay_us(1);
}

void Buzzer::delay_ms(int ms)
{
	for(int i=0; i<ms; i++) _delay_ms(1);
}

void Buzzer::kindOfTone(int us) {										
	sbi(PORTB,BUZZ);													// Turn ON the Buzzer conneted to PORTB
	delay_us(us);														// Wait for some time
	cbi(PORTB, BUZZ);													// Turn OFF the Buzzer connected to PORTB
	delay_us(us);														// Wait for some time
}

void Buzzer::tonLength(int lengthOfTone_ms, int kindOfTone_us) {		// Length of tone in ms and kind of tone <25;cca 5000)
	for (int i = 0; i < lengthOfTone_ms; i++)
	{
		kindOfTone(kindOfTone_us);
	}
}

void Buzzer::playFrequency(int frequency_ms, int lengthOfTone_ms, int kindOfTone_us) {
	tonLength(lengthOfTone_ms,kindOfTone_us);
	delay_ms(frequency_ms);
}
