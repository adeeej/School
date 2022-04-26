#include "Led.h"

// default constructor
Led::Led()
{
	/* set as outputs */
	sbi(DDRC,R_LED);
	sbi(DDRC,G_LED);
	sbi(DDRC,B_LED);
	
	set(false,false,false);	// set all leds off
	
	// Fast PWM
	// CLKIO/256
	sbi(TCCR0A,WGM00);		// set fast PWM for TC0
	sbi(TCCR0A,WGM01);		// set fast PWM for TC0
	sbi(TCCR0B,CS02);		// clkio/256 (183 Hz) for TC0
	
	sbi(TCCR2A,WGM20);		// set fast PWM for TC2
	sbi(TCCR2A,WGM21);		// set fast PWM for TC2
	sbi(TCCR2B,CS22);		// clkio/256 (183 Hz) for TC2
	
} //Led

// default destructor
Led::~Led()
{
	
} //~Led

void Led::set(bool r,bool g,bool b)
{
	if(r) cbi(PORTC,R_LED); else sbi(PORTC,R_LED);
	if(g) cbi(PORTC,G_LED); else sbi(PORTC,G_LED);
	if(b) cbi(PORTC,B_LED); else sbi(PORTC,B_LED);
}

void Led::setIntensity(uint8_t r, uint8_t g, uint8_t b)
{
	if(r==0)
	{
		cbi(TCCR0A,COM0A0);
		cbi(TCCR0A,COM0A1);
		sbi(PORTD,R_LED);
	}
	else
	{
		sbi(TCCR0A, COM0A0);
		sbi(TCCR0A, COM0A1);
		OCR0A = r;
	}

	if(g==0)
	{
		cbi(TCCR2A,COM2B0);
		cbi(TCCR2A,COM2B1);
		sbi(PORTD,G_LED);
	}
	else
	{
		sbi(TCCR2A, COM2B0);
		sbi(TCCR2A, COM2B1);
		OCR2B = g;
	}

	if(b==0)
	{
		cbi(TCCR0A,COM0B0);
		cbi(TCCR0A,COM0B1);
		sbi(PORTD,B_LED);
	}
	else
	{
		sbi(TCCR0A, COM0B0);
		sbi(TCCR0A, COM0B1);
		OCR0B = b;
	}
}

void Led::set(Colour c)
{
	switch(c)
	{
		case 0:		set(1,0,0);
		break;
		case 1:		set(0,1,0);
		break;
		case 2:		set(0,0,1);
		break;
		case 3:		set(1,0,1);
		break;
		default:	set(0,0,0);
	}
}

void Led::blick(bool r,bool g,bool b, int timeMs)
{
	this->set(r,g,b);
	for(int i=0; i<timeMs; i++) _delay_ms(1);
	this->set(0,0,0);
	for(int i=0; i<timeMs; i++) _delay_ms(1);
}

void Led::delay_ms(int ms)
{
	for(int i=0; i<ms; i++) _delay_ms(1);
}

void Led::delay_us(int us)
{
	for(int i=0; i<us; i++) _delay_us(1);
}

void Led::swPwm(Colour c, uint8_t percentage)
{
	if(percentage == 0)
	{
		set(0,0,0);
		return;
	}
	if(percentage>=100)
	{
		set(c);
		return;
	}
	set(c);
	delay_us(percentage);
	set(0,0,0);
	delay_us(100-percentage);
}
