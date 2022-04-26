#ifndef INT_DEF_H_
#define INT_DEF_H_

/*
	Definicia zakladnych celociselnych typov
	
	u32 - neznamienkovy 32bitovy celociselny typ
	i32 - znamienkovy 32bitovy celociselny typ
	u16 - neznamienkovy 16bitovy celociselny typ
	i16 - znamienkovy 16bitovy celociselny typ
	u8 - neznamienkovy 8bitovy celociselny typ
	i8 - znamienkovy 8bitovy celociselny typ
*/

#ifndef u32
#define u32 unsigned long int
#endif

#ifndef u16
#define u16 unsigned int
#endif

#ifndef u8
#define u8  unsigned char
#endif

#ifndef i32
#define i32 signed long int
#endif

#ifndef i16
#define i16 signed int
#endif

#ifndef i8
#define i8  signed char
#endif

#endif /* INT_DEF_H_ */