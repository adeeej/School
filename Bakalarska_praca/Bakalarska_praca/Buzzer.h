#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "Board.h"

class Buzzer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	Buzzer();
	~Buzzer();
	void delay_us(int us);
	void delay_ms(int ms);
	void kindOfTone(int us);
	void tonLength(int lengthOfTone_ms, int kindOfTone_us);
	void playFrequency(int frequency_ms, int lengthOfTone_ms, int kindOfTone_us);
	protected:
	private:
}; //Buzzer

#endif //__BUZZER_H__