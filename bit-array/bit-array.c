/*
	diy-VT100 firmware
	==================

	Source code of diy-VT100 firmware.
	Run on STM32F767VxTx.

	URL: https://www.madresistor.com/diy-vt100
	Hardware design: https://gitlab.com/madresistor/diy-vt100-hardware

	If you are looking for the last tested design,
	checkout tag "manuf-27-march-2017" from firmware repo and hardware design repo.

	Dependencies
	============
*/

#include "bit-array.h"

//inline uint8_t mask(unsigned index) { return 1 << ( 0x7 & index ); }
//inline unsigned offset(unsigned index) { return index >> 3; }

/* TODO: Use ARM bitband region */

void bitarr_write( uint8_t *data, uint16_t index, bool value )
{
	uint16_t o = offset( index );
	uint8_t m = mask( index );

	if( value )
	{
		data[o] |= m;
	} else {
		data[o] &= ~m;
	}
}

bool bitarr_read( const uint8_t *data, uint16_t index )
{
	return !!( data[ offset( index ) ] & mask( index ) );
}

void bitarr_flip( uint8_t *data, uint16_t index )
{
	data[ offset( index ) ] ^= mask( index );
}

void bitarr_high( uint8_t *data, uint16_t index )
{
	data[ offset( index ) ] |= mask( index );
}

void bitarr_low( uint8_t *data, uint16_t index )
{
	data[ offset( index ) ] &= ~mask( index );
}
