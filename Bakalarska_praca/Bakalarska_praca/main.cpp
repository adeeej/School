#include "Led.h"
#include "Button.h"
#include "Buzzer.h"
#include "Uart.h"
#include "MPU_6050.h"
#include "Battery.h"

#define LOW_VOLTAGE 3.3

// Globalna premenna, do ktorej sa uklada pocet preruseni 
volatile uint16_t tot_overflow;

ISR(TIMER1_COMPA_vect)				// Prerusenie pri zhode OCR1A a TCNT1 (cca kazdych xy ms)
{
	cli();
	TCNT1=0;						// Vynuluje TCNT1
	tot_overflow++;
	sei();
}

int main(void)
{
	Led rgb;
	Button btn;
	Uart serial;
	MPU_6050 mpu;
	Battery batt;
	Buzzer buzz;
	sbi(DDRC, BATT);													
	cbi(PORTC, BATT);													
	
	mpu.timer_init();
	mpu.TWIM_WriteRegister(107,0);
	sei();
	while(!btn.isPressed()){}
	
	double voltage = 0;
	_delay_ms(20000);
	buzz.tonLength(100,3500);
	
	while (1)
	{
		if (TCNT1==0)
		{
			mpu.pushup_Control();
		}
		
		if (tot_overflow > 5000)
		{
			sbi(DDRD, BATT_MEAS_EN);													
			sbi(PORTD, BATT_MEAS_EN);													
			voltage = batt.voltsCounting(0);
			//printf("Value %u mV!\r\n", (unsigned int)voltage);
			tot_overflow = 0;
			cbi(PORTD, BATT_MEAS_EN);
			if (voltage < LOW_VOLTAGE)
			{
				rgb.set(red);
			}
		}
	}

	return 0;
}

