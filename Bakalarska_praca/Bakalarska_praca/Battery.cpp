#include "Battery.h"

// default constructor
Battery::Battery()
{
	initADC();
	counts = 0;						
	adder = ADDER_VOLTAGE;					
	mv = 0;						
	output = 0;
} //Battery

// default destructor
Battery::~Battery()
{
} //~Battery

void Battery::initADC() {
	// Select Vref=AVcc
	ADMUX |= (1<<REFS0);											//internal 1.1V voltage reference with external capacitor at AREF pin ADMUX |= (1<<REFS1)|(1<<REFS0);
	//set prescaller to 128 and enable ADC
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

uint16_t Battery::ReadADC(uint8_t ADCchannel) {
		//select ADC channel with safety mask
		ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
		//single conversion mode
		ADCSRA |= (1<<ADSC);
		// wait until ADC conversion is complete
		while( ADCSRA & (1<<ADSC));
		return ADC;
}

double Battery::voltsCounting(uint8_t ADCchannel) {
	counts = ReadADC(ADCchannel);
	mv = (double)counts * mvpc;
	output = mv + (double)adder + LOSS_OF_VOLTAGE;
	return output;
}