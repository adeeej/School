#include "TWI.h"
#include "Uart.h"

// default constructor
TWI::TWI()
{
} //TWI

// default destructor
TWI::~TWI()
{
} //~TWI

uint8_t TWI::TWIM_Init (uint32_t TWI_Bitrate)
{
	/*
	** Set TWI bitrate
	** If bitrate is too high, then error return
	*/
	TWBR = ((F_CPU/TWI_Bitrate)-16)/2;
	//TWBR = 0x34;
	if (TWBR < 11) return FALSE;
	return TRUE;
}

uint8_t TWI::TWIM_Start (uint8_t Address, uint8_t TWIM_Type)//1 = read, 0 = write
{
	uint8_t        twst;
	/*
	** Send START condition
	*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/*
	** Wait until transmission completed
	*/
	while (!(TWCR &(1<<TWINT)));
	/*
	** Check value of TWI Status Register. Mask prescaler bits.
	*/
	twst = TWSR & 0xF8;
	if ((twst != TWI_START) && (twst != TWI_REP_START)) return FALSE;
	/*
	** Send device address
	*/
	TWDR = (Address<<1) + TWIM_Type;
	TWCR = (1<<TWINT)|(1<<TWEN);
	/*
	** Wait until transmission completed and ACK/NACK has been received
	*/
	while (!(TWCR &(1<<TWINT)));
	/*
	** Check value of TWI Status Register. Mask prescaler bits.
	*/
	twst = TWSR & 0xF8;
	if ((twst != TWI_MTX_ADR_ACK) && (twst != TWI_MRX_ADR_ACK)) return FALSE;

	return TRUE;
}

void TWI::TWIM_Stop (void)
{
	/*
	** Send stop condition
	*/
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	/*
	** Wait until stop condition is executed and bus released
	*/
	while (TWCR & (1<<TWINT));
}

uint8_t TWI::TWIM_Write (uint8_t byte)
{
	uint8_t   twst;
	/*
	** Send data to the previously addressed device
	*/
	TWDR = byte;
	TWCR = (1<<TWINT) |
	(1<<TWEN);
	/*
	** Wait until transmission completed
	*/
	while (!(TWCR & (1<<TWINT)));
	/*
	** Check value of TWI Status Register. Mask prescaler bits
	*/
	twst = TWSR & 0xF8;
	if (twst != TWI_MTX_DATA_ACK) return 1;

	return 0;
}

uint8_t TWI::TWIM_ReadAck (void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));

	return TWDR;
}

uint8_t TWI::TWIM_ReadNack (void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}