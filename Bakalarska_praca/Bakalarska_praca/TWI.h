#ifndef __TWI_H__
#define __TWI_H__

#define F_CPU 12000000UL

#define TRUE 1
#define FALSE 0

#include <avr/interrupt.h>

/****************************************************************************
  TWI State codes
****************************************************************************/
// General TWI Master status codes                      
#define TWI_START                    0x08	// START has been transmitted  
#define TWI_REP_START                0x10	// Repeated START has been transmitted
#define TWI_ARB_LOST                 0x38	// Arbitration lost

// TWI Master Transmitter status codes                      
#define TWI_MTX_ADR_ACK              0x18	// SLA+W has been transmitted and ACK received
#define TWI_MTX_ADR_NACK             0x20	// SLA+W has been transmitted and NACK received 
#define TWI_MTX_DATA_ACK             0x28	// Data byte has been transmitted and ACK received
#define TWI_MTX_DATA_NACK            0x30	// Data byte has been transmitted and NACK received 

// TWI Master Receiver status codes  
#define TWI_MRX_ADR_ACK				 0x40	// SLA+R has been transmitted and ACK received
#define TWI_MRX_ADR_NACK			 0x48	// SLA+R has been transmitted and NACK received
#define TWI_MRX_DATA_ACK			 0x50	// Data byte has been received and ACK transmitted
#define TWI_MRX_DATA_NACK            0x58	// Data byte has been received and NACK transmitted

// TWI Slave Transmitter status codes
#define TWI_STX_ADR_ACK              0xA8	// Own SLA+R has been received; ACK has been returned
#define TWI_STX_ADR_ACK_M_ARB_LOST   0xB0	// Arbitration lost in SLA+R/W as Master; own SLA+R has been received; ACK has been returned
#define TWI_STX_DATA_ACK             0xB8	// Data byte in TWDR has been transmitted; ACK has been received
#define TWI_STX_DATA_NACK            0xC0	// Data byte in TWDR has been transmitted; NOT ACK has been received
#define TWI_STX_DATA_ACK_LAST_BYTE   0xC8   // Last data byte in TWDR has been transmitted (TWEA = ?0?); ACK has been received

// TWI Slave Receiver status codes
#define TWI_SRX_ADR_ACK              0x60	// Own SLA+W has been received ACK has been returned
#define TWI_SRX_ADR_ACK_M_ARB_LOST   0x68   // Arbitration lost in SLA+R/W as Master; own SLA+W has been received; ACK has been returned
#define TWI_SRX_GEN_ACK              0x70   // General call address has been received; ACK has been returned
#define TWI_SRX_GEN_ACK_M_ARB_LOST   0x78   // Arbitration lost in SLA+R/W as Master; General call address has been received; ACK has been returned
#define TWI_SRX_ADR_DATA_ACK         0x80   // Previously addressed with own SLA+W; data has been received; ACK has been returned
#define TWI_SRX_ADR_DATA_NACK        0x88   // Previously addressed with own SLA+W; data has been received; NOT ACK has been returned
#define TWI_SRX_GEN_DATA_ACK         0x90   // Previously addressed with general call; data has been received; ACK has been returned
#define TWI_SRX_GEN_DATA_NACK        0x98   // Previously addressed with general call; data has been received; NOT ACK has been returned
#define TWI_SRX_STOP_RESTART         0xA0   // A STOP condition or repeated START condition has been received while still addressed as Slave

// TWI Miscellaneous status codes
#define TWI_NO_STATE                 0xF8   // No relevant state information available; TWINT = ?0?
#define TWI_BUS_ERROR                0x00   // Bus error due to an illegal START or STOP condition

#define TWIM_READ    1
#define TWIM_WRITE   0

class TWI
{
//variables
public:
protected:
private:

//functions
public:
	TWI();
	~TWI();
	uint8_t TWIM_Init (uint32_t TWI_Bitrate);
	uint8_t TWIM_Start (uint8_t Address, uint8_t TWIM_Type);
	void TWIM_Stop (void);
	uint8_t TWIM_Write (uint8_t byte);
	uint8_t TWIM_ReadAck (void);
	uint8_t TWIM_ReadNack (void);
protected:
private:

}; //TWI

#endif //__TWI_H__
