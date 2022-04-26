#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "Board.h"
#define LOSS_OF_VOLTAGE 200
#define ADDER_VOLTAGE 2200

class Battery
{
//variables
public:
protected:
private:
	static const double mvpc = 3.22;		//(refernce ADC / 1024) = 3.3 / 1024 = 3.22 mV
	uint16_t counts;						//value from adc pin
	double adder;							//add 2.2V, because voltage divider
	double mv;								//miliVolts but we need to add adder
	double output;							//final value of volts

//functions
public:
	Battery();
	~Battery();
	void initADC();
	uint16_t ReadADC(uint8_t ADCchannel);
	double voltsCounting(uint8_t ADCchannel);
protected:
private:
	

}; //Battery

#endif //__BATTERY_H__
