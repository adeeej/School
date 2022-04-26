#ifndef __MPU_6050_H__
#define __MPU_6050_H__

#include <util/twi.h>
#include <avr/io.h>
#include "TWI.h"
#include "Int_Def.h"
#include "Buzzer.h"

#define addr 0x68		// adresa senzora

class MPU_6050
{
//variables
public:
protected:
private:
	TWI twi;
	Buzzer buzz;
	u32 repetitions;
	u32 timerCounter;
	
	bool first_control_down;
	bool second_control_down;
	bool third_control_down;
	bool fourth_control_down;
	
	bool first_control_up;
	bool second_control_up;
	bool third_control_up;
	bool fourth_control_up;

//functions
public:
	MPU_6050();
	~MPU_6050();
	void TWIM_WriteRegister(char reg, char value);
	char TWIM_ReadRegister(char reg);
	i8 MPU6050_ReadAccel(int axis);
	double MPU6050_ReadGyro(int axis);
	void pushup_Control();
	void timer_init();
	void setRepetitions();
	u32 getRepetitions();
	void controlDownFalse();
	void controlUpFalse();
protected:
private:
	

}; //MPU_6050

#endif //__MPU_6050_H__
