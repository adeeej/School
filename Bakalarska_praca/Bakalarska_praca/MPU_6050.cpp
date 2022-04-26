#include "MPU_6050.h"
#include "Uart.h"

// default constructor
MPU_6050::MPU_6050()
{
	twi.TWIM_Init(10000);
	repetitions = 0;
	timerCounter = 0;
	first_control_down = false;
	second_control_down = false;
	
	first_control_up = false;
	second_control_up = false;
} //MPU_6050

// default destructor
MPU_6050::~MPU_6050()
{
} //~MPU_6050

void MPU_6050::TWIM_WriteRegister(char reg, char value)
{
	twi.TWIM_Start(addr, TWIM_WRITE); // set device address and write mode
	twi.TWIM_Write(reg);
	twi.TWIM_Write(value);
	twi.TWIM_Stop();
}

char MPU_6050::TWIM_ReadRegister(char reg)
{
	twi.TWIM_Start(addr, TWIM_WRITE);
	twi.TWIM_Write(reg);
	twi.TWIM_Stop();
	twi.TWIM_Start(addr, TWIM_READ); // set device address and read mode
	char ret = twi.TWIM_ReadNack();
	twi.TWIM_Stop();

	return ret;
}

i8 MPU_6050::MPU6050_ReadAccel(int axis)	//x = 0; y = 1; z = 2
{
	char reg = axis * 2 + 59;
	char AFS_SEL = TWIM_ReadRegister(28);
	double factor = 1<<AFS_SEL;
	factor = 16384/factor;
	int val = 0;
	double double_val = 0;
	char ret = 0;

	ret = TWIM_ReadRegister(reg);
	val = ret << 8;
	ret = TWIM_ReadRegister(reg+1);
	val += ret;

	if (val & 1<<15)
	val -= 1<<16;
	
	double_val = val;
	double_val = double_val / factor;
	double_val=double_val*(-127);			// uprava na pozadovany format
	i8 cislo = (i8)double_val;
	if (double_val>127)
	{
		cislo=127;
	}
	if(double_val<(-127))
	{
		cislo=-127;
	}
	return cislo;
}

double MPU_6050::MPU6050_ReadGyro(int axis)//x = 0; y = 1; z = 2
{
	char reg = axis * 2 + 67;
	char FS_SEL = TWIM_ReadRegister(27);
	double factor = 1<<FS_SEL;
	factor = 131/factor;
	int val = 0;
	double double_val = 0;
	char ret = 0;

	ret = TWIM_ReadRegister(reg);
	val = ret << 8;
	ret = TWIM_ReadRegister(reg+1);
	val += ret;

	if (val & 1<<15)
	val -= 1<<16;

	double_val = val;
	double_val = double_val / factor;
	return double_val;
}

void MPU_6050::pushup_Control()
{
	i8 x, y, z = 0;
	x =(i8)MPU6050_ReadAccel(0);									// Citanie X-ovej suradnice akcelerometra
	y =(i8)MPU6050_ReadAccel(1);									// Citanie Y-lonovej suradnice akcelerometra
	z =(i8)MPU6050_ReadAccel(2);									// Citanie Z-ovej suradnice akcelerometra
	
	if (!first_control_down || !second_control_down) {  
		if (y >= -85 && y <= -40 && x >= -45 && x <= 45 && z <= -50)
		{
			if (!second_control_down)
			{
				first_control_down = true;
				} else {
				buzz.tonLength(20,2500);
				controlDownFalse();
			}
		} 
		else if (y <= 20 && y >= -30 && x >= -45 && x <= 45 && z <= -50)
		{
			if (!first_control_down)				
			{
				buzz.tonLength(20,2500);
				controlDownFalse();
				} else {
				second_control_down = true;
			}
		} 
		else if (y < -85 || y > 20 || x > 45|| x < -45 || z > -50)
		{
			buzz.tonLength(20,2500);
			controlUpFalse();
			controlDownFalse();
		}
	}	
	
	if (first_control_down && second_control_down)
	{
		if (y <= 20 && y >= -30 && x >= -45 && x <= 45 && z <= -50) {
			if (!second_control_up) {
				first_control_up = true;
			} else {
				buzz.tonLength(20,2500);
				controlUpFalse();
				controlDownFalse();
			}
			}
		else if (y >= -85 && y <= -40 && x >= -45 && x <= 45 && z <= -50)											
		{
			if (!first_control_up)		
			{
				buzz.tonLength(20,2500);
				controlUpFalse();
				controlDownFalse();
				} else {
				second_control_up = true;
				setRepetitions();
				printf("Pocet opakovani: %lu!\r\n",getRepetitions());
				controlUpFalse();
				controlDownFalse();	
			}
		} 
		else if (y < -85 || y > 20 || x > 45 || x < -45 || z > -50)
		{
			buzz.tonLength(20,2500);
			controlUpFalse();
			controlDownFalse();
		}
	}
}

void MPU_6050::timer_init()
{
	TCCR1B|=(1<<CS10)|(1<<CS12);	// preddelicka 1024
	TCCR1B&=~(1<CS11);				// preddelicka 1024
	TIMSK1 |= (1 << OCIE1A);		// prerušenie pri zhode OCR1A a TCNT1
	OCR1A = 500;					// prerusenie kazdych cca 60 ms
}

void MPU_6050::setRepetitions() {
	repetitions++;
}

u32 MPU_6050::getRepetitions() {
	return repetitions;
}

void MPU_6050::controlDownFalse() {
	first_control_down = false;
	second_control_down = false;
}

void MPU_6050::controlUpFalse() {
	first_control_up = false;
	second_control_up = false;
}